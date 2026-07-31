import os, json, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_ARM

SDK_PREFIXES = [
    'OS_', 'FS_', 'GX_', 'G3_', 'G2_', 'MI_', 'SND_', 'CARD_', 'RTC_', 'PAD_',
    'WM_', 'WVR_', 'MB_', 'CTRDG_', 'MATH_', 'FX_', 'CP_', 'PXI_', 'PM_', 'THP_',
    'SPI_', 'DWC_', 'NNS_', 'SDK_'
]

MSL_NAMES = [
    'memset', 'memcpy', 'memmove', 'memcmp', 'strcpy', 'strncpy', 'strlen',
    'strcmp', 'strncmp', 'sprintf', 'vsprintf', 'snprintf', 'malloc', 'free',
    'calloc', 'realloc', '__destroy_arr', '__register_global_object', '__construct_array',
    '__destroy_global_chain', '__aeabi_idiv', '__aeabi_uidiv', '__aeabi_idivmod',
    '__aeabi_uidivmod', '__aeabi_memcpy', '__aeabi_memclr', '__aeabi_memset',
    '__sfp_exception', '__std_alloc', '__std_free', 'abort', 'exit'
]

MODULE_MAP = {
    'itcm': (0x01ff8000, r'extracted\dsd\arm9\itcm.bin'),
    'main': (0x02000c00, r'extracted\dsd\arm9\arm9.bin'),
    'unk_autoload_0': (0x02320000, r'extracted\dsd\arm9\unk_autoload_0.bin'),
    'unk_autoload_2': (0x0236a140, r'extracted\dsd\arm9\unk_autoload_2.bin'),
}

def load_symbols():
    syms = []
    symfile = r'config\arm9\symbols.txt'
    with open(symfile, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'): continue
            parts = dict(p.split('=', 1) for p in line.split() if '=' in p)
            syms.append({
                'name': parts.get('name', ''),
                'module': parts.get('module', ''),
                'addr': int(parts.get('addr', '0'), 16),
                'size': int(parts.get('size', '0'), 16)
            })
    return syms

def classify_function(sym, code_bytes):
    name = sym['name']
    addr = sym['addr']

    # 1. Known prefix/name matching
    for pfx in SDK_PREFIXES:
        if name.startswith(pfx):
            return 'SDK', f'SDK Prefix ({pfx})'

    for msl in MSL_NAMES:
        if name == msl or name.startswith(msl + '_') or name.startswith('__aeabi_') or name.startswith('__sfp_'):
            return 'MSL', f'MSL C Runtime ({msl})'

    if '_std_' in name or 'std::' in name or 'MSL' in name:
        return 'MSL', 'MSL C++ Runtime'

    # 2. Binary memory zone rules (CodeWarrior section ordering in NDS ROMs)
    # Addresses 0x02350000+ are NITRO-SDK library section
    if addr >= 0x02350000:
        return 'SDK', 'NITRO-SDK Memory Section (>= 0x02350000)'

    # Addresses 0x02332000 - 0x0234FFFF are Metrowerks Runtime & Math Section
    if 0x02332800 <= addr < 0x02350000:
        return 'MSL', 'Metrowerks Runtime/Math Section (0x02332800 - 0x0234FFFF)'

    # 3. Disassembly & Literal Pool Analysis
    if code_bytes:
        # Check literals for hardware registers
        literals = []
        for i in range(0, len(code_bytes) - 3, 4):
            val = struct.unpack('<I', code_bytes[i:i+4])[0]
            literals.append(val)

        if any(0x04000000 <= v < 0x04001000 for v in literals):
            return 'SDK', 'Hardware IO Access (0x0400XXXX)'

        if any(0x06800000 <= v < 0x07000000 for v in literals):
            return 'SDK', 'Display Engine VRAM Access'

        # Check for CP15 instructions
        md_thumb = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
        md_arm = Cs(CS_ARCH_ARM, CS_MODE_ARM)
        dis = list(md_thumb.disasm(code_bytes, addr))
        if not dis: dis = list(md_arm.disasm(code_bytes, addr))

        for insn in dis:
            op = insn.op_str.lower()
            mn = insn.mnemonic.lower()
            if 'p15' in op or mn in ['mcr', 'mrc']:
                return 'SDK', 'CP15 Coprocessor instruction'
            if mn in ['swi', 'svc']:
                return 'SDK', 'SWI BIOS System Call'

    # 4. Default to Application Space
    return 'APP', 'PictoChat Application Logic (< 0x02332800)'

def main():
    syms = load_symbols()
    bin_buffers = {}
    for mod, (base_addr, path) in MODULE_MAP.items():
        if os.path.exists(path):
            with open(path, 'rb') as f:
                bin_buffers[mod] = f.read()

    categories = {'APP': [], 'SDK': [], 'MSL': []}

    for sym in syms:
        mod = sym['module']
        base_addr, _ = MODULE_MAP.get(mod, (0, ''))
        offset = sym['addr'] - base_addr
        data = None
        if mod in bin_buffers and 0 <= offset < len(bin_buffers[mod]):
            data = bin_buffers[mod][offset:offset+sym['size']]

        cat, reason = classify_function(sym, data)
        sym['category'] = cat
        sym['reason'] = reason
        categories[cat].append(sym)

    print("\n================ Classification Summary ================")
    print(f"Total Functions Analyzed: {len(syms)}")
    print(f"  APP Space (PictoChat Logic):  {len(categories['APP'])} functions ({len(categories['APP'])/len(syms)*100:.1f}%)")
    print(f"  SDK Space (Nintendo NITRO):  {len(categories['SDK'])} functions ({len(categories['SDK'])/len(syms)*100:.1f}%)")
    print(f"  MSL Space (Metrowerks C/C++): {len(categories['MSL'])} functions ({len(categories['MSL'])/len(syms)*100:.1f}%)")
    print("========================================================\n")

    out_json = r'config\arm9\classified_symbols.json'
    with open(out_json, 'w') as f:
        json.dump(syms, f, indent=2)
    print(f"Saved classification map to {out_json}")

    # Generate Markdown Summary Report
    report_file = r'notes\symbol-classification.md'
    with open(report_file, 'w') as f:
        f.write("# PictoChat Symbol & Function Classification\n\n")
        f.write("Functions are categorized into **App Space** (PictoChat Application Logic), **SDK Space** (Nintendo NITRO-SDK), and **MSL Space** (Metrowerks C/C++ Runtime).\n\n")
        f.write("## Space Breakdown\n\n")
        f.write(f"- **APP Space**: {len(categories['APP'])} functions ({len(categories['APP'])/len(syms)*100:.1f}%)\n")
        f.write(f"- **SDK Space**: {len(categories['SDK'])} functions ({len(categories['SDK'])/len(syms)*100:.1f}%)\n")
        f.write(f"- **MSL Space**: {len(categories['MSL'])} functions ({len(categories['MSL'])/len(syms)*100:.1f}%)\n\n")
        f.write("## Sample App Functions\n")
        for s in categories['APP'][:10]:
            f.write(f"- `{s['name']}` @ `{hex(s['addr'])}` (size `{hex(s['size'])}`): {s['reason']}\n")
        f.write("\n## Sample SDK Functions\n")
        for s in categories['SDK'][:10]:
            f.write(f"- `{s['name']}` @ `{hex(s['addr'])}` (size `{hex(s['size'])}`): {s['reason']}\n")
        f.write("\n## Sample MSL Runtime Functions\n")
        for s in categories['MSL'][:10]:
            f.write(f"- `{s['name']}` @ `{hex(s['addr'])}` (size `{hex(s['size'])}`): {s['reason']}\n")

    print(f"Saved markdown report to {report_file}")

if __name__ == '__main__':
    main()
