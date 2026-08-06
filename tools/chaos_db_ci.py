"""CI-safe progress data generator: rebuild chaos-db.json from COMMITTED data only
(no ROM, no local extracted/, no ledger), so a GitHub Action can refresh it on every
push and the tangos.dev card / any viewer always shows current numbers.

Same shape as sm64ds-decomp's tools/chaos_db_ci.py, adapted to this repo's model:
  universe   config/{arm9,arm7}/symbols.txt  (name, module, addr, size - committed by
             tools/gen_symbols.py from the local Ghidra export; boundaries, no bytes)
  matched    a committed src/arm9|arm7/*.c[pp] carries a `// decomp: module=.. addr=..`
             marker (tools/ledger.py) for that function and is NOT parked `// NONMATCHING:`

  author     git history: the FIRST contributor to land the surviving match for each
             src file. Credit follows renames, so a later duplicate match or a mass
             rename does not steal it (login from users.noreply emails, else the
             email local-part, else the author name)

The `stats` block is the contract tangos.dev's romstats-sync reads: totalBytes,
matchedBytes, moduleCount, matchedFunctions (plus totalFunctions, generatedAt).

--contrib-out additionally writes contributions.json: matched-function count and
weighted match-coin count per contributor. That file is the input tangos.dev's match
coin ledger reads; it credits the DELTA between a published career total and what it
last paid, so this must be regenerated on every push to main and committed.

Until config/{arm9,arm7}/symbols.txt exists the universe is empty and only the matched
COUNT is meaningful - byte totals and the percentage need the symbols table.

Usage: python tools/chaos_db_ci.py [--out chaos-db.json] [--contrib-out contributions.json]
"""
import argparse
import collections
import json
import pathlib
import re
import subprocess
import time

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
SRC = REPO / "src"

# GitHub hands out noreply commit emails as [id+]login@users.noreply.github.com, which
# is the one git field that reliably carries the actual login.
LOGIN_RE = re.compile(r"^(?:\d+\+)?([^@]+)@users\.noreply\.github\.com$")

# Match-coin weighting, per module. A match is worth 1 MC by default; a module listed
# here is worth its multiplier instead, to steer effort somewhere. Nothing is weighted
# here yet - arm9 and arm7 both pay the flat rate.
COIN_WEIGHTS: dict[str, int] = {}

# Bump whenever COIN_WEIGHTS changes. The ledger credits the DELTA between a published
# career total and what it last paid, so a formula change would otherwise read as a
# flood of new matches and pay a retroactive windfall (and fire a wall of Discord
# milestones). The backend rebases silently when this number moves: it banks the new
# totals as already-credited without touching balances, so a weight change only ever
# affects matches landed AFTER it.
COIN_FORMULA = 1

# One universe line: name=.. module=.. addr=0x.. size=0x.. (tools/gen_symbols.py output).
SYM_RE = re.compile(
    r"^name=(\S+)\s+module=(\S+)\s+addr=0x([0-9a-fA-F]+)\s+size=0x([0-9a-fA-F]+)\s*$")
# The src-file -> function link (tools/ledger.py marker_for / MARKER_RE).
MARKER_RE = re.compile(
    r"^// decomp: module=(\S+) addr=(0x[0-9a-fA-F]+) name=(\S+)\s*$", re.M)

CPUS = ("arm9", "arm7")


def matched_src():
    """{(module, addr): 'src/arm9/x.c'} for every committed, byte-matched src file -
    keyed by its `// decomp:` marker. Parked `// NONMATCHING:` files are excluded:
    they are logic-correct but not byte-exact, so they do not count as matched."""
    out = {}
    for cpu in CPUS:
        d = SRC / cpu
        if not d.is_dir():
            continue
        for p in sorted(list(d.glob("*.c")) + list(d.glob("*.cpp"))):
            head = p.read_text(encoding="utf-8", errors="ignore")[:400]
            if "// NONMATCHING:" in head:
                continue
            m = MARKER_RE.search(head)
            if not m:
                continue
            module, addr = m.group(1), int(m.group(2), 16)
            out[(module, addr)] = f"src/{cpu}/{p.name}"
    return out


def universe():
    """[(name, module, addr, size), ...] from config/{arm9,arm7}/symbols.txt."""
    rows = []
    for cpu in CPUS:
        sym = CONFIG / cpu / "symbols.txt"
        if not sym.is_file():
            continue
        for line in sym.read_text(encoding="utf-8", errors="ignore").splitlines():
            m = SYM_RE.match(line)
            if m:
                rows.append((m.group(1), m.group(2), int(m.group(3), 16), int(m.group(4), 16)))
    return rows


def _handle_from(name: str, email: str) -> str:
    """git identity -> canonical-ish handle: noreply login, else the email local-part
    (stable across author-name typos, usually equals the GitHub handle), else the name."""
    email = email.strip()
    m = LOGIN_RE.match(email)
    return m.group(1) if m else (email.split("@")[0].lower() or name.strip())


def first_matchers(rev="HEAD") -> dict[str, str]:
    """{'src/arm9/name.ext': handle} crediting each currently-tracked file to the FIRST
    contributor to land the match it descends from. A later duplicate submission of the
    same function does not steal it.

    Replays the whole src/ history oldest-first, tracking one 'origin author' per live
    path, following git's own add / delete / rename classification (-M):
      * add     -- starts a lineage: the adder owns it (setdefault, so replay is safe)
      * rename  -- CARRIES the origin author forward, so a mass symbol-rename keeps the
                   original matcher's credit instead of handing it to the renamer
      * delete  -- ENDS the lineage. A later add at that path is a fresh match and
                   credits the new author, which is the false-match case: a wrong match
                   that was deleted and later redone correctly must credit whoever
                   landed the surviving one.
    The rename / delete+add distinction is git's content-similarity call, which is what
    separates 'same match, new name' from 'the first attempt was wrong'."""
    # diff.renameLimit=0 lifts the exhaustive-rename cap. Without it a bulk rename
    # degrades to delete+add and the mass-renamer wrongly inherits everyone's credit.
    out = subprocess.run(
        ["git", "-c", "diff.renameLimit=0", "log", "--reverse", "--diff-filter=ADR", "-M",
         "--format=%x01%an%x02%ae", "--name-status", rev, "--", "src/"],
        cwd=REPO, capture_output=True, text=True, encoding="utf-8", errors="replace").stdout
    origin: dict[str, str] = {}   # live path -> author of the earliest add in its lineage
    handle = None
    adds: list[str] = []
    dels: list[str] = []

    def flush(who):
        """Apply one commit's adds/deletes, pairing a same-stem delete+add as a rename.

        Promoting a matched function from .c to .cpp can rewrite enough of the body that
        git's similarity check misses the rename, so it arrives as delete+add. That is
        still the SAME function, so ending the lineage would hand the original matcher's
        credit to whoever did the promotion. Pairing is deliberately limited to a delete
        and an add of the same stem IN ONE COMMIT, which cannot be confused with the
        false-match case: that is a delete in one commit and a corrected add in a later.
        """
        by_stem = {d.rsplit(".", 1)[0]: d for d in dels}
        paired = set()
        for new in adds:
            old = by_stem.get(new.rsplit(".", 1)[0])
            if old is not None and old != new:
                origin[new] = origin.pop(old, who)   # same function, new extension
                paired.add(old)
                paired.add(new)
        for a in adds:
            if a not in paired:
                origin.setdefault(a, who)
        for d in dels:
            if d not in paired:
                origin.pop(d, None)
        adds.clear()
        dels.clear()

    for line in out.splitlines():
        if line.startswith("\x01"):
            if handle:
                flush(handle)
            name, _, email = line[1:].partition("\x02")
            handle = _handle_from(name, email)
        elif handle and line and line[0] in "ADR":
            parts = line.split("\t")
            code = parts[0]
            if code.startswith("A") and len(parts) >= 2:
                adds.append(parts[1].strip())
            elif code.startswith("D") and len(parts) >= 2:
                dels.append(parts[1].strip())
            elif code.startswith("R") and len(parts) >= 3:
                old, new = parts[1].strip(), parts[2].strip()
                origin[new] = origin.pop(old, handle)  # carry the matcher's credit forward
    if handle:
        flush(handle)
    return origin


def match_finishers(rev="HEAD") -> dict[str, str]:
    """{'src/arm9/name.ext': handle} crediting whoever FIRST turned a NONMATCHING draft
    into a real byte-match -- the person who actually matched the function.

    first_matchers() credits whoever added a path first, which is wrong whenever that
    first version was an unmatched draft: the file only becomes countable once someone
    removes the banner, so the drafter would collect credit for someone else's match.

    A finish is identified by CONTENT, not by commit message: the path carried the
    NONMATCHING banner at some earlier point and does not at this commit. The FIRST such
    transition wins, so re-touching an already-matched file never transfers credit.

    This walks full history with per-path state rather than filtering diffs, because
    every diff-shaped approach misses cases:
      - `git log -- <path>` applies history simplification and silently prunes commits
        that arrived through a merge, so a match landing on a side branch is invisible.
      - the -G pickaxe lists only files whose own diff contains the pattern, so a newly
        added byte-matching file -- banner-free by definition -- is never reported.
    Draft state also has to follow a file across an extension change, which git records
    as a rename when the edit is small and as delete + add of the same stem when not.

    Cost is one full-history log plus a single batched `git cat-file`."""
    REC, FLD, SUB = "\x01", "\x02", "\x03"
    out = subprocess.run(
        ["git", "-c", "diff.renameLimit=0", "log", "--full-history", "--reverse",
         f"--format={REC}%H{FLD}%an{SUB}%ae", "--name-status", "-M", rev, "--", "src/"],
        cwd=REPO, capture_output=True, text=True, encoding="utf-8", errors="replace").stdout

    commits: list[tuple[str, str, list]] = []
    sha = handle = None
    ents: list = []
    for line in out.splitlines():
        if line.startswith(REC):
            if sha:
                commits.append((sha, handle, ents))
            sha, _, rest = line[1:].partition(FLD)
            name, _, email = rest.partition(SUB)
            handle, ents = _handle_from(name, email), []
            continue
        if not sha or not line.strip():
            continue
        parts = line.split("\t")
        if len(parts) >= 2:
            ents.append((parts[0], [x.strip() for x in parts[1:]]))
    if sha:
        commits.append((sha, handle, ents))

    def target(code: str, paths: list[str]) -> str:
        return paths[1] if (code.startswith("R") and len(paths) >= 2) else paths[0]

    want = sorted({(s, target(c, p)) for s, _, es in commits for c, p in es
                   if not c.startswith("D")})
    if not want:
        return {}
    proc = subprocess.Popen(["git", "cat-file", "--batch"], cwd=REPO,
                            stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    query = "".join(f"{s}:{p}" + "\n" for s, p in want).encode()
    data, _ = proc.communicate(query)

    state: dict[tuple[str, str], str | None] = {}
    pos = idx = 0
    while pos < len(data) and idx < len(want):
        nl = data.find(b"\n", pos)
        if nl < 0:
            break
        header = data[pos:nl].decode("utf-8", "replace")
        pos = nl + 1
        if header.endswith("missing"):
            state[want[idx]] = None
            idx += 1
            continue
        try:
            size = int(header.rsplit(" ", 1)[1])
        except (IndexError, ValueError):
            break
        # Clamp the banner window to THIS blob. `data` is one concatenated cat-file batch
        # response, so a fixed-size read runs past any shorter blob into the next one's
        # header and content, and a clean blob followed by a drafted one reads as drafted.
        state[want[idx]] = ("draft" if b"// NONMATCHING" in data[pos:pos + min(400, size)]
                            else "clean")
        pos += size + 1
        idx += 1

    drafted: set[str] = set()
    finishers: dict[str, str] = {}
    for sha, handle, ents in commits:
        for code, paths in ents:                       # an extension change keeps its history
            if code.startswith("R") and len(paths) >= 2:
                if paths[0] in drafted:
                    drafted.add(paths[1])
                # ...and so does the finish. Carrying `drafted` alone leaks credit: the
                # renamed path arrives still marked drafted with a clean blob and no
                # finisher entry, so the clause below reads it as a fresh finish and hands
                # the match to whoever moved the file.
                if paths[0] in finishers:
                    finishers[paths[1]] = finishers.pop(paths[0])
        dels = [p[0] for c, p in ents if c.startswith("D")]
        adds = [p[0] for c, p in ents if c.startswith("A")]
        for d in dels:                                 # ...whether git called it a rename or not
            if d not in drafted:
                continue
            base = d.rsplit(".", 1)[0]
            for a in adds:
                if a != d and a.rsplit(".", 1)[0] == base:
                    drafted.add(a)
                    if d in finishers:
                        finishers[a] = finishers.pop(d)
        for code, paths in ents:
            if code.startswith("D"):
                continue                               # a delete never clears the draft history
            new = target(code, paths)
            blob = state.get((sha, new))
            if blob == "draft":
                drafted.add(new)
            elif blob == "clean" and new in drafted and new not in finishers:
                finishers[new] = handle
    return finishers


def attribution_overrides() -> dict[str, str]:
    """Manual {'src/arm9/name.c': github_login} for matches the git-add author gets wrong
    -- e.g. work that landed via a maintainer's consolidating PR or squash, which records
    the maintainer (not the matcher) as the commit author. Applied with HIGHEST priority.
    Lives in attribution.json at the repo root: {"overrides": {"src/x.c": "login", ...}}."""
    p = REPO / "attribution.json"
    if not p.is_file():
        return {}
    try:
        data = json.loads(p.read_text(encoding="utf-8"))
        ov = data.get("overrides", {}) if isinstance(data, dict) else {}
        return {k: v for k, v in ov.items()
                if isinstance(k, str) and k.startswith("src/") and isinstance(v, str) and v}
    except Exception as e:
        print(f"  (attribution.json overrides skipped: {e})")
        return {}


def identity_aliases() -> dict[str, str]:
    """{'git_handle': 'github_login'} collapsing one person's many git identities into a
    single login -- git records vary the author email/name per machine and per squash, so
    the same human otherwise splits into several buckets. Keys are the lowercased handles
    _handle_from produces. From attribution.json: {"aliases": {"alt": "canonical"}}."""
    p = REPO / "attribution.json"
    if not p.is_file():
        return {}
    try:
        data = json.loads(p.read_text(encoding="utf-8"))
        al = data.get("aliases", {}) if isinstance(data, dict) else {}
        return {str(k).lower(): v for k, v in al.items() if isinstance(v, str) and v}
    except Exception:
        return {}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="chaos-db.json")
    ap.add_argument("--contrib-out", default=None,
                    help="path for contributions.json (default: next to --out)")
    args = ap.parse_args()

    matched = matched_src()
    funcs = universe()

    finishers = match_finishers()        # src path -> who turned the draft into a real match
    firstmatch = first_matchers()        # src path -> first contributor to land the match
    overrides = attribution_overrides()  # manual fixes, highest priority
    aliases = identity_aliases()         # collapse one person's split git identities

    def canon(login):                    # apply the alias map (idempotent)
        return aliases.get(login.lower(), login)

    def author_of(src_path):
        """Priority: manual override > whoever FINISHED the match (turned the NONMATCHING
        draft byte-identical) > whoever first added the file."""
        who = (overrides.get(src_path) or finishers.get(src_path)
               or firstmatch.get(src_path))
        return canon(who) if who else None

    functions = []
    total_b = matched_b = matched_n = 0
    seen = set()
    for name, module, addr, size in funcs:
        seen.add((module, addr))
        src_path = matched.get((module, addr))
        is_matched = src_path is not None
        total_b += size
        rec = {"id": f"{module}:0x{addr:08x}", "module": module, "name": name,
               "addr": addr, "size": size, "matched": is_matched}
        if src_path:
            rec["srcPath"] = src_path
            if (who := author_of(src_path)) is not None:
                rec["author"] = who
            matched_b += size
            matched_n += 1
        functions.append(rec)

    # A matched src file whose function is not in the symbols table yet (export predates
    # the match, or symbols.txt is missing) still counts - otherwise a fresh match would
    # briefly vanish from the total. It contributes to the matched count with size 0.
    orphan = 0
    for (module, addr), src_path in sorted(matched.items()):
        if (module, addr) in seen:
            continue
        orphan += 1
        matched_n += 1
        rec = {"id": f"{module}:0x{addr:08x}", "module": module,
               "name": pathlib.Path(src_path).stem, "addr": addr, "size": 0,
               "matched": True, "srcPath": src_path}
        # An orphan is still a real match by a real person, so it earns like one. Leaving
        # it unauthored would drop coins for anyone whose match landed ahead of the next
        # symbols.txt export.
        if (who := author_of(src_path)) is not None:
            rec["author"] = who
        functions.append(rec)

    stats = {
        "totalFunctions": len(funcs) + orphan,
        "matchedFunctions": matched_n,
        "totalBytes": total_b,
        "matchedBytes": matched_b,
        "moduleCount": len({f["module"] for f in functions}),
    }
    db = {
        "generatedAt": time.strftime("%Y-%m-%d %H:%M", time.gmtime()) + " UTC",
        "project": {"name": "pictochat-decomp", "title": "PictoChat", "platform": "nds"},
        "stats": stats,
        "functions": functions,
    }
    out = pathlib.Path(args.out)
    out.write_text(json.dumps(db), encoding="utf-8")
    pct = (100.0 * matched_b / total_b) if total_b else 0.0
    note = "" if funcs else "  (no symbols.txt yet - matched count only, no total/percentage)"
    print(f"wrote {out} ({out.stat().st_size // 1024} KB): "
          f"{matched_n}/{stats['totalFunctions']} funcs matched, "
          f"{matched_b}/{total_b} bytes ({pct:.2f}%), "
          f"{stats['moduleCount']} modules{note}, "
          f"{sum(1 for f in functions if 'author' in f)} authored")

    # The single source of truth for the contributor chart AND the match coin ledger:
    # matched-function count per canonical login. Regenerated on every merge, so
    # someone's number is a committed fact rather than re-derived from git each time.
    tally = collections.Counter(f["author"] for f in functions if f.get("author"))
    # Weighted match coins. Kept as a SEPARATE field from `matched`, which stays the
    # plain honest count the contributor chart reads.
    coins = collections.Counter()
    for f in functions:
        if who := f.get("author"):
            coins[who] += COIN_WEIGHTS.get(f["module"], 1)
    contrib = {
        "generatedAt": db["generatedAt"],
        "note": "Matched functions per contributor (canonical GitHub login), credited to whoever "
                "landed each match FIRST (credit follows renames; a later duplicate match does not "
                "steal it). Auto-generated by tools/chaos_db_ci.py from committed matches, git "
                "history, attribution.json aliases (collapse split identities) + overrides. Do not "
                "hand-edit; fix names in attribution.json instead. `matched` is the honest function "
                "count; `coins` is the same set weighted by COIN_WEIGHTS (match coins), which is "
                "what the MC ledger spends. They differ only for weighted modules.",
        "totalMatched": matched_n,
        "coinFormula": COIN_FORMULA,
        "coinWeights": COIN_WEIGHTS,
        "contributors": [{"login": who, "matched": n, "coins": coins[who]}
                         for who, n in tally.most_common()],
    }
    cpath = (pathlib.Path(args.contrib_out) if args.contrib_out
             else out.with_name("contributions.json"))
    cpath.write_text(json.dumps(contrib, indent=1), encoding="utf-8")
    print(f"wrote {cpath}: {len(tally)} contributors "
          f"(top: {', '.join(f'{w}={n}' for w, n in tally.most_common(4))})")


if __name__ == "__main__":
    main()
