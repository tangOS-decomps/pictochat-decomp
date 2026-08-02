"""Canonical match-ledger I/O: progress/matched.jsonl + progress/nonmatching.jsonl.

Ported from sm64ds-decomp's tools/ledger.py, adapted for this project's fixed
five-module set (no overlays - see tools/funcs.py) and its src/arm9 vs
src/arm7 split (not one flat src/ dir).

Everything that writes a verified match should go through bank() here rather
than hand-rolling a write to src/, so that:

  * a cross-process lock (atomic-mkdir mutex) serializes appends - important
    once this project has more than one contributor running templates.py or
    the permuter batch runner at the same time, so two of them can't land the
    same (module, addr) twice;
  * the done-set is re-checked under the lock, so a race always resolves to
    exactly one winner ("dup" for the loser, not a corrupted ledger);
  * a contributor's merged PR is "adopted" cleanly: the src file lands via
    git, but their local gitignored matched.jsonl never saw it - bank() sees
    the src file already matches byte-for-byte and just appends the record
    instead of refusing.

Two done-set flavors:
  matched_set()  -- byte-exact matches only. "Done" = verified match.
  load_done()    -- matched PLUS parked (nonmatching.jsonl). "Done" = do not
                    re-select as a target.
"""
import json
import os
import pathlib
import sys
import time

REPO = pathlib.Path(__file__).resolve().parent.parent
SRC = REPO / "src"
MATCHED = REPO / "progress" / "matched.jsonl"
NONMATCHING = REPO / "progress" / "nonmatching.jsonl"
LOCKDIR = REPO / "progress" / ".lock"


def norm_addr(addr):
    return int(addr, 0) if isinstance(addr, str) else int(addr)


def make_key(module, addr):
    return (module, norm_addr(addr))


def key_of(record):
    return make_key(record["module"], record["addr"])


def read_records(path):
    """Yield parsed records from a JSONL ledger. A corrupt line is reported to
    stderr with its line number, never silently swallowed."""
    path = pathlib.Path(path)
    if not path.is_file():
        return
    for lineno, line in enumerate(
            path.read_text(encoding="utf-8", errors="ignore").splitlines(), 1):
        if not line.strip():
            continue
        try:
            yield json.loads(line)
        except Exception as e:
            print(f"ledger: {path}:{lineno}: corrupt line skipped ({e})", file=sys.stderr)


def _key_set(path):
    out = set()
    for rec in read_records(path):
        try:
            out.add(key_of(rec))
        except Exception as e:
            print(f"ledger: {path}: record without usable module/addr skipped ({e})",
                  file=sys.stderr)
    return out


def matched_set():
    return _key_set(MATCHED)


def nonmatching_set():
    return _key_set(NONMATCHING)


def load_done():
    return matched_set() | nonmatching_set()


class locked:
    """Cross-process mutex via atomic mkdir. Hold only for the brief
    read-check-append - never while compiling or permuting."""

    def __init__(self, lockdir=LOCKDIR, timeout=120.0):
        self.lockdir = pathlib.Path(lockdir)
        self.timeout = timeout

    def __enter__(self):
        self.lockdir.parent.mkdir(parents=True, exist_ok=True)
        deadline = time.monotonic() + self.timeout
        while True:
            try:
                os.mkdir(self.lockdir)
                return self
            except FileExistsError:
                if time.monotonic() >= deadline:
                    raise TimeoutError(f"could not acquire {self.lockdir}")
                time.sleep(0.1)

    def __exit__(self, *a):
        try:
            os.rmdir(self.lockdir)
        except OSError:
            pass


def _format(record):
    rec = dict(record)
    mod, addr = key_of(record)
    rec["module"] = mod
    rec["addr"] = f"0x{addr:08x}"
    if isinstance(rec.get("size"), str):
        rec["size"] = int(rec["size"], 0)
    return rec


def _append_line(path, rec):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("a", encoding="utf-8") as f:
        f.write(json.dumps(rec) + "\n")


def append_matched(record):
    """Returns True if written, False on duplicate."""
    rec = _format(record)
    with locked():
        if key_of(rec) in matched_set():
            return False
        _append_line(MATCHED, rec)
    return True


def append_nonmatching(record):
    """Returns True if written, False if already matched or parked."""
    rec = _format(record)
    with locked():
        if key_of(rec) in load_done():
            return False
        _append_line(NONMATCHING, rec)
    return True


def src_path(module, name, ext):
    sub = "arm7" if module == "arm7" else "arm9"
    return SRC / sub / f"{name}.{ext}"


def marker_for(module, addr, name):
    """Machine-readable one-liner stamped at the top of every banked file, so
    tools/sync_ledger.py can rebuild the (gitignored) ledger from committed
    src/ alone on a fresh clone - even after a function gets renamed from its
    Ghidra placeholder (FUN_xxxxxxxx) to a real symbol, which breaks the
    filename-based fallback lookup."""
    return f"// decomp: module={module} addr=0x{norm_addr(addr):08x} name={name}\n"


MARKER_RE = __import__("re").compile(
    r"^// decomp: module=(\S+) addr=(0x[0-9a-fA-F]+) name=(\S+)\s*$", __import__("re").M)


def bank(record, src_text):
    """Bank one verified match: write src/arm{9,7}/<name>.c|cpp (prefixed with
    a `// decomp:` marker comment - see marker_for()) and append the record to
    matched.jsonl, both under the ledger lock.

    Returns "banked", "dup" (key already matched - e.g. a concurrent
    contributor won the race), or "refused". Refusals go to stderr and cover:
      * <name> already matched at a DIFFERENT (module, addr);
      * an existing src/<name>.* file we cannot prove belongs to this key
        (the only sanctioned overwrite is a NONMATCHING hatch parked for the
        SAME key, which a verified match upgrades).
    """
    rec = _format(record)
    k = key_of(rec)
    name = rec["name"]
    ext = "cpp" if src_text.startswith("//cpp") else "c"
    body = src_text if src_text.endswith("\n") else src_text + "\n"
    if not MARKER_RE.search(body):
        marker = marker_for(k[0], k[1], name)
        # keep a leading `//cpp` directive first (swarm/templates near-miss
        # convention), marker right after it
        if body.startswith("//cpp"):
            first, rest = body.split("\n", 1)
            body = first + "\n" + marker + rest
        else:
            body = marker + body

    with locked():
        keys, owner = set(), None
        for r in read_records(MATCHED):
            try:
                k2 = key_of(r)
            except Exception:
                continue
            keys.add(k2)
            if owner is None and r.get("name") == name and k2 != k:
                owner = k2
        if k in keys:
            return "dup"
        if owner is not None:
            print(f"ledger: REFUSED to bank {name} at {k}: name already matched "
                  f"at {owner}", file=sys.stderr)
            return "refused"

        existing = [p for p in (src_path(k[0], name, "c"), src_path(k[0], name, "cpp"))
                    if p.exists()]
        if existing:
            same = [p for p in existing
                    if p.suffix == "." + ext and p.read_text(encoding="utf-8") == body]
            if same:
                _append_line(MATCHED, rec)
                _drop_nonmatching(k)
                return "banked"
            parked_owner = None
            for r in read_records(NONMATCHING):
                if r.get("name") == name:
                    try:
                        parked_owner = key_of(r)
                    except Exception:
                        pass
                    break
            all_hatches = all(
                "NONMATCHING" in p.read_text(encoding="utf-8", errors="replace")[:200]
                for p in existing)
            if parked_owner != k and not all_hatches:
                print(f"ledger: REFUSED to bank {name} at {k}: "
                      f"{existing[0].name} exists and is not a hatch parked for "
                      f"this (module, addr)", file=sys.stderr)
                return "refused"
            stale = [p for p in existing if p.suffix != "." + ext]
            if stale:
                if all_hatches:
                    for p in stale:
                        p.unlink()
                else:
                    print(f"ledger: REFUSED to bank {name} at {k}: existing "
                          f"{stale[0].name} has a different extension than the "
                          f"new .{ext}; resolve by hand", file=sys.stderr)
                    return "refused"

        path = src_path(k[0], name, ext)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(body, encoding="utf-8")
        _append_line(MATCHED, rec)
        _drop_nonmatching(k)
    return "banked"


def _drop_nonmatching(k):
    """A verified match overrides a stale park. Caller holds the ledger lock."""
    if not NONMATCHING.exists():
        return
    kept, dropped = [], 0
    for line in NONMATCHING.read_text(encoding="utf-8").splitlines():
        if not line.strip():
            continue
        try:
            if key_of(json.loads(line)) == k:
                dropped += 1
                continue
        except Exception:
            pass
        kept.append(line)
    if dropped:
        tmp = NONMATCHING.with_name(NONMATCHING.name + ".tmp")
        tmp.write_text("".join(l + "\n" for l in kept), encoding="utf-8")
        os.replace(tmp, NONMATCHING)
