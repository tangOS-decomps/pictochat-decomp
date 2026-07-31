import os

files = [
    'FUN_02328ce4.cpp', 'FUN_02328d60.cpp', 'FUN_02328d80.cpp', 'FUN_02328e04.cpp'
]

print("=== INSPECTING PICTOCHAT AUDIO & SOUND MANAGER CLUSTER ===\n")

for f in files:
    fpath = os.path.join('drafts/arm9', f)
    if os.path.exists(fpath):
        with open(fpath, 'r') as fp: content = fp.read().strip()
        print(f"=== {f} ===")
        print(content)
        print("-" * 50)
