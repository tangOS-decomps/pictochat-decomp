import os

files = [
    'FUN_02321c58.cpp', 'FUN_02321c60.cpp', 'FUN_02321c68.cpp', 'FUN_02321cf8.cpp',
    'FUN_02321d04.cpp', 'FUN_02321d10.cpp', 'FUN_02321d1c.cpp', 'FUN_02321d28.cpp',
    'FUN_02321d34.cpp', 'FUN_02321d40.cpp', 'FUN_02321d4c.cpp'
]

print("=== INSPECTING TOUCH CANVAS & INPUT CONTROLLER CLUSTER ===\n")

for f in files:
    fpath = os.path.join('drafts/arm9', f)
    if os.path.exists(fpath):
        with open(fpath, 'r') as fp: content = fp.read().strip()
        print(f"=== {f} ===")
        print(content)
        print("-" * 50)
