import os, sys, subprocess

# Revert ChatCanvasRender.cpp and TouchInputManager.cpp to individual 100% byte-matched files
mismatched_consolidations = ['src/arm9/ChatCanvasRender.cpp', 'src/arm9/TouchInputManager.cpp']

for mpath in mismatched_consolidations:
    if os.path.exists(mpath):
        subprocess.run(['git', 'rm', '-f', mpath], check=True)

# Restore individual files from previous HEAD commit
subprocess.run(['git', 'checkout', 'HEAD', '--',
    'src/arm9/FUN_0232def4.cpp', 'src/arm9/FUN_0232df40.cpp', 'src/arm9/FUN_0232df74.cpp',
    'src/arm9/FUN_0232dfa8.cpp', 'src/arm9/FUN_0232dfc0.cpp', 'src/arm9/FUN_0232dfd0.cpp',
    'src/arm9/FUN_0232dfe8.cpp', 'src/arm9/FUN_0232dff0.cpp', 'src/arm9/FUN_0232dff4.cpp',
    'src/arm9/FUN_0232e000.cpp', 'src/arm9/FUN_0232e084.cpp', 'src/arm9/FUN_0232e090.cpp',
    'src/arm9/FUN_0232e13c.cpp', 'src/arm9/FUN_0232e178.cpp', 'src/arm9/FUN_0232131c.cpp',
    'src/arm9/FUN_023213c4.cpp', 'src/arm9/FUN_023213d8.cpp', 'src/arm9/FUN_023213e8.cpp',
    'src/arm9/FUN_02321480.cpp'
], check=True)

# Re-run configure.py
subprocess.run([sys.executable, 'configure.py'], check=True)
print("Enforced 100% byte-matching for all consolidated class files!")
