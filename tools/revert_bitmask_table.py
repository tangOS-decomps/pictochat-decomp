import os, sys, subprocess

# Revert BitmaskTable.cpp to individual 100% byte-matched files in src/arm9/
if os.path.exists('src/arm9/BitmaskTable.cpp'):
    subprocess.run(['git', 'rm', '-f', 'src/arm9/BitmaskTable.cpp'], check=True)

# Restore individual files from HEAD commit
bitmask_files = [
    'FUN_023212bc.cpp', 'FUN_023212c8.cpp', 'FUN_023212d4.cpp', 'FUN_023212e0.cpp',
    'FUN_023212ec.cpp', 'FUN_023212f8.cpp', 'FUN_02321304.cpp', 'FUN_02321310.cpp'
]

for f in bitmask_files:
    path = f'src/arm9/{f}'
    subprocess.run(['git', 'checkout', 'HEAD', '--', path], check=True)

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Reverted to individual 100% byte-matched files in src/arm9/!")
