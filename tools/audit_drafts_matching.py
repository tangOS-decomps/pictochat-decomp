import os, sys, subprocess, re, json

draft_dirs = [r'drafts\arm9', r'drafts\arm7']
syms_file9 = r'config\arm9\symbols.txt'
syms_file7 = r'config\arm7\symbols.txt'

symbols_dict = {}

for sf in [syms_file9, syms_file7]:
    if os.path.exists(sf):
        with open(sf, 'r') as f:
            for line in f:
                if line.startswith('name='):
                    parts = dict(p.split('=', 1) for p in line.strip().split() if '=' in p)
                    symbols_dict[parts['name']] = parts
                    symbols_dict[parts['addr']] = parts

print("Auditing all draft files against match.py...\n")

matched_drafts = []
near_matches = []
non_matches = []

for ddir in draft_dirs:
    if not os.path.exists(ddir): continue
    files = [f for f in os.listdir(ddir) if f.endswith('.cpp')]

    for fname in files:
        path = os.path.join(ddir, fname)
        with open(path, 'r') as fp:
            content = fp.read()

        matches = re.findall(r'//\s*decomp:\s*module=(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
        if not matches:
            matches_alt = re.findall(r'addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
            matches = [('unk_autoload_0', addr, name) for addr, name in matches_alt]

        if not matches:
            continue

        for mod, addr, name in matches:
            size_str = '0x20'
            if name in symbols_dict:
                size_str = symbols_dict[name].get('size', '0x20')
                mod = symbols_dict[name].get('module', mod)
            elif addr in symbols_dict:
                size_str = symbols_dict[addr].get('size', '0x20')
                mod = symbols_dict[addr].get('module', mod)

            cmd = [
                sys.executable, 'tools/match.py',
                '--c', path,
                '--func', name,
                '--addr', addr,
                '--size', size_str,
                '--module', mod
            ]
            res = subprocess.run(cmd, capture_output=True, text=True)
            stdout = res.stdout

            is_100_match = ('MATCHING VERSIONS: dsi/1.3' in stdout or ('MATCHING VERSIONS:' in stdout and 'none' not in stdout))

            if is_100_match:
                matched_drafts.append({
                    'file': path,
                    'fname': fname,
                    'dir': ddir,
                    'func': name,
                    'addr': addr,
                    'size': size_str,
                    'module': mod
                })
                print(f"  [100% MATCH] {fname} -> {name} @ {addr}")
            else:
                # Check if size matches and diff is small
                size_differs = 'size differs:' in stdout
                if not size_differs and 'MISMATCH' in stdout:
                    near_matches.append({'file': path, 'func': name, 'addr': addr, 'size': size_str})
                else:
                    non_matches.append({'file': path, 'func': name, 'addr': addr, 'size': size_str})

print("\n================ Draft Audit Summary ================")
print(f"Total Drafts Audited: {len(matched_drafts) + len(near_matches) + len(non_matches)}")
print(f"  100% Byte Matches:  {len(matched_drafts)}")
print(f"  Near Matches:       {len(near_matches)}")
print(f"  Non-Matching:       {len(non_matches)}")
print("=====================================================\n")

# Save markdown audit report
report_path = r'notes\drafts-match-report.md'
with open(report_path, 'w') as f:
    f.write("# Drafts Byte-Matching Audit Report\n\n")
    f.write(f"- **Total Drafts Audited**: {len(matched_drafts) + len(near_matches) + len(non_matches)}\n")
    f.write(f"- **100% Byte Matches**: {len(matched_drafts)}\n")
    f.write(f"- **Near Matches**: {len(near_matches)}\n")
    f.write(f"- **Non-Matching**: {len(non_matches)}\n\n")

    f.write("## 100% Byte Matches\n")
    if matched_drafts:
        for m in matched_drafts:
            f.write(f"- `{m['fname']}` (`{m['func']}` @ `{m['addr']}`, size `{m['size']}`)\n")
    else:
        f.write("None currently in `drafts/`.\n")

    f.write("\n## Near Matches (Size Matched)\n")
    for m in near_matches[:20]:
        f.write(f"- `{m['file']}` (`{m['func']}` @ `{m['addr']}`, size `{m['size']}`)\n")

print(f"Report saved to {report_path}")
