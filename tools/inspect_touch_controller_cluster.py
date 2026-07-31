import os

files = [
    'FUN_02321d14.cpp', 'FUN_02321df4.cpp', 'FUN_02321f9c.cpp',
    'FUN_02321fbc.cpp', 'FUN_02321fd4.cpp', 'FUN_02321fe0.cpp', 'FUN_02321fec.cpp'
]

print("=== INSPECTING TOUCH CONTROLLER CLUSTER FILES ===\n")

for f in files:
    fpath = os.path.join('drafts/arm9', f)
    if os.path.exists(fpath):
        with open(fpath, 'r') as fp: content = fp.read().strip()
        print(f"=== {f} ===")
        print(content)
        print("-" * 50)
