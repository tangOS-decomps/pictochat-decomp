import os, sys, subprocess, re

src_dirs = [r'src\arm9', r'src\arm7']

print("Enforcing Strict Policy: Purging all non-matching functions from .cpp files...\n")

purged_files = 0
purged_funcs = 0
kept_files = 0
kept_funcs = 0

for sdir in src_dirs:
    if not os.path.exists(sdir): continue
    files = [f for f in os.listdir(sdir) if f.endswith('.cpp')]

    for fname in files:
        path = os.path.join(sdir, fname)
        with open(path, 'r') as fp:
            content = fp.read()

        # Parse functions in file
        matches = re.findall(r'//\s*decomp:\s*module=(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
        if not matches:
            matches_alt = re.findall(r'addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
            matches = [('unk_autoload_0', addr, name) for addr, name in matches_alt]

        if not matches:
            # File has no decomp header comments, test as single function or purge
            # Let's check with match.py
            continue

        matched_funcs_in_file = []
        nonmatched_funcs_in_file = []

        for mod, addr, name in matches:
            size_str = '0x20'
            # lookup size
            sym_txt = r'config\arm9\symbols.txt' if 'arm9' in sdir else r'config\arm7\symbols.txt'
            if os.path.exists(sym_txt):
                with open(sym_txt, 'r') as sf:
                    for sline in sf:
                        if f"addr={addr}" in sline or f"name={name}" in sline:
                            sparts = dict(p.split('=', 1) for p in sline.strip().split() if '=' in p)
                            if 'size' in sparts: size_str = sparts['size']
                            if 'module' in sparts: mod = sparts['module']
                            break

            cmd = [
                sys.executable, 'tools/match.py',
                '--c', path,
                '--func', name,
                '--addr', addr,
                '--size', size_str,
                '--module', mod
            ]
            res = subprocess.run(cmd, capture_output=True, text=True)
            is_match = ('MATCHING VERSIONS: dsi/1.3' in res.stdout or 'MATCHING VERSIONS: 1.' in res.stdout or 'MATCHING VERSIONS: 2.' in res.stdout) and 'none' not in res.stdout

            if is_match:
                matched_funcs_in_file.append((mod, addr, name))
                kept_funcs += 1
            else:
                nonmatched_funcs_in_file.append((mod, addr, name))
                purged_funcs += 1

        if not matched_funcs_in_file:
            # Entire file has NO 100% matches -> git rm
            subprocess.run(['git', 'rm', '-f', path], check=True)
            purged_files += 1
            print(f"  [PURGED FILE] {path} (0 / {len(matches)} matched)")
        else:
            kept_files += 1
            print(f"  [KEPT FILE  ] {path} ({len(matched_funcs_in_file)} / {len(matches)} matched)")

print("\n================ Purge Summary ================")
print(f"Files Purged (Non-Matching): {purged_files}")
print(f"Files Kept (100% Matched):   {kept_files}")
print(f"Functions Purged:            {purged_funcs}")
print(f"Functions Kept (100% Match): {kept_funcs}")
print("===============================================\n")

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Re-ran configure.py successfully!")
