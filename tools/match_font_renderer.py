import os, sys, subprocess, re

font_files = [
    ('drafts/arm9/FUN_02320e14.cpp', '0x02320e14', '0x1e'),
    ('drafts/arm9/FUN_02320e3c.cpp', '0x02320e3c', '0x1a'),
    ('drafts/arm9/FUN_02320e60.cpp', '0x02320e60', '0x1e'),
    ('drafts/arm9/FUN_02320e88.cpp', '0x02320e88', '0x1a'),
    ('drafts/arm9/FUN_02320eac.cpp', '0x02320eac', '0x1e'),
    ('drafts/arm9/FUN_02320ed4.cpp', '0x02320ed4', '0x1a'),
    ('drafts/arm9/FUN_02320f00.cpp', '0x02320f00', '0x1e'),
    ('drafts/arm9/FUN_02320f24.cpp', '0x02320f24', '0x1a'),
    ('drafts/arm9/FUN_02320f4c.cpp', '0x02320f4c', '0x1e'),
    ('drafts/arm9/FUN_02320f74.cpp', '0x02320f74', '0x1a'),
]

print("=== FontRenderer (PictoChat Core Text Engine) Matching Sweep ===\n")

for fpath, addr, size in font_files:
    if not os.path.exists(fpath): continue
    with open(fpath, 'r') as fp: content = fp.read()

    # Compile with mwccarm to find mangled symbol
    mwcc_cmd = [
        r'tools\mwccarm\dsi\1.3\mwccarm.exe',
        '-O4,p', '-enum', 'int', '-lang', 'c++', '-char', 'signed',
        '-interworking', '-thumb', '-proc', 'arm946e', '-gccext,on',
        '-msgstyle', 'gcc', '-Iinclude', '-c', fpath,
        '-o', 'scratch/temp.o'
    ]
    subprocess.run(mwcc_cmd, capture_output=True)

    mangled = None
    if os.path.exists('scratch/temp.o'):
        with open('scratch/temp.o', 'rb') as f: data = f.read()
        syms = re.findall(r'_ZN\w+', data.decode('latin1', errors='ignore'))
        if syms: mangled = syms[0]

    if not mangled: mangled = os.path.basename(fpath).replace('.cpp', '')

    cmd = [
        sys.executable, 'tools/match.py',
        '--c', fpath,
        '--func', mangled,
        '--addr', addr,
        '--size', size,
        '--module', 'unk_autoload_0'
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    is_match = ('MATCHING VERSIONS: dsi/1.3' in res.stdout or 'MATCHING VERSIONS: 1.' in res.stdout) and 'none' not in res.stdout

    if is_match:
        print(f"  [100% BYTE MATCH] {fpath} ({mangled} @ {addr})")
    else:
        print(f"  [NOT MATCHED    ] {fpath} ({mangled} @ {addr})")
