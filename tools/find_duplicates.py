"""Find byte-identical functions and auto-bank the free ones.

The compiler emits the exact same bytes for genuinely identical function
bodies at different addresses (small helpers, thin wrappers, empty stubs
whose real content is elsewhere) - this project already has real examples,
e.g. FUN_0232df74 turned out byte-identical to FUN_0232df40. This scans
every Ghidra-known function by raw byte content and groups exact matches.

Two things fall out of that grouping:
  * A group with >=1 already-matched member: every other member is free -
    same source (just a new `// decomp:` marker), re-verified through the
    normal oracle before banking, no drafting needed. `--apply` does this
    automatically.
  * A group with no matched member yet: these are worth targeting by hand
    (via the normal m2c_draft.py/ghidra_draft.py loop) in proportion to
    the group's size, since one match frees the rest. Printed either way,
    ranked biggest-group-first, so they're easy to prioritize.

Usage:
    python tools/find_duplicates.py              # report only
    python tools/find_duplicates.py --apply       # also bank the free ones
"""
import argparse
import collections
import pathlib
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import funcs as F   # noqa: E402
import match as M   # noqa: E402
import ledger as L  # noqa: E402


def matched_index():
    """{(module, addr): record} for every currently-matched function."""
    out = {}
    for rec in L.read_records(L.MATCHED):
        out[(rec["module"], int(rec["addr"], 16) if isinstance(rec["addr"], str) else rec["addr"])] = rec
    return out


def marker_index():
    """{(module, addr): path} from every `// decomp:` marker in src/ - the
    authoritative way to find a function's file, since its name may not be
    `<name>.c` (address-suffixed filenames disambiguate cross-module
    same-name symbols, e.g. IRQ::DisableEv exists on both arm7 and arm9)."""
    out = {}
    for sub in ("arm9", "arm7"):
        d = REPO / "src" / sub
        if not d.is_dir():
            continue
        for p in list(d.glob("*.c")) + list(d.glob("*.cpp")):
            head = p.read_text(encoding="utf-8", errors="ignore")[:400]
            m = L.MARKER_RE.search(head)
            if m:
                out[(m.group(1), int(m.group(2), 16))] = p
    return out


PAD = 16  # bytes of lookahead past each function's cached size, for the
          # false-duplicate check below


def rom_bytes(module, addr, length):
    rel_path, base = M.MODULES[module]
    path = M.DSD_EXTRACT / rel_path
    data = path.read_bytes()
    off = addr - base
    return data[off:off + length]


def find_groups():
    """Group functions by raw byte content - but see the false-duplicate
    guard below before trusting a group blindly."""
    by_bytes = collections.defaultdict(list)
    for f in F.load_funcs():
        if f["module"] is None:
            continue
        by_bytes[f["bytes"]].append(f)
    return {b: v for b, v in by_bytes.items() if len(v) > 1}


def false_duplicate(members):
    """True if this "duplicate" group is actually a Ghidra-undercounting
    artifact, not a real duplicate: functions like `ldr r0,[pc,#0]; bx lr`
    look byte-identical in the CACHED (truncated) size because Ghidra's
    boundary excludes each one's own trailing literal pool - but the pool
    words (the whole point of the function - which global it returns) are
    genuinely different per instance. Confirmed by reading PAD extra bytes
    straight from the ROM past the cached boundary for every member: a
    real duplicate stays identical there too; a false one diverges
    immediately (see notes/tooling.md's Ghidra-undercounting section)."""
    size = members[0]["size"]
    windows = {rom_bytes(f["module"], f["addr"], size + PAD) for f in members}
    return len(windows) > 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true", help="bank the free matches (dry-run otherwise)")
    args = ap.parse_args()

    matched = matched_index()
    markers = marker_index()
    raw_groups = find_groups()

    groups, false_groups = {}, []
    for b, members in raw_groups.items():
        if false_duplicate(members):
            false_groups.append(members)
        else:
            groups[b] = members

    # Key everything by (module, addr), never by name: the Ghidra cache's
    # names are FUN_xxxxxxxx placeholders as of whenever it was last
    # exported, so a function renamed to a real symbol since then (every
    # cross-matched one) would silently look "unmatched" by name alone.
    seeded, unseeded = [], []
    for b, members in groups.items():
        seed = next((f for f in members if (f["module"], f["addr"]) in matched), None)
        if seed:
            seeded.append((seed, members))
        else:
            unseeded.append(members)

    print(f"{len(raw_groups)} duplicate-byte group(s) by cached size, "
          f"{sum(len(v) for v in raw_groups.values())} function(s) total")
    if false_groups:
        print(f"{len(false_groups)} of those are FALSE duplicates (diverge once you read past "
              f"Ghidra's undercounted cache - real functions, real targets, not free matches)")
    print(f"{len(groups)} genuine duplicate-byte group(s) remain, "
          f"{sum(len(v) for v in groups.values())} function(s) total")
    print(f"{len(seeded)} group(s) already have a matched seed - free matches available")
    print(f"{len(unseeded)} group(s) have no matched seed yet - worth targeting by hand, biggest first\n")

    banked = 0
    for seed, members in seeded:
        seed_key = (seed["module"], seed["addr"])
        seed_rec = matched[seed_key]
        seed_real_name = seed_rec["name"]  # the real symbol, not the Ghidra placeholder
        src_path = markers.get(seed_key)
        if src_path is None:
            print(f"  ! seed source not found for {seed_real_name} (0x{seed['addr']:08x}) - skipping its group")
            continue
        seed_src = src_path.read_text(encoding="utf-8")
        # strip the seed's own marker/header lines (bank() re-adds one per target)
        body_lines = seed_src.splitlines(keepends=True)
        body = "".join(l for l in body_lines if not l.startswith("// decomp:"))

        for f in members:
            if (f["module"], f["addr"]) in matched:
                continue
            print(f"  {seed_real_name} -> {f['module']:16} {f['name']:30} @ 0x{f['addr']:08x} (0x{f['size']:x})")
            if not args.apply:
                continue
            flags = M.DEFAULT_FLAGS_ARM7 if f["module"] == "arm7" else M.DEFAULT_FLAGS
            if body.lstrip().startswith("//cpp") and "-lang c99" in flags:
                flags = flags.replace("-lang c99", "-lang c++")
            versions = seed_rec.get("versions") or [M.CANONICAL]
            ok_versions = []
            import tempfile
            with tempfile.NamedTemporaryFile(suffix=".c", mode="w", delete=False,
                                               encoding="utf-8") as tf:
                tf.write(body)
                tmp_path = pathlib.Path(tf.name)
            try:
                for v in versions:
                    obj = M.compile_c(tmp_path, v, flags)
                    if obj is None:
                        continue
                    code, relocs, reloc_info = M.extract_func(obj, f["name"])
                    if code is None:
                        continue
                    target = F.target_bytes(f)
                    ok, _ = M.compare(target, code, relocs, verbose=False)
                    if ok:
                        # A "duplicate" body still has to call/reference the same
                        # real addresses at its new site - compare() wildcards
                        # every reloc word, so check any address-named symbol
                        # against what the real bytes at this address resolve to.
                        bad = [r for r in M.verify_relocs(f["addr"], target, reloc_info,
                                                            f["mode"] == "thumb") if r[4] is False]
                        if bad:
                            print(f"    ! {f['name']} @ 0x{f['addr']:08x}: reloc target mismatch "
                                  f"({bad[0][1]} claims 0x{bad[0][2]:08x}, real bytes are "
                                  f"0x{bad[0][3]:08x}) - not a real duplicate, skipping")
                            continue
                        ok_versions.append(v)
            finally:
                tmp_path.unlink(missing_ok=True)
            if not ok_versions:
                print(f"    ! did not re-verify for {f['name']} - not banking (needs a real draft)")
                continue
            st = L.bank({"addr": f["addr"], "name": f["name"], "size": f["size"],
                          "module": f["module"], "versions": ok_versions}, body)
            print(f"    {st}")
            banked += st == "banked"

    if args.apply:
        print(f"\nbanked {banked} free match(es)")
    elif seeded:
        print("(dry-run: nothing banked; re-run with --apply)")

    if unseeded:
        print("\nunmatched duplicate groups (no seed yet), biggest first:")
        for members in sorted(unseeded, key=lambda m: -len(m)):
            names = ", ".join(f["name"] for f in members[:4])
            more = f" (+{len(members) - 4} more)" if len(members) > 4 else ""
            print(f"  {len(members):3}x  0x{members[0]['size']:<4x} {members[0]['module']:16} {names}{more}")


if __name__ == "__main__":
    main()
