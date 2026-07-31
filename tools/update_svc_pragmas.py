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
#pragma thumb on
extern "C" asm void {fname[:-4]}(void) {{
    swi {num}
    bx lr
}}
"""
    fpath = os.path.join('drafts/arm9', fname)
    with open(fpath, 'w') as f: f.write(code)
    print(f"Updated {fpath}")
