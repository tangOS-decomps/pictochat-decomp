import os, sys, json, subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

# Load classification JSON
with open(r'config\arm9\classified_symbols.json', 'r') as f:
    classified_syms = json.load(f)

# Load unk_autoload_0 binary for signature matching
with open(r'extracted\dsd\arm9\unk_autoload_0.bin', 'rb') as f:
    autoload_data = f.read()

base_addr = 0x02320000
md_thumb = Cs(CS_ARCH_ARM, CS_MODE_THUMB)

rename_map = {}

for s in classified_syms:
    if s['category'] != 'MSL': continue
    addr = s['addr']
    size = s['size']
    old_name = s['name']
    offset = addr - base_addr

    # Known specific functions
    if addr == 0x02332e70:
        new_name = 'memset'
    elif 'memset' in old_name:
        new_name = 'memset'
    elif 'memcpy' in old_name:
        new_name = 'memcpy'
    else:
        # Standardized MSL prefix naming for illegible FUN_0233XXXX symbols
        if old_name.startswith('FUN_0233') or old_name.startswith('FUN_0234'):
            new_name = f"MSL_{old_name[4:]}"
        else:
            new_name = old_name

    rename_map[old_name] = new_name
    s['name'] = new_name

print(f"Renaming {len(rename_map)} MSL functions to legible MSL namespace...")

# 1. Update config/arm9/symbols.txt
syms_file = r'config\arm9\symbols.txt'
with open(syms_file, 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    if line.startswith('name='):
        parts = dict(p.split('=', 1) for p in line.strip().split() if '=' in p)
        old_n = parts.get('name', '')
        if old_n in rename_map:
            line = line.replace(f"name={old_n}", f"name={rename_map[old_n]}")
    new_lines.append(line)

with open(syms_file, 'w') as f:
    f.writelines(new_lines)
print(f"Updated {syms_file}")

# 2. Update config/arm9/classified_symbols.json
with open(r'config\arm9\classified_symbols.json', 'w') as f:
    json.dump(classified_syms, f, indent=2)
print("Updated config/arm9/classified_symbols.json")

# 3. Rename any matching .cpp files in src/arm9
src_dir = r'src\arm9'
renamed_files = 0
for old_n, new_n in rename_map.items():
    if old_n == new_n: continue
    # Search for files starting with old_n
    for f in os.listdir(src_dir):
        if f.startswith(old_n + '.') or f.startswith(old_n + '_') or f == f"{old_n}.cpp":
            old_path = os.path.join(src_dir, f)
            new_fname = f.replace(old_n, new_n)
            new_path = os.path.join(src_dir, new_fname)
            try:
                subprocess.run(['git', 'mv', old_path, new_path], check=True)
                renamed_files += 1
                print(f"  git mv {f} -> {new_fname}")
            except Exception as e:
                print(f"  Error moving {f}: {e}")

print(f"Renamed {renamed_files} source files in src/arm9/")

# 4. Regenerate build.ninja
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Re-ran configure.py successfully!")
