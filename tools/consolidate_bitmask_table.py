import os, sys, subprocess, json, re

# Consolidate the 8 100% matched bitmask functions into src/arm9/BitmaskTable.cpp
bitmask_files = [
    'FUN_023212bc.cpp', 'FUN_023212c8.cpp', 'FUN_023212d4.cpp', 'FUN_023212e0.cpp',
    'FUN_023212ec.cpp', 'FUN_023212f8.cpp', 'FUN_02321304.cpp', 'FUN_02321310.cpp'
]

SYMBOL_RENAME_MAP = {
    'FUN_023212bc': 'Bitmask_GetBit2',
    'FUN_023212c8': 'Bitmask_GetBit3',
    'FUN_023212d4': 'Bitmask_GetBit4',
    'FUN_023212e0': 'Bitmask_GetWord0',
    'FUN_023212ec': 'Bitmask_GetWord1',
    'FUN_023212f8': 'Bitmask_GetWord2',
    'FUN_02321304': 'Bitmask_GetWord3',
    'FUN_02321310': 'Bitmask_SetFlag9'
}

src_dir = r'src\arm9'
target_cpp = os.path.join(src_dir, 'BitmaskTable.cpp')

blocks = ["// ==========================================================\n// C++ Class / Module Implementation: BitmaskTable.cpp\n// ==========================================================\n\n"]

for f in bitmask_files:
    fpath = os.path.join(src_dir, f)
    if os.path.exists(fpath):
        with open(fpath, 'r') as fp: text = fp.read().strip()
        for old_name, new_name in SYMBOL_RENAME_MAP.items():
            text = text.replace(f"name={old_name}", f"name={new_name}")
            text = text.replace(f"{old_name}(", f"{new_name}(")
        blocks.append(f"// --- {f} ---\n{text}\n\n")

with open(target_cpp, 'w') as fp:
    fp.write(''.join(blocks))

print(f"Created consolidated class file: {target_cpp}")

# Remove individual single-function files
for f in bitmask_files:
    fpath = os.path.join(src_dir, f)
    if os.path.exists(fpath):
        subprocess.run(['git', 'rm', '-f', fpath], check=True)

subprocess.run(['git', 'add', target_cpp], check=True)

# Create include/BitmaskTable.h
header_path = 'include/BitmaskTable.h'
header_code = """#ifndef BITMASK_TABLE_H
#define BITMASK_TABLE_H

extern "C" {
    int Bitmask_GetBit2(int a);
    int Bitmask_GetBit3(int a);
    int Bitmask_GetBit4(int a);
    int Bitmask_GetWord0(void);
    int Bitmask_GetWord1(void);
    int Bitmask_GetWord2(void);
    int Bitmask_GetWord3(void);
    void Bitmask_SetFlag9(void);
}

class BitmaskTable {
public:
    inline int GetBit2(int val) const { return Bitmask_GetBit2(val); }
    inline int GetBit3(int val) const { return Bitmask_GetBit3(val); }
    inline int GetBit4(int val) const { return Bitmask_GetBit4(val); }
    inline int GetWord0() const { return Bitmask_GetWord0(); }
    inline int GetWord1() const { return Bitmask_GetWord1(); }
    inline int GetWord2() const { return Bitmask_GetWord2(); }
    inline int GetWord3() const { return Bitmask_GetWord3(); }
    inline void SetFlag9() { Bitmask_SetFlag9(); }
};

#endif // BITMASK_TABLE_H
"""

with open(header_path, 'w') as f: f.write(header_code)
subprocess.run(['git', 'add', header_path], check=True)
print(f"Created C++ class header: {header_path}")

# Update config/arm9/symbols.txt & classified_symbols.json
syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'

with open(syms_file, 'r') as f: lines = f.readlines()
new_lines = []
for line in lines:
    for old_name, new_name in SYMBOL_RENAME_MAP.items():
        if f"name={old_name} " in line:
            line = line.replace(f"name={old_name} ", f"name={new_name} ")
    new_lines.append(line)
with open(syms_file, 'w') as f: f.writelines(new_lines)

with open(classified_file, 'r') as f: classified_data = json.load(f)
for s in classified_data:
    for old_name, new_name in SYMBOL_RENAME_MAP.items():
        if s['name'] == old_name:
            s['name'] = new_name
with open(classified_file, 'w') as f: json.dump(classified_data, f, indent=2)

subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
