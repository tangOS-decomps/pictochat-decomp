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
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

REPO = pathlib.Path(__file__).resolve().parent.parent
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


def verify(c_path, name, row):
    cmd = [
        sys.executable, str(REPO / "tools" / "match.py"),
        "--c", str(c_path), "--func", name,
        "--addr", str(row["addr"]), "--size", str(row["size"]), "--module", row["module"],
        "--brief",
    ]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
    except subprocess.TimeoutExpired:
        return False
    text = (r.stdout or "") + (r.stderr or "")
    return "MATCHING VERSIONS: none" not in text and ": MATCH" in text


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


def work_one(row, cfg, attempts):
    name = row["name"]
    size = int(str(row["size"]), 0)
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
    for attempt in range(1, attempts + 1):
        try:
            text, a, b = call_model(messages, cfg)
        except urllib.error.HTTPError as e:
            detail = e.read().decode("utf-8", "replace")[:300]
            return {"name": name, "matched": False, "error": f"HTTP {e.code}: {detail}"}, tin, tout
        except Exception as e:
            return {"name": name, "matched": False, "error": f"{type(e).__name__}: {e}"}, tin, tout
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
            if verify(tmp, name, row):
                return {"name": name, "matched": True, "c_source": code, "attempts": attempt}, tin, tout
            best = code
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
    return {"name": name, "matched": False, "c_source": best, "attempts": attempts}, tin, tout


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

    results, tin, tout = [], 0, 0
    with ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        for res, a, b in pool.map(lambda r: work_one(r, cfg, args.attempts), rows):
            results.append(res)
            tin += a
            tout += b
            mark = "MATCH" if res.get("matched") else (res.get("error") or "no match")
            print(f"{res['name']}: {mark}", flush=True)

    out = {
        "results": results,
        "landed": [r["name"] for r in results if r.get("matched")],
        # Compiling-but-not-matching drafts. Kept so land.py can park them: a close attempt is
        # the best starting point for the next one, and dropping it loses real work.
        "nearMisses": [
            {"name": r["name"], "c_source": r["c_source"]}
            for r in results
            if not r.get("matched") and r.get("c_source")
        ],
        "tokensIn": tin,
        "tokensOut": tout,
    }
    pathlib.Path(args.out).write_text(json.dumps(out, indent=1), encoding="utf-8")
    landed = len(out["landed"])
    print(f"\n{landed}/{len(results)} matched   tokens in={tin} out={tout}   -> {args.out}")


if __name__ == "__main__":
    main()
