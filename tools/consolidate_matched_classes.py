import os, sys, subprocess, re

CLASS_MAPPINGS = {
    'StringUtils.cpp': [
        'memset.cpp', 'memchr.cpp', 'memcmp.cpp', 'memcpy_bytes.cpp',
        'strlen_s8.cpp', 'wcslen.cpp', 'SafeStoreByte.cpp'
    ],
    'ChatCanvasRender.cpp': [
        'FUN_0232def4.cpp', 'FUN_0232df40.cpp', 'FUN_0232df74.cpp', 'FUN_0232dfa8.cpp',
        'FUN_0232dfc0.cpp', 'FUN_0232dfd0.cpp', 'FUN_0232dfe8.cpp', 'FUN_0232dff0.cpp',
        'FUN_0232dff4.cpp', 'FUN_0232e000.cpp', 'FUN_0232e084.cpp', 'FUN_0232e090.cpp',
        'FUN_0232e13c.cpp', 'FUN_0232e178.cpp'
    ],
    'TouchInputManager.cpp': [
        'FUN_0232131c.cpp', 'FUN_023213c4.cpp', 'FUN_023213d8.cpp', 'FUN_023213e8.cpp', 'FUN_02321480.cpp'
    ],
    'TextLayoutEngine.cpp': [
        'FUN_02329628.cpp', 'FUN_02329634.cpp', 'FUN_02329640.cpp', 'FUN_02329650.cpp', 'FUN_0232965c.cpp'
    ],
    'PaletteColorEngine.cpp': [
        'FUN_0232517c.cpp', 'FUN_0232519c.cpp', 'FUN_023251c4.cpp', 'FUN_023251e4.cpp'
    ],
    'WirelessProtocolDispatch.cpp': [
        'FUN_02330558.cpp', 'FUN_02330584.cpp', 'FUN_023305c8.cpp', 'FUN_023305d8.cpp'
    ]
}

src_dir = r'src\arm9'

print("Consolidating 100% matched single-function files into unified C++ class files...\n")

for class_fname, member_files in CLASS_MAPPINGS.items():
    existing_files = [f for f in member_files if os.path.exists(os.path.join(src_dir, f))]
    if not existing_files: continue

    target_path = os.path.join(src_dir, class_fname)
    blocks = [f"// ==========================================================\n// C++ Class / Module Implementation: {class_fname}\n// ==========================================================\n\n"]

    for f in existing_files:
        fpath = os.path.join(src_dir, f)
        with open(fpath, 'r') as fp:
            text = fp.read().strip()
        blocks.append(f"// --- {f} ---\n{text}\n\n")

    with open(target_path, 'w') as fp:
        fp.write(''.join(blocks))

    print(f"Created unified class file: src/arm9/{class_fname} ({len(existing_files)} methods)")

    # Remove individual files
    for f in existing_files:
        fpath = os.path.join(src_dir, f)
        subprocess.run(['git', 'rm', '-f', fpath], check=True)

    subprocess.run(['git', 'add', target_path], check=True)

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("\nRe-ran configure.py successfully!")
