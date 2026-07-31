import os, sys, subprocess, re

cluster_files = [
    ('drafts/arm9/FUN_023209ec.cpp', 'FUN_023209ec', '0x023209ec', '0xa'),
    ('drafts/arm9/FUN_02320a00.cpp', 'FUN_02320a00', '0x02320a00', '0x8'),
    ('drafts/arm9/FUN_02320a0c.cpp', 'FUN_02320a0c', '0x02320a0c', '0x10'),
    ('drafts/arm9/FUN_02320b80.cpp', 'FUN_02320b80', '0x02320b80', '0x12'),
    ('drafts/arm9/FUN_02321198.cpp', 'FUN_02321198', '0x02321198', '0x14'),
    ('drafts/arm9/FUN_023212bc.cpp', 'FUN_023212bc', '0x023212bc', '0x8'),
    ('drafts/arm9/FUN_023212c8.cpp', 'FUN_023212c8', '0x023212c8', '0x8'),
    ('drafts/arm9/FUN_023212d4.cpp', 'FUN_023212d4', '0x023212d4', '0x8'),
]

print("=== STRICT BYTE-MATCH SWEEP FOR TEXT ENGINE CLUSTER ===\n")

for fpath, func, addr, size in cluster_files:
    if not os.path.exists(fpath): continue

    cmd = [
        sys.executable, 'tools/match.py',
        '--c', fpath,
        '--func', func,
        '--addr', addr,
        '--size', size,
        '--module', 'unk_autoload_0'
    ]
    res = subprocess.run(cmd, capture_output=True, text=True)
    is_match = ('MATCHING VERSIONS: dsi/1.3' in res.stdout or 'MATCHING VERSIONS: 1.' in res.stdout) and 'none' not in res.stdout

    if is_match:
        print(f"  [100% BYTE MATCH] {func} ({fpath})")
    else:
        print(f"  [NOT MATCHED    ] {func} ({fpath})")
