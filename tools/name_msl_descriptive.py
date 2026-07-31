import os, sys, json, struct, subprocess
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

# Load classified symbols
with open(r'config\arm9\classified_symbols.json', 'r') as f:
    classified_syms = json.load(f)

# Load unk_autoload_0 binary
with open(r'extracted\dsd\arm9\unk_autoload_0.bin', 'rb') as f:
    autoload_data = f.read()

base_addr = 0x02320000
md_thumb = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
md_arm = Cs(CS_ARCH_ARM, CS_MODE_ARM)

rename_map = {}

for s in classified_syms:
    if s['category'] != 'MSL': continue
    addr = s['addr']
    size = s['size']
    old_name = s['name']
    offset = addr - base_addr
    addr_hex = hex(addr)[2:].zfill(8)

    if offset < 0 or offset + size > len(autoload_data):
        rename_map[old_name] = old_name
        continue

    code = autoload_data[offset:offset+size]
    dis = list(md_thumb.disasm(code, addr))
    if not dis: dis = list(md_arm.disasm(code, addr))

    insns = [(i.mnemonic.lower(), i.op_str.lower()) for i in dis]
    text = ' '.join(f"{m} {o}" for m, o in insns)

    # Descriptive Naming Rules
    if addr == 0x02332e70 or old_name == 'memset':
        new_name = 'memset'
    elif 'ldmia' in text and 'stmia' in text and size in [0x3c, 0x40, 0x48, 0x50]:
        new_name = f'memcpy_{addr_hex}'
    elif 'ldrb' in text and 'cmp' in text and 'beq' in text and size in [0x14, 0x18, 0x1c, 0x20] and 'add' in text:
        new_name = f'strlen_{addr_hex}'
    elif 'ldrb' in text and 'sub' in text and size in [0x18, 0x1c, 0x20, 0x24] and 'cmp' in text:
        new_name = f'strcmp_{addr_hex}'
    elif 'ldrb' in text and 'strb' in text and 'beq' in text and size in [0x14, 0x18, 0x1c, 0x20]:
        new_name = f'strcpy_{addr_hex}'
    elif 'lsrs' in text and 'subs' in text and 'bne' in text and size < 0x50:
        if 'r0, r1' in text or 'r1, r0' in text:
            new_name = f'__aeabi_uidivmod_{addr_hex}'
        else:
            new_name = f'__aeabi_idivmod_{addr_hex}'
    elif 'push {r4, r5, r6, r7, lr}' in text or 'push {r4, r5, r6, lr}' in text:
        if 'bl' in text and size > 0x100:
            new_name = f'msl_formatted_io_{addr_hex}'
        else:
            new_name = f'msl_helper_{addr_hex}'
    elif 'pop {r4, r5, pc}' in text or 'pop {r4, r5, r6, pc}' in text:
        new_name = f'msl_string_util_{addr_hex}'
    elif size <= 0x10 and ('bx lr' in text or 'pop {pc}' in text):
        new_name = f'msl_stub_{addr_hex}'
    else:
        new_name = f'msl_runtime_{addr_hex}'

    rename_map[old_name] = new_name
    s['name'] = new_name

print(f"Applying descriptive MSL names for {len(rename_map)} functions...")

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
