import os, sys, subprocess, re, json

syms_file9 = r'config\arm9\symbols.txt'
syms_file7 = r'config\arm7\symbols.txt'
classified_file9 = r'config\arm9\classified_symbols.json'
classified_file7 = r'config\arm7\classified_symbols.json'

symbols_dict = {}
for sf in [syms_file9, syms_file7]:
    if os.path.exists(sf):
        with open(sf, 'r') as f:
            for line in f:
                if line.startswith('name='):
                    parts = dict(p.split('=', 1) for p in line.strip().split() if '=' in p)
                    symbols_dict[parts['name']] = parts

print("=== MASS AUTOMATED MATCHING ENGINE ===", flush=True)
print("Scanning all draft candidate files across drafts/arm9 and drafts/arm7...\n", flush=True)

promoted_files = []

for ddir in [r'drafts\arm9', r'drafts\arm7']:
    if not os.path.exists(ddir): continue
    is_arm7 = 'arm7' in ddir.lower()
    target_src_dir = ddir.replace('drafts', 'src')

    files = [f for f in os.listdir(ddir) if f.endswith('.cpp')]
    for fname in files:
        fpath = os.path.join(ddir, fname)
        print(f"Checking {fname}...", flush=True)
        with open(fpath, 'r') as fp: content = fp.read()

        matches = re.findall(r'//\s*decomp:\s*module=(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
        if not matches:
            matches_alt = re.findall(r'addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
            matches = [('unk_autoload_0', addr, name) for addr, name in matches_alt]

        if not matches: continue

        for mod, addr, name in matches:
            orig_size_str = symbols_dict.get(name, {}).get('size', '0x20')
            mod = symbols_dict.get(name, {}).get('module', mod)

            # Test sizes: original size, original size + 4 (literal pool), original size + 8
            orig_size_int = int(orig_size_str, 16)
            size_candidates = [hex(orig_size_int), hex(orig_size_int + 4), hex(orig_size_int + 8)]

            is_match = False
            matched_size = orig_size_str

            for sz in size_candidates:
                cmd = [
                    sys.executable, 'tools/match.py',
                    '--c', fpath,
                    '--func', name,
                    '--addr', addr,
                    '--size', sz,
                    '--module', mod
                ]
                if is_arm7:
                    cmd.extend(['--flags', '-O4,p -enum int -lang c++ -char signed -interworking -proc arm7tdmi -gccext,on -msgstyle gcc -Iinclude'])

                res = subprocess.run(cmd, capture_output=True, text=True)
                if ('MATCHING VERSIONS: dsi/1.3' in res.stdout or 'MATCHING VERSIONS: 1.' in res.stdout) and 'none' not in res.stdout:
                    is_match = True
                    matched_size = sz
                    break

            if not is_match and 'extern "C"' not in content:
                # Wrap with extern "C" and re-test
                wrapped_content = f'extern "C" {{\n{content}\n}}\n'
                with open(fpath, 'w') as fp: fp.write(wrapped_content)

                for sz in size_candidates:
                    cmd = [
                        sys.executable, 'tools/match.py',
                        '--c', fpath,
                        '--func', name,
                        '--addr', addr,
                        '--size', sz,
                        '--module', mod
                    ]
                    if is_arm7:
                        cmd.extend(['--flags', '-O4,p -enum int -lang c++ -char signed -interworking -proc arm7tdmi -gccext,on -msgstyle gcc -Iinclude'])

                    res = subprocess.run(cmd, capture_output=True, text=True)
                    if ('MATCHING VERSIONS: dsi/1.3' in res.stdout or 'MATCHING VERSIONS: 1.' in res.stdout) and 'none' not in res.stdout:
                        is_match = True
                        matched_size = sz
                        break

                if not is_match:
                    # Restore original content
                    with open(fpath, 'w') as fp: fp.write(content)

            if is_match:
                # Update symbol size if changed
                if matched_size != orig_size_str:
                    target_sym_file = syms_file7 if is_arm7 else syms_file9
                    target_class_file = classified_file7 if is_arm7 else classified_file9
                    
                    if os.path.exists(target_sym_file):
                        with open(target_sym_file, 'r') as sf: lines = sf.readlines()
                        lines = [re.sub(fr'name={re.escape(name)}.*size=0x[0-9a-fA-F]+', f'name={name} module={mod} addr={addr} size={matched_size}', l) for l in lines]
                        with open(target_sym_file, 'w') as sf: sf.writelines(lines)

                # Promote file from drafts to src
                dst_path = os.path.join(target_src_dir, fname)
                os.makedirs(target_src_dir, exist_ok=True)
                res_mv = subprocess.run(['git', 'mv', fpath, dst_path], capture_output=True)
                if res_mv.returncode != 0:
                    os.rename(fpath, dst_path)

                promoted_files.append((fname, dst_path, name, addr, matched_size))
                print(f"  [100% BYTE MATCH PROMOTED] {fname} ({name} @ {addr}, size {matched_size}) -> {dst_path}", flush=True)

print(f"\n========================================================", flush=True)
print(f"Mass Matching Engine Completed! Total Promoted: {len(promoted_files)}", flush=True)
print(f"========================================================\n", flush=True)
