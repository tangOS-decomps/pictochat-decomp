"""Verify every candidate in scratch/batch/ and bank the ones that match.

Hand-matching small functions goes fastest in BATCHES: write several drafts,
verify them all in one pass, keep the wins, and re-read only the misses. Doing
that with match.py one file at a time means re-typing the coordinates every
time and looking each size up by hand.

    python tools/verify_batch.py            # dry-run: report per file
    python tools/verify_batch.py --apply    # bank everything that matches

Drop `FUN_<addr>.c` / `.cpp` files in scratch/batch/ - coordinates come from
the filename via the function table, so no marker is needed while drafting
(ledger.bank() adds one when banking). Each candidate is tried against every
pinned build and at funcs.true_size(), the Ghidra size, and the candidate's own
length, so a function whose cached boundary excludes its literal pool still
matches instead of silently failing."""
import sys, pathlib, re
sys.path.insert(0, 'tools')
import match as M, funcs as F, templates as T, ledger as L

names = {f['name']: f for f in F.load_funcs() if f.get('module')}
apply_ = '--apply' in sys.argv
ok, bad = [], []
for cf in sorted(pathlib.Path('scratch/batch').glob('FUN_*.c*')):
    stem = cf.stem
    f = names.get(stem)
    if not f:
        bad.append((stem, 'not in function table')); continue
    src = cf.read_text(encoding='utf-8')
    flags = M.apply_flags_marker(T.flags_for(f['module'], f['mode']), src, allow_thumb_heuristic=False)
    good, used = [], None
    for v in M.PINNED:
        obj = M.compile_c(cf, v, flags)
        if not obj: continue
        code, relocs, _ = M.extract_func(obj, stem)
        if code is None: continue
        for sz in dict.fromkeys([F.true_size(f), f['size'], len(code)]):
            if sz <= 0: continue
            try: tgt = M.target_bytes(f['module'], f['addr'], sz)
            except SystemExit: continue
            if len(code) == sz and all(i//4*4 in relocs or code[i] == tgt[i] for i in range(sz)):
                good.append(v); used = sz; break
    if good:
        ok.append((stem, used, len(good)))
        if apply_:
            marker = L.marker_for(f['module'], f['addr'], stem)
            body = src
            if '// decomp:' not in body:
                first, rest = body.split('\n', 1) if body.startswith('//cpp') else ('', body)
                body = (first + '\n' + marker + '\n' + rest) if first else (marker + '\n' + body)
            print('  bank', stem, L.bank({"addr": f"0x{f['addr']:08x}", "name": stem,
                  "size": used, "module": f['module'], "versions": good}, body))
    else:
        bad.append((stem, 'no match'))
print(f"\nMATCH {len(ok)}/{len(ok)+len(bad)}")
for s, u, n in ok:  print(f"   ok    {s:16s} size={u:#x} builds={n}")
for s, why in bad: print(f"   FAIL  {s:16s} {why}")
