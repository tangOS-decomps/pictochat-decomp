import os, json, re, subprocess, sys

syms_file = r'config\arm7\symbols.txt'
classified_file = r'config\arm7\classified_symbols.json'

updates = {
    'FUN_022d08a8': '0x14',
    'FUN_022d811c': '0x1c',
    'FUN_022d8138': '0x34',
    'FUN_022d816c': '0x4c'
}

print("Updating ARM7 symbol sizes in symbols.txt & classified_symbols.json...\n")

if os.path.exists(syms_file):
    with open(syms_file, 'r') as f: lines = f.readlines()
    new_lines = []
    for line in lines:
        for fname, new_size in updates.items():
            if f"name={fname} " in line:
                line = re.sub(r'size=0x[0-9a-fA-F]+', f'size={new_size}', line)
        new_lines.append(line)
    with open(syms_file, 'w') as f: f.writelines(new_lines)

if os.path.exists(classified_file):
    with open(classified_file, 'r') as f: classified_data = json.load(f)
    for s in classified_data:
        if s['name'] in updates:
            s['size'] = updates[s['name']]
    with open(classified_file, 'w') as f: json.dump(classified_data, f, indent=2)

print("Updated ARM7 symbol sizes successfully!")
