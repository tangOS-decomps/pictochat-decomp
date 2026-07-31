import os, subprocess, re

src_dir = r'src\arm9'
files_to_fix = [
    'VRAM.cpp', 'EXMEM.cpp', 'PacketHeader.cpp', 'SVC.cpp',
    'ChatContext.cpp', 'memchr.cpp', 'memcmp.cpp', 'memcpy_bytes.cpp',
    'strlen_s8.cpp', 'wcslen.cpp', 'SafeStoreByte.cpp', 'SetGlobalStateByte.cpp'
]

for fname in files_to_fix:
    path = os.path.join(src_dir, fname)
    if not os.path.exists(path): continue

    with open(path, 'r') as f:
        content = f.read()

    # Wrap function definitions in extern "C" if not already wrapped
    if 'extern "C"' not in content and 'asm void' not in content:
        # Wrap entire body or function header
        content = f'//cpp\nextern "C" {{\n{content}\n}}\n'
    elif 'asm void' in content and 'extern "C"' not in content:
        content = content.replace('asm void', 'extern "C" asm void')

    with open(path, 'w') as f:
        f.write(content)

print("Added extern 'C' to C-style detangled files.")

# Re-run configure.py
subprocess.run(['python', 'configure.py'], check=True)
