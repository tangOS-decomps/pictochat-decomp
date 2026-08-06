"""Work a worklist with an LLM over an API key, compiling and byte-checking every attempt.

This is the driver tangOS Console runs for a keyed agent. It reads the worklist Console's
scheduler produced, and for each target: shows the model the ROM's disassembly and target
bytes, asks for C, compiles it, and compares against the ROM. A miss comes back with the
actual instruction diff so the next attempt is informed rather than a re-roll.

Nothing here banks anything. It writes a results file; tools/land.py re-verifies every claim
independently and decides what reaches src/. A driver that lies (or is simply wrong about a
size) must not be able to land a file, so the byte gate runs twice on purpose.

Configuration comes from the environment, matching what Console sets for an agent:
    GLM_API_KEY    the key
    GLM_BASE_URL   API root, e.g. https://api.anthropic.com
    GLM_MODEL      model id
    GLM_DIALECT    "openai" for /chat/completions; default is the Anthropic messages API

Usage:
    python tools/drive.py --wl worklist.jsonl --out results.json --jobs 1 --attempts 4
"""
import argparse
import json
import os
import pathlib
import re
import subprocess
import sys
import urllib.error
import urllib.request
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

REPO = pathlib.Path(__file__).resolve().parent.parent
_print_lock = threading.Lock()


def log(msg):
    with _print_lock:
        print(msg, flush=True)


SYSTEM = (
    "You are decompiling a Nintendo DSi ARM binary into C that a period CodeWarrior compiler "
    "(mwccarm) rebuilds BYTE FOR BYTE. Byte-exact is the only success. Reply with one fenced C "
    "code block and nothing else: no prose, no explanation. Write plain C99 unless the symbol is "
    "C++-mangled, in which case make the FIRST LINE exactly //cpp. Do not invent helper functions "
    "or headers that do not exist; keep it to what the disassembly shows."
)


def disasm(module, addr, size, thumb):
    """Ask the repo's own disassembler for this function, so the model sees real instructions."""
    cmd = [
        sys.executable, str(REPO / "tools" / "disasm.py"),
        "--module", module, "--addr", addr, "--length", hex(size),
    ]
    if thumb:
        cmd.append("--thumb")
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
        return (r.stdout or "").strip()
    except Exception:
        return ""


def fdiff(c_path, name, row):
    """Instruction-level diff of a failed candidate, fed back as the next attempt's context."""
    cmd = [
        sys.executable, str(REPO / "tools" / "fdiff.py"),
        "--c", str(c_path), "--func", name,
        "--module", row["module"], "--addr", str(row["addr"]), "--size", str(row["size"]),
        "--compact",
    ]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=300)
        return ((r.stdout or "") + (r.stderr or "")).strip()[:4000]
    except Exception:
        return ""


DIFF_RE = re.compile(r"closest:\s+\S+\s+\((\d+)\s+differ\)")


def verify(c_path, name, row):
    """(matched, divergence). Divergence is the closest build's differing-word count, which is
    what the console's live viewer reports per target; 999 is match.py's sentinel for a candidate
    that did not compile or came out the wrong size."""
    cmd = [
        sys.executable, str(REPO / "tools" / "match.py"),
        "--c", str(c_path), "--func", name,
        "--addr", str(row["addr"]), "--size", str(row["size"]), "--module", row["module"],
        "--brief",
    ]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
    except subprocess.TimeoutExpired:
        return False, 999
    text = (r.stdout or "") + (r.stderr or "")
    if "MATCHING VERSIONS: none" not in text and ": MATCH" in text:
        return True, 0
    m = DIFF_RE.search(text)
    return False, int(m.group(1)) if m else 999


def call_model(messages, cfg):
    """One API round-trip. Returns (text, tokens_in, tokens_out)."""
    if cfg["dialect"] == "openai":
        url = cfg["base"].rstrip("/") + "/v1/chat/completions"
        body = {
            "model": cfg["model"],
            "messages": [{"role": "system", "content": SYSTEM}] + messages,
            "max_tokens": 4096,
        }
        headers = {"Authorization": f"Bearer {cfg['key']}", "Content-Type": "application/json"}
    else:
        url = cfg["base"].rstrip("/") + "/v1/messages"
        body = {
            "model": cfg["model"],
            "system": SYSTEM,
            "messages": messages,
            "max_tokens": 4096,
        }
        headers = {
            "x-api-key": cfg["key"],
            "anthropic-version": "2023-06-01",
            "Content-Type": "application/json",
        }
    req = urllib.request.Request(url, data=json.dumps(body).encode("utf-8"), headers=headers)
    with urllib.request.urlopen(req, timeout=cfg["timeout"]) as resp:
        data = json.loads(resp.read().decode("utf-8"))

    if cfg["dialect"] == "openai":
        text = (data.get("choices") or [{}])[0].get("message", {}).get("content") or ""
        usage = data.get("usage") or {}
        return text, usage.get("prompt_tokens", 0), usage.get("completion_tokens", 0)
    parts = data.get("content") or []
    text = "".join(p.get("text", "") for p in parts if p.get("type") == "text")
    usage = data.get("usage") or {}
    return text, usage.get("input_tokens", 0), usage.get("output_tokens", 0)


CODE_RE = re.compile(r"```(?:c\+\+|cpp|c)?\s*\n(.*?)```", re.S)


def extract_code(text):
    m = CODE_RE.search(text or "")
    return (m.group(1) if m else (text or "")).strip()


def work_one(row, cfg, attempts, live=False):
    name = row["name"]
    size = int(str(row["size"]), 0)
    att_log = []  # per-attempt lines, printed by the caller BELOW the result header

    def note_attempt(msg):
        att_log.append(msg)
        if live:
            log(f"    {name} {msg}")

    if live:  # immediate feedback: which function is being worked, before the slow model call
        log(f"-> {name}: writing from scratch with {cfg['model']} (up to {attempts} attempts)...")
    listing = disasm(row["module"], str(row["addr"]), size, (row.get("mode") == "thumb"))
    prompt = [
        f"Function: {name}",
        f"Module: {row['module']}   Address: {row['addr']}   Size: {row['size']}",
    ]
    if row.get("target_hex"):
        prompt.append(f"Target bytes: {row['target_hex']}")
    if listing:
        prompt.append("\nDisassembly:\n" + listing)
    prompt.append("\nWrite the C that rebuilds this function byte for byte.")
    messages = [{"role": "user", "content": "\n".join(prompt)}]

    tin = tout = 0
    best = None
    best_div = 999
    for attempt in range(1, attempts + 1):
        try:
            text, a, b = call_model(messages, cfg)
        except urllib.error.HTTPError as e:
            detail = e.read().decode("utf-8", "replace")[:300]
            return {"name": name, "matched": False, "divergences": 999, "attempts": attempt,
                    "c_source": None, "note": f"HTTP {e.code}: {detail}", "log": att_log,
                    "orig_div": None}, tin, tout
        except Exception as e:
            return {"name": name, "matched": False, "divergences": 999, "attempts": attempt,
                    "c_source": None, "note": f"{type(e).__name__}: {e}", "log": att_log,
                    "orig_div": None}, tin, tout
        tin += a
        tout += b
        code = extract_code(text)
        if not code:
            continue
        ext = "cpp" if code.lstrip().startswith("//cpp") else "c"
        tmp = REPO / "extracted" / f"_drive_{name}_{attempt}.{ext}"
        tmp.parent.mkdir(parents=True, exist_ok=True)
        tmp.write_text(code, encoding="utf-8")
        try:
            ok, div = verify(tmp, name, row)
            if not ok:
                note_attempt(f"attempt {attempt}: div={div}")
            if ok:
                note_attempt(f"attempt {attempt}: MATCH")
                return {"name": name, "matched": True, "divergences": 0, "attempts": attempt,
                        "c_source": code, "note": "", "log": att_log, "orig_div": None}, tin, tout
            # Keep the CLOSEST attempt, not the last one - a later try can be worse, and the
            # closest draft is what a refine pass wants to start from.
            if div < best_div:
                best_div, best = div, code
            if attempt < attempts:
                diff = fdiff(tmp, name, row)
                messages += [
                    {"role": "assistant", "content": text},
                    {
                        "role": "user",
                        "content": "Not byte-exact. Here is how your candidate differs from the ROM:\n\n"
                        + (diff or "(no diff available)")
                        + "\n\nRewrite the C to close the gap. One fenced code block, nothing else.",
                    },
                ]
        finally:
            tmp.unlink(missing_ok=True)
    return {"name": name, "matched": False, "divergences": best_div, "attempts": attempts,
            "c_source": best, "note": "", "log": att_log, "orig_div": None}, tin, tout


def _write_output(path, results, tin, tout, model):
    """Same shape glm_refine writes, because Console parses this file: landedNames drives what
    counts as landed, nearMisses is what gets parked, and the token fields feed the agent stats."""
    landed = [r for r in results if r["matched"]]
    out = {
        "model": model,
        "attempted": len(results),
        "landed": len(landed),
        "landedNames": [r["name"] for r in landed],
        "outputTokens": tout,
        "inputTokens": tin,
        "tokensPerLanded": round(tout / len(landed)) if landed else None,
        "results": [{"name": r["name"], "matched": r["matched"], "attempts": r["attempts"],
                     "divergences": r["divergences"], "note": r["note"]} for r in results],
        "sources": {r["name"]: r["c_source"] for r in landed if r["c_source"]},
        # Only COMPILING drafts are worth banking. divergences==999 is the verifier's "no
        # divergence count" sentinel: the draft did not compile, so its c_source is not a usable
        # near-miss - banking it would just add non-reproducing noise. A draft that compiled
        # (div < 999), even a loose one, is real progress from nothing and is saved.
        "nearMisses": [{"name": r["name"], "c_source": r["c_source"]}
                       for r in results
                       if not r["matched"] and r["c_source"] and r["divergences"] < 999],
    }
    pathlib.Path(path).write_text(json.dumps(out, indent=1), encoding="utf-8")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--wl", required=True, help="worklist JSONL to work through")
    ap.add_argument("--out", required=True, help="where to write the results JSON")
    ap.add_argument("--jobs", type=int, default=1, help="targets in flight at once")
    ap.add_argument("--attempts", type=int, default=4, help="tries per function before moving on")
    ap.add_argument("--timeout", type=int, default=300, help="per-request timeout, seconds")
    args = ap.parse_args()

    cfg = {
        "key": os.environ.get("GLM_API_KEY", ""),
        "base": os.environ.get("GLM_BASE_URL", "https://api.anthropic.com"),
        "model": os.environ.get("GLM_MODEL", "claude-sonnet-5"),
        "dialect": os.environ.get("GLM_DIALECT", "anthropic"),
        "timeout": args.timeout,
    }
    if not cfg["key"]:
        sys.exit("no GLM_API_KEY in the environment - add the key in Console's vault")

    rows = []
    for line in pathlib.Path(args.wl).read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if line:
            rows.append(json.loads(line))
    if not rows:
        sys.exit(f"{args.wl} is empty - nothing to drive")

    t0 = time.time()
    results, tin, tout = [], 0, 0
    live = args.jobs <= 1  # sequential runs stream each attempt; parallel ones would interleave
    with ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        futs = [pool.submit(work_one, r, cfg, args.attempts, live) for r in rows]
        # as_completed, not map: map yields in submission order, so one slow target holds back every
        # result behind it and the viewer's bar sits at zero while work is actually finishing.
        for f in as_completed(futs):
            res, i_tok, o_tok = f.result()
            tin += i_tok
            tout += o_tok
            results.append(res)
            # Result-first block: header (index, name, final div) then this function's attempts
            # indented below, so each function reads as one tidy unit and a new header means the
            # previous one finished. The header shape is what the console's live viewer parses -
            # anything else and the analyzed bar never climbs.
            status = "MATCH" if res["matched"] else "div=" + str(res["divergences"])
            orig = res.get("orig_div")
            if isinstance(orig, int) and orig > 0:
                status += f" (from: {orig})"
            lines = [f"({len(results)}/{len(rows)}) {res['name']}: {status}"]
            if not live:  # sequential runs already streamed these attempts live
                lines += [f"    {ln}" for ln in res.get("log", [])]
            log("\n".join(lines))

    _write_output(args.out, results, tin, tout, cfg["model"])
    landed = [r for r in results if r["matched"]]
    mins = (time.time() - t0) / 60
    print(f"\n{cfg['model']}: landed {len(landed)}/{len(results)} in {mins:.0f}m; "
          f"in={tin} out={tout} tok"
          + (f" ({round(tout / len(landed))} out/landed)" if landed else ""))
    print(f"land with: python tools/land.py --output {args.out} --wl {args.wl}")


if __name__ == "__main__":
    main()
