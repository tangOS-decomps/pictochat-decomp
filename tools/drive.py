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


class AuthFailed(RuntimeError):
    """The API rejected the key. Aborts the whole run rather than repeating per function."""

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import pr_linkcheck as _linkcheck  # noqa: E402   the repo's own verification gate

REPO = pathlib.Path(__file__).resolve().parent.parent
# Built once: symbol name -> [(addr, size, module)], the sanity index pr_linkcheck checks a
# header's name against before doing any work.
_SYMBOL_IDX = _linkcheck.build_symbol_index()
_print_lock = threading.Lock()


def log(msg):
    with _print_lock:
        print(msg, flush=True)


SYSTEM = (
    "You are decompiling a Nintendo DSi ARM binary into C that a period CodeWarrior compiler "
    "(mwccarm) rebuilds BYTE FOR BYTE. Byte-exact is the only success. Reply with one fenced C "
    "code block and nothing else: no prose, no explanation. Write plain C99 unless the symbol is "
    "C++-mangled, in which case make the FIRST LINE exactly //cpp. Do not invent helper functions "
    "or headers that do not exist; keep it to what the disassembly shows.\n\n"
    "You are NOT the compiler - do not reason your way to certainty about which instruction your "
    "C will become. This is guess-and-check: write your single best candidate and submit it. One "
    "guess actually compiled beats ten argued in your head. END EVERY REPLY WITH A CODE BLOCK; "
    "never spend a turn on speculation alone. And never write inline asm - it is not a valid "
    "match and will not compile with these flags."
)


def _lever_block(mode):
    """Structural levers for this function's ISA, from the shared catalogue.

    The catalogue lives in sm64ds-decomp (the mature one) and is read across a sibling checkout,
    so a lever proven in either project reaches both instead of living in one repo's notes.
    Selected by ISA on purpose: most of it was derived on an all-ARM title, so the ARM-only
    entries are dropped for a Thumb target and the rest arrive marked unproven rather than
    presented as fact. Absent sibling checkout -> no block, and the driver still runs."""
    sib = pathlib.Path(os.environ.get("LEVERS_REPO") or (REPO.parent / "sm64ds-decomp"))
    script = sib / "tools" / "levers.py"
    if not script.is_file():
        return ""
    try:
        p = subprocess.run(
            [sys.executable, str(script), "--repo", str(sib),
             "--arch", "thumb" if mode == "thumb" else "arm", "--format", "prompt"],
            capture_output=True, text=True, timeout=30,
        )
    except (OSError, subprocess.SubprocessError):
        return ""
    return (p.stdout or "").strip() if p.returncode == 0 else ""


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


NDIFF_RE = re.compile(r"(\d+) word\(s\) differ")


def verify(c_path, name, row):
    """(matched, divergence), decided by THIS repo's own gate - tools/pr_linkcheck.py.

    Not a hand-rolled match.py call with a size we guessed. This project does not verify the way
    sm64ds does, and the differences all matter:

      * The comparison span comes from the COMPILED OBJECT, not from a size argument. Ghidra's
        boundary table is explicitly "not the size source of truth" here, and neither is a
        pool-extended guess - passing either produced a size mismatch and a 999 on functions that
        actually reproduce perfectly.
      * It sweeps every pinned mwccarm version AND both Thumb/ARM flag variants, because this
        title's canonical version is still a guess; pinning one under-checks.
      * The header name is often descriptive rather than the real link symbol (every C++ method
        here), so it tries each symbol the object emits.
      * `// NONMATCHING:` files are PARKED by declaration, not failures.

    pr_linkcheck reads the target's address and module from the file's own `// decomp:` header,
    so the candidate has to carry one - drive.py writes it.
    """
    try:
        rel = str(pathlib.Path(c_path).resolve().relative_to(REPO))
    except ValueError:
        rel = str(c_path)
    try:
        rep = _linkcheck.check_file(rel, _SYMBOL_IDX)
    except Exception as e:
        return False, 999, f"{type(e).__name__}: {e}"
    verdict = rep.get("verdict")
    if verdict == "VERIFIED":
        return True, 0, ""
    detail = rep.get("detail") or verdict
    m = NDIFF_RE.search(detail or "")
    # 999 stays the "no usable divergence count" sentinel (didn't compile, unresolved), which is
    # what tells land.py a draft is not worth parking.
    return False, int(m.group(1)) if m else 999, detail


# Hard ceiling for the truncation escalation in run_one. A reply cut off mid-reasoning is retried
# with double the budget, and this is where that stops - high enough for a reasoner that genuinely
# needs to think (deepseek-reasoner tops out at 64k output), low enough that a model stuck in a
# thinking loop cannot bill indefinitely.
MAX_OUTPUT_TOKENS = int(os.environ.get("GLM_MAX_OUTPUT_TOKENS_CAP", "64000"))
# How many times one function may double its ceiling. Bounds the worst case for a model that
# truncates no matter how much room it gets: 24000 -> 48000 -> 64000, then give up on it.
MAX_ESCALATIONS = 2


def _is_reasoner(cfg):
    m = (cfg.get("model") or "").lower()
    return bool("reason" in m or "nemo" in m or re.match(r"^(gpt-5|o[1-4])", m))


def _max_tokens_for(cfg, override=None):
    """Output ceiling. A reasoning model spends its hidden thinking INSIDE this limit, so the flat
    4096 that used to be hardcoded here starves it: the reasoning consumes the whole budget and the
    reply is cut off before the code block ever starts, which then reads as "no code block
    returned". sm64ds's driver learned this the expensive way (130k output tokens, 0 landed) and
    gives known reasoners real headroom - they only bill what they use.

    `override` is the escalated budget run_one carries after a truncation; the env var sets only the
    STARTING ceiling, so raising it by hand is no longer the only way out of a cut-off."""
    if override:
        return int(override)
    return int(os.environ.get("GLM_MAX_OUTPUT_TOKENS", "24000" if _is_reasoner(cfg) else "8000"))


def call_model(messages, cfg, max_tokens=None):
    """One API round-trip. Returns (text, tokens_in, tokens_out).

    Raises AuthFailed on 401/403 and Throttled on 429/5xx so the caller can react differently to
    "your key is wrong" (stop) and "slow down" (retry) instead of scoring both as a failed match.

    `max_tokens` overrides the ceiling for this call, so a caller retrying a truncated reply can
    give it more room rather than re-buying the same cut-off.
    """
    mt = _max_tokens_for(cfg, max_tokens)
    system = SYSTEM
    # Nemotron reasons so heavily it burns the whole budget before emitting the code block. Its
    # NVIDIA system toggle "detailed thinking off" roughly halves the thinking, so it actually
    # submits a candidate and uses the compile-check loop instead of truncating. Same trick
    # sm64ds's driver uses; without it the first attempt on a big function is usually wasted.
    if "nemo" in (cfg.get("model") or "").lower():
        system = "detailed thinking off\n\n" + SYSTEM
    if cfg["dialect"] == "openai":
        url = cfg["base"].rstrip("/") + "/v1/chat/completions"
        body = {
            "model": cfg["model"],
            "messages": [{"role": "system", "content": system}] + messages,
            "max_tokens": mt,
        }
        headers = {"Authorization": f"Bearer {cfg['key']}", "Content-Type": "application/json"}
    else:
        url = cfg["base"].rstrip("/") + "/v1/messages"
        body = {
            "model": cfg["model"],
            "system": system,
            "messages": messages,
            "max_tokens": mt,
        }
        headers = {
            "x-api-key": cfg["key"],
            "anthropic-version": "2023-06-01",
            "Content-Type": "application/json",
        }
    req = urllib.request.Request(url, data=json.dumps(body).encode("utf-8"), headers=headers)
    with urllib.request.urlopen(req, timeout=cfg["timeout"]) as resp:
        data = json.loads(resp.read().decode("utf-8"))

    # finish_reason / stop_reason travels with the text. An empty reply that stopped on "length"
    # was CUT OFF, not silent, and the two need opposite responses - nagging a truncated model for
    # a code block at the same ceiling just buys the same truncation.
    if cfg["dialect"] == "openai":
        ch = (data.get("choices") or [{}])[0]
        text = ch.get("message", {}).get("content") or ""
        usage = data.get("usage") or {}
        return (text, usage.get("prompt_tokens", 0), usage.get("completion_tokens", 0),
                ch.get("finish_reason"))
    parts = data.get("content") or []
    text = "".join(p.get("text", "") for p in parts if p.get("type") == "text")
    usage = data.get("usage") or {}
    return (text, usage.get("input_tokens", 0), usage.get("output_tokens", 0),
            data.get("stop_reason"))


CODE_RE = re.compile(r"```(?:c\+\+|cpp|c)?\s*\n(.*?)```", re.S)


def extract_code(text):
    m = CODE_RE.search(text or "")
    return (m.group(1) if m else (text or "")).strip()


def with_header(code, name, row):
    """Give a candidate the `// decomp:` header this repo identifies files by.

    pr_linkcheck resolves a file's target from that header, not from arguments, so a candidate
    without one is UNRESOLVED however good the C is. Note there is deliberately no size in it:
    the span comes from what the compiler emits.

    //cpp has to stay the literal first line - that is how the build picks C++ - so the header
    goes after it rather than above.
    """
    if "// decomp:" in code:
        return code
    hdr = f"// decomp: module={row['module']} addr={row['addr']} name={name}"
    lines = code.split("\n")
    at = 1 if lines and lines[0].strip().startswith("//cpp") else 0
    lines.insert(at, hdr)
    return "\n".join(lines)


def apply_mode_marker(code, mode):
    """Kept only for the ARM/Thumb hint in the prompt path; pr_linkcheck's resolve_flags already
    tries both variants, so this is no longer load-bearing."""
    if mode != "arm" or "// flags:" in code:
        return code
    lines = code.split("\n")
    at = 1 if lines and lines[0].strip().startswith("//cpp") else 0
    lines.insert(at, "// flags: -noThumb")
    return "\n".join(lines)


def work_one(row, cfg, attempts, live=False):
    name = row["name"]
    size = int(str(row["size"]), 0)
    att_log = []  # per-attempt lines, printed by the caller BELOW the result header

    def note_attempt(msg):
        att_log.append(msg)
        if live:
            log(f"    {name} {msg}")

    draft = row.get("draft")
    if live:  # immediate feedback: which function is being worked, before the slow model call
        if draft:
            d = row.get("divergences")
            log(f"-> {name}: refining a parked draft"
                + (f" (currently {d} word(s) off)" if d is not None else "")
                + f" with {cfg['model']} (up to {attempts} attempts)...")
        else:
            log(f"-> {name}: writing from scratch with {cfg['model']} (up to {attempts} attempts)...")
    mode = row.get("mode")
    listing = disasm(row["module"], str(row["addr"]), size, (mode == "thumb"))
    # Tell it what it is compiling for. None of this was in the prompt before: the model was
    # asked to hit a byte-exact target without being told the compiler build, the flags, or
    # even whether it was writing ARM or Thumb - on a title that is ~70% Thumb.
    try:
        import match as _m
        version = _m.CANONICAL
        flags = _m.DEFAULT_FLAGS_ARM7 if row["module"] == "arm7" else _m.DEFAULT_FLAGS
    except Exception:
        version, flags = "2.0/sp1", ""
    prompt = [
        f"Function: {name}",
        f"Module: {row['module']}   Address: {row['addr']}   Size: {row['size']}"
        + (f"   ISA: {mode.upper()}" if mode else ""),
        f"Compiler: mwccarm {version}" + (f"\nFlags: {flags}" if flags else ""),
    ]
    if row.get("target_hex"):
        prompt.append(f"Target bytes: {row['target_hex']}")
    if listing:
        prompt.append("\nDisassembly:\n" + listing)
    # Worked examples from the scheduler's --similar mode: already-matched functions whose
    # opcode sequence resembles this one, plus the C that actually reproduced them. A sibling
    # near 1.0 usually means the same shape with different operands, which is worth far more to
    # the model than the disassembly alone. Absent (plain smallest-first worklist) this is a
    # no-op, so the driver reads either kind of worklist.
    sims = {s.get("name"): s.get("sim") for s in (row.get("siblings") or [])}
    for ex in row.get("examples") or []:
        if not ex.get("c_source"):
            continue
        sim = sims.get(ex.get("name"))
        header = f"\nAlready-matched function with a similar shape ({ex.get('name')}"
        header += f", opcode similarity {sim}):\n" if sim is not None else "):\n"
        prompt.append(header + ex["c_source"])
    levers = _lever_block(mode)
    if levers:
        prompt.append("\n" + levers)
    if draft:
        d = row.get("divergences")
        prompt.append(
            "\nA previous attempt got this close and is PARKED as a near-miss"
            + (f" - {d} word(s) still differ from the ROM" if d is not None else "")
            + ". Start from it and fix the remaining codegen SHAPE; do not rewrite it from "
              "scratch, and do not change semantics unless the diff proves them wrong:\n" + draft
        )
        prompt.append("\nReturn the improved complete source file.")
    else:
        prompt.append("\nWrite the C that rebuilds this function byte for byte.")
    messages = [{"role": "user", "content": "\n".join(prompt)}]

    tin = tout = 0
    best = None
    best_div = 999
    last_detail = ""
    budget = None   # raised ceiling carried forward after a truncation (None = the model default)
    escalations = 0 # how many times the ceiling has been doubled for this function
    attempt = 0
    while attempt < attempts:
        attempt += 1
        try:
            text, a, b, finish = call_model(messages, cfg, budget)
        except urllib.error.HTTPError as e:
            detail = e.read().decode("utf-8", "replace")[:300]
            # A rejected key is not a property of this function, so reporting it as div=999 and
            # moving to the next target is wrong twice: it buries the real cause behind a number
            # that means "the C did not match", and it re-asks a question already answered for
            # every remaining function. A 401/403 will not fix itself between calls. Raise so the
            # run stops and SAYS what happened.
            if e.code in (401, 403):
                raise AuthFailed(f"HTTP {e.code}: {detail}")
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
            # This used to be a bare `continue` - an empty reply burned an attempt with no log line
            # at all. Two very different causes need saying apart: a reply cut off at the token
            # ceiling (the reasoner spent its whole budget thinking) versus a model that genuinely
            # returned nothing.
            #
            # A cut-off used to end the function outright, telling the operator to go raise
            # GLM_MAX_OUTPUT_TOKENS by hand. That threw the whole target away over a number the
            # driver could just as well raise itself, and on a batch of big functions it threw most
            # of them away: retrying at the SAME ceiling truncates identically, so "stop" looked
            # like the only alternative. Double the ceiling and resend the SAME prompt instead -
            # the model only bills what it uses, and a truncation now costs one extra call rather
            # than the function. The retry does NOT consume an attempt, because nothing about the
            # candidate was tested; only a real compile-and-verify should.
            if finish in ("length", "max_tokens"):
                used = _max_tokens_for(cfg, budget)
                nxt = min(used * 2, MAX_OUTPUT_TOKENS)
                if nxt > used and escalations < MAX_ESCALATIONS:
                    budget = nxt
                    escalations += 1
                    attempt -= 1  # this call tested nothing - don't spend an attempt on it
                    note_attempt(f"attempt {attempt + 1}: cut off at the {used}-token ceiling "
                                 f"before writing any code - retrying at {nxt}")
                    continue
                note_attempt(f"attempt {attempt}: cut off at the {used}-token ceiling before "
                             f"writing any code - already at the {MAX_OUTPUT_TOKENS} cap")
                break
            note_attempt(f"attempt {attempt}: no code block returned")
            continue
        code = with_header(code, name, row)
        ext = "cpp" if code.lstrip().startswith("//cpp") else "c"
        tmp = REPO / "extracted" / "_drive" / f"{name}_{attempt}.{ext}"
        tmp.parent.mkdir(parents=True, exist_ok=True)
        tmp.write_text(code, encoding="utf-8")
        try:
            ok, div, detail = verify(tmp, name, row)
            if not ok:
                last_detail = detail
                note_attempt(f"attempt {attempt}: div={div}" + (f" ({detail})" if detail else ""))
            if ok:
                note_attempt(f"attempt {attempt}: MATCH")
                return {"name": name, "matched": True, "divergences": 0, "attempts": attempt,
                        "c_source": code, "note": "", "log": att_log, "orig_div": None}, tin, tout
            # Keep the CLOSEST attempt, not the last one - a later try can be worse, and the
            # closest draft is what a refine pass wants to start from.
            if best is None or div < best_div:
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
            "c_source": best, "note": last_detail, "log": att_log, "orig_div": None}, tin, tout


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
    blob = json.dumps(out, indent=1)
    pathlib.Path(path).write_text(blob, encoding="utf-8")
    _archive_run(path, blob)


def _archive_run(path, blob, keep=40):
    """Keep a timestamped copy of every run's results next to the live one.

    The Console hands the driver ONE output path per agent and the next drive overwrites it, so a
    failing run destroys its own evidence as soon as anything else runs. That is not hypothetical:
    a driver reporting div=3 while the banking step re-verified the same source at 999 could not be
    diagnosed at all, because the results had already been clobbered by the following batch.

    The live path keeps its exact name and contents - the Console's contract is untouched. The copy
    (and the worklist that explains it, since results alone lack addr/size/module) goes in
    history/, oldest pruned past `keep`. Never fatal: losing an archive must not fail a good run."""
    try:
        live = pathlib.Path(path)
        hist = live.parent / "history"
        hist.mkdir(parents=True, exist_ok=True)
        stamp = time.strftime("%Y%m%d-%H%M%S")
        (hist / f"{live.stem}-{stamp}.output").write_text(blob, encoding="utf-8")
        wl = live.with_suffix(".worklist.jsonl")
        if not wl.is_file():  # <agent>.results.output -> <agent>.worklist.jsonl
            wl = live.parent / (live.name.split(".")[0] + ".worklist.jsonl")
        if wl.is_file():
            (hist / f"{live.stem}-{stamp}.worklist.jsonl").write_text(
                wl.read_text(encoding="utf-8"), encoding="utf-8")
        old = sorted(hist.glob("*.output"))[:-keep]
        for f in old:
            f.unlink(missing_ok=True)
            f.with_suffix(".worklist.jsonl").unlink(missing_ok=True)
    except OSError:
        pass


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
            try:
                res, i_tok, o_tok = f.result()
            except AuthFailed as e:
                for other in futs:
                    other.cancel()
                sys.exit(
                    f"\nauthentication failed - the API rejected the key, so nothing was attempted.\n"
                    f"  {e}\n"
                    f"Fix the key for this agent in Console's vault (GLM_API_KEY) and re-run. "
                    f"No targets were consumed and nothing was banked."
                )
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
