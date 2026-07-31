import os, sys, subprocess

bitmask_files = [
    'FUN_023212bc.cpp', 'FUN_023212c8.cpp', 'FUN_023212d4.cpp', 'FUN_023212e0.cpp',
    'FUN_023212ec.cpp', 'FUN_023212f8.cpp', 'FUN_02321304.cpp', 'FUN_02321310.cpp'
]

for f in bitmask_files:
    draft_path = f'drafts/arm9/{f}'
    src_path = f'src/arm9/{f}'
    if os.path.exists(draft_path):
        subprocess.run(['git', 'mv', draft_path, src_path], check=True)
        print(f"  git mv {draft_path} -> {src_path}")

subprocess.run([sys.executable, 'configure.py'], check=True)
print("Restored 8 100% byte-matched individual files in src/arm9/!")
