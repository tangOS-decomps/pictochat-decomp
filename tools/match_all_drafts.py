import os, sys, subprocess, re

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

print("Running Automated Matching Sweep across all draft files...\n")

matched_count = 0
promoted_files = []

for ddir in draft_dirs:
    if not os.path.exists(ddir): continue
    target_src_dir = ddir.replace('drafts', 'src')

    for fname in os.listdir(ddir):
        if not fname.endswith('.cpp'): continue
        path = os.path.join(ddir, fname)
        with open(path, 'r') as fp:
            content = fp.read()

        matches = re.findall(r'//\s*decomp:\s*module=(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
        if not matches:
            matches_alt = re.findall(r'addr=(0x[0-9a-fA-F]+)\s+name=(\S+)', content)
            matches = [('unk_autoload_0', addr, name) for addr, name in matches_alt]

        if not matches: continue

        # Test each function
        file_is_100_percent_matched = True

        for mod, addr, name in matches:
            size_str = '0x20'
            if name in symbols_dict:
                size_str = symbols_dict[name].get('size', '0x20')
                mod = symbols_dict[name].get('module', mod)
            elif addr in symbols_dict:
                size_str = symbols_dict[addr].get('size', '0x20')
                mod = symbols_dict[addr].get('module', mod)

            # Try matching
            cmd = [
                sys.executable, 'tools/match.py',
                '--c', path,
                '--func', name,
                '--addr', addr,
                '--size', size_str,
                '--module', mod
            ]
            if 'arm7' in ddir.lower():
                cmd.extend(['--flags', '-O4,p -enum int -lang c++ -char signed -interworking -proc arm7tdmi -gccext,on -msgstyle gcc -Iinclude'])
            res = subprocess.run(cmd, capture_output=True, text=True)
            stdout = res.stdout

            is_match = ('MATCHING VERSIONS: dsi/1.3' in stdout or ('MATCHING VERSIONS:' in stdout and 'none' not in stdout))

            if not is_match:
                # If symbol not found, try adding extern "C" temporarily
                if 'symbol' in stdout and 'not found' in stdout and 'extern "C"' not in content:
                    temp_content = f'//cpp\nextern "C" {{\n{content}\n}}\n'
                    with open(path, 'w') as fp: fp.write(temp_content)
                    res = subprocess.run(cmd, capture_output=True, text=True)
                    stdout = res.stdout
                    is_match = ('MATCHING VERSIONS: dsi/1.3' in stdout or ('MATCHING VERSIONS:' in stdout and 'none' not in stdout))
                    if not is_match:
                        # Revert temp content
                        with open(path, 'w') as fp: fp.write(content)

            if not is_match:
                file_is_100_percent_matched = False
                break

        if file_is_100_percent_matched:
            # Promote matched file from drafts/ to src/ via git mv!
            dst_path = os.path.join(target_src_dir, fname)
            os.makedirs(target_src_dir, exist_ok=True)
            res_mv = subprocess.run(['git', 'mv', path, dst_path], capture_output=True)
            if res_mv.returncode != 0:
                os.rename(path, dst_path)
            matched_count += 1
            promoted_files.append((fname, dst_path))
            print(f"  [100% MATCH PROMOTED TO SRC] {fname} -> {dst_path}")

print(f"\n================ Matching Sweep Summary ================")
print(f"Total Draft Files Promoted to src/: {matched_count}")
print("========================================================\n")

if matched_count > 0:
    subprocess.run([sys.executable, 'configure.py'], check=True)
    print("Re-ran configure.py successfully!")
