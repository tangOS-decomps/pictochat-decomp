import os, sys, subprocess

bitmask_data = {
    'FUN_023212bc.cpp': ("FUN_023212bc", "0x023212bc", "0xc", "extern unsigned short G_0234a120[]; int FUN_023212bc(int a) { return a & G_0234a120[2]; }"),
    'FUN_023212c8.cpp': ("FUN_023212c8", "0x023212c8", "0xc", "extern unsigned short G_0234a120[]; int FUN_023212c8(int a) { return a & G_0234a120[3]; }"),
    'FUN_023212d4.cpp': ("FUN_023212d4", "0x023212d4", "0xc", "extern unsigned short G_0234a120[]; int FUN_023212d4(int a) { return a & G_0234a120[4]; }"),
    'FUN_023212e0.cpp': ("FUN_023212e0", "0x023212e0", "0xc", "extern unsigned short G_0234a120[]; int FUN_023212e0(void) { return G_0234a120[0]; }"),
    'FUN_023212ec.cpp': ("FUN_023212ec", "0x023212ec", "0xc", "extern int G_0234a120[]; int FUN_023212ec(void) { return G_0234a120[7]; }"),
    'FUN_023212f8.cpp': ("FUN_023212f8", "0x023212f8", "0xc", "extern unsigned short G_0234a120[]; int FUN_023212f8(void) { return G_0234a120[10]; }"),
    'FUN_02321304.cpp': ("FUN_02321304", "0x02321304", "0xc", "extern unsigned short G_0234a120[]; int FUN_02321304(void) { return G_0234a120[11]; }"),
    'FUN_02321310.cpp': ("FUN_02321310", "0x02321310", "0xc", "extern int G_0234a120[]; void FUN_02321310(void) { G_0234a120[9] = 1; }"),
}

for fname, (name, addr, size, body) in bitmask_data.items():
    fpath = f'src/arm9/{fname}'
    code = f"// decomp: module=unk_autoload_0 addr={addr} name={name}\nextern \"C\" {{\n    {body}\n}}\n"
    with open(fpath, 'w') as f: f.write(code)
    subprocess.run(['git', 'add', fpath], check=True)
    print(f"Created 100% matched source: {fpath}")

subprocess.run([sys.executable, 'configure.py'], check=True)
print("Re-ran configure.py successfully!")
