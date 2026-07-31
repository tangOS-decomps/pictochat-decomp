import os

svc_files = {
    'SVC_WaitByLoop.cpp': ('0x02332d10', '0x3'),
    'SVC_CpuSet.cpp': ('0x02332d2e', '0xb'),
    'SVC_FastCopy.cpp': ('0x02332d32', '0xc'),
    'SVC_GetCRC16.cpp': ('0x02332d3a', '0xe'),
    'SVC_IsDebuggerPresent.cpp': ('0x02332d42', '0x10'),
    'SVC_CustomCall.cpp': ('0x02332d4e', '0x13'),
}

for fname, (addr, num) in svc_files.items():
    code = f"""// decomp: module=unk_autoload_0 addr={addr} name={fname[:-4]}
extern "C" asm void {fname[:-4]}(void) {{
    swi {num}
    bx lr
}}
"""
    fpath = os.path.join('drafts/arm9', fname)
    with open(fpath, 'w') as f: f.write(code)
    print(f"Created {fpath}")

# Format VRAM_GetEngineBBaseAddr.cpp
vram_code = """// decomp: module=unk_autoload_0 addr=0x02336710 name=VRAM_GetEngineBBaseAddr
extern "C" int VRAM_GetEngineBBaseAddr(void) {
    unsigned short val = *(unsigned short *)0x0400100a;
    int field = (val & 0x3c) >> 2;
    return (field << 14) + 0x06200000;
}
"""
with open('drafts/arm9/VRAM_GetEngineBBaseAddr.cpp', 'w') as f: f.write(vram_code)
print("Created drafts/arm9/VRAM_GetEngineBBaseAddr.cpp")

# Clean up multi-function container files if present
for old_f in ['SVC.cpp', 'VRAM.cpp']:
    old_p = os.path.join('drafts/arm9', old_f)
    if os.path.exists(old_p): os.remove(old_p)
