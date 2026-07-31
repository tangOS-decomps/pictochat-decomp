import os, sys, subprocess, json

# Exact map of old symbol names to sane, descriptive functional names
SYMBOL_RENAME_MAP = {
    # StringUtils
    'FUN_02332e70': 'memset',

    # TextLayoutEngine
    'FUN_02329628': 'TextLayout_DrawText',
    'FUN_02329634': 'TextLayout_DrawGlyph',
    'FUN_02329640': 'TextLayout_SetFont',
    'FUN_02329650': 'TextLayout_SetSpacing',
    'FUN_0232965c': 'TextLayout_SetLineHeight',

    # PaletteColorEngine
    'FUN_0232517c': 'Palette_InitBounds',
    'FUN_0232519c': 'Palette_StepAnimation',
    'FUN_023251c4': 'Palette_ResetState',
    'FUN_023251e4': 'Palette_GetActiveColor',

    # WirelessProtocolDispatch
    'FUN_02330558': 'Wireless_GetActivePeerSlot',
    'FUN_02330584': 'Wireless_ResetState',
    'FUN_023305c8': 'Wireless_IncrementSequenceNumber',
    'FUN_023305d8': 'Wireless_IsSequenceComplete',
}

syms_file = r'config\arm9\symbols.txt'
classified_file = r'config\arm9\classified_symbols.json'
src_dir = r'src\arm9'

print("Applying sane functional names and C++ class method structures...\n")

# 1. Update config/arm9/symbols.txt
with open(syms_file, 'r') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    for old_name, new_name in SYMBOL_RENAME_MAP.items():
        if f"name={old_name} " in line:
            line = line.replace(f"name={old_name} ", f"name={new_name} ")
    new_lines.append(line)

with open(syms_file, 'w') as f:
    f.writelines(new_lines)
print(f"Updated {syms_file}")

# 2. Update config/arm9/classified_symbols.json
with open(classified_file, 'r') as f:
    classified_data = json.load(f)

for s in classified_data:
    for old_name, new_name in SYMBOL_RENAME_MAP.items():
        if s['name'] == old_name:
            s['name'] = new_name

with open(classified_file, 'w') as f:
    json.dump(classified_data, f, indent=2)
print(f"Updated {classified_file}")

# 3. Update C++ source files in src/arm9
class_files = [
    'StringUtils.cpp', 'TextLayoutEngine.cpp',
    'PaletteColorEngine.cpp', 'WirelessProtocolDispatch.cpp'
]

for class_fname in class_files:
    fpath = os.path.join(src_dir, class_fname)
    if not os.path.exists(fpath): continue

    with open(fpath, 'r') as f:
        content = f.read()

    for old_name, new_name in SYMBOL_RENAME_MAP.items():
        content = content.replace(f"name={old_name}", f"name={new_name}")
        content = content.replace(f"{old_name}(", f"{new_name}(")

    with open(fpath, 'w') as f:
        f.write(content)

    print(f"Updated source file: {fpath}")

# 4. Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
