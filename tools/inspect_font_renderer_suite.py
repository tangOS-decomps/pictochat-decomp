import os

files = [
    'FUN_02320c44.cpp', 'FUN_02320e14.cpp', 'FUN_02320e3c.cpp', 'FUN_02320e60.cpp',
    'FUN_02320e88.cpp', 'FUN_02320eac.cpp', 'FUN_02320ed4.cpp', 'FUN_02320f00.cpp',
    'FUN_02320f24.cpp', 'FUN_02320f4c.cpp', 'FUN_02320f74.cpp'
]

print("=== INSPECTING FONT RENDERER MASTER TEXT OVERLOAD SUITE ===\n")

for f in files:
    fpath = os.path.join('drafts/arm9', f)
    if os.path.exists(fpath):
        with open(fpath, 'r') as fp: content = fp.read().strip()
        print(f"=== {f} ===")
        print(content)
        print("-" * 50)
