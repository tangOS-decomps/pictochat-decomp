import os

cp15_files = {
    'CP15_EnableMPU.cpp': ('0x023317a4', '_ZN4CP159EnableMPUEv', '0x10', """extern "C" unsigned int _ZN4CP159EnableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    v |= 1;
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}"""),
    'CP15_DisableMPU.cpp': ('0x023317b4', '_ZN4CP1510DisableMPUEv', '0x10', """extern "C" unsigned int _ZN4CP1510DisableMPUEv(void){
    unsigned int v;
    asm { mrc p15,0,v,c1,c0,0 }
    asm { bic v,v,#1 }
    asm { mcr p15,0,v,c1,c0,0 }
    return v;
}"""),
    'CP15_FlushDataCache.cpp': ('0x0233146c', '_ZN4CP1514FlushDataCacheEv', '0x2c', """extern "C" asm void _ZN4CP1514FlushDataCacheEv(void){
    mov r1, #0
outer:
    mov r0, #0
seg:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt seg
    add r1, r1, #0x40000000
    cmp r1, #0
    bne outer
    bx lr
}"""),
    'CP15_FlushDataCacheRange.cpp': ('0x023314e8', '_ZN4CP1514FlushDataCacheEjj', '0x1c', """extern "C" asm void _ZN4CP1514FlushDataCacheEjj(unsigned int addr, unsigned int size){
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}"""),
    'CP15_DrainWriteBuffer.cpp': ('0x02331528', '_ZN4CP1516DrainWriteBufferEv', '0xc', """extern "C" asm void _ZN4CP1516DrainWriteBufferEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}"""),
    'CP15_WaitForInterrupt.cpp': ('0x0233229c', '_ZN4CP1516WaitForInterruptEv', '0xc', """extern "C" asm void _ZN4CP1516WaitForInterruptEv(void){
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}"""),
    'CP15_InvalidateDataCacheRange.cpp': ('0x023314cc', '_ZN4CP1519InvalidateDataCacheEjj', '0x1c', """extern "C" asm void _ZN4CP1519InvalidateDataCacheEjj(unsigned int addr, unsigned int size){
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}""")
}

for fname, (addr, name, size, body) in cp15_files.items():
    code = f"// decomp: module=unk_autoload_0 addr={addr} name={name}\n" + body + "\n"
    fpath = os.path.join('drafts/arm9', fname)
    with open(fpath, 'w') as f: f.write(code)
    print(f"Created {fpath}")

# Remove old container file
if os.path.exists('drafts/arm9/CP15.cpp'):
    os.remove('drafts/arm9/CP15.cpp')
