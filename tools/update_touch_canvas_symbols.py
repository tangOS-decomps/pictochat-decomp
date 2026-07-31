import json, re, subprocess, sys

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

updates = {
    'FUN_02321c58': '0x8',
    'FUN_02321c60': '0x8',
    'FUN_02321c68': '0x8',
    'FUN_02321cf8': '0xc',
    'FUN_02321d04': '0x10',
    'FUN_02321fd4': '0xc',
    'FUN_02321fe0': '0xc',
    'FUN_02321fec': '0x18'
}

print("Updating touch canvas symbol sizes in symbols.txt & classified_symbols.json...\n")

with open(syms_file, 'r') as f: lines = f.readlines()
new_lines = []
for line in lines:
    for fname, new_size in updates.items():
        if f"name={fname} " in line:
            line = re.sub(r'size=0x[0-9a-fA-F]+', f'size={new_size}', line)
    new_lines.append(line)
with open(syms_file, 'w') as f: f.writelines(new_lines)

with open(classified_file, 'r') as f: classified_data = json.load(f)
for s in classified_data:
    if s['name'] in updates:
        s['size'] = updates[s['name']]
with open(classified_file, 'w') as f: json.dump(classified_data, f, indent=2)

print("Updated symbol sizes successfully!")
