import json, re, subprocess, sys

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

funcs_to_update = [
    'FUN_023212bc', 'FUN_023212c8', 'FUN_023212d4', 'FUN_023212e0',
    'FUN_023212ec', 'FUN_023212f8', 'FUN_02321304', 'FUN_02321310'
]

print("Updating symbol sizes to 0xc in symbols.txt & classified_symbols.json...\n")

with open(syms_file, 'r') as f: lines = f.readlines()
new_lines = []
for line in lines:
    for fname in funcs_to_update:
        if f"name={fname} " in line:
            line = re.sub(r'size=0x[0-9a-fA-F]+', 'size=0xc', line)
    new_lines.append(line)
with open(syms_file, 'w') as f: f.writelines(new_lines)

with open(classified_file, 'r') as f: classified_data = json.load(f)
for s in classified_data:
    if s['name'] in funcs_to_update:
        s['size'] = '0xc'
with open(classified_file, 'w') as f: json.dump(classified_data, f, indent=2)

print("Updated config files successfully!")
