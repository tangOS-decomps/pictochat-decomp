import json, re, subprocess, sys, os

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

updates = {
    '_ZN4CP159EnableMPUEv': '0x10',
    '_ZN4CP1510DisableMPUEv': '0x10',
    '_ZN4CP1514FlushDataCacheEv': '0x2c',
    '_ZN4CP1514FlushDataCacheEjj': '0x1c',
    '_ZN4CP1516DrainWriteBufferEv': '0xc',
    '_ZN4CP1516WaitForInterruptEv': '0xc',
    '_ZN4CP1519InvalidateDataCacheEjj': '0x1c'
}

print("Updating CP15 symbol sizes in symbols.txt & classified_symbols.json...\n")

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

print("Updated symbol sizes successfully!")
