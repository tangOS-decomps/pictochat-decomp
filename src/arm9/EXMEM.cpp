//cpp
extern "C" {
// ==========================================================
// C++ Class Implementation: EXMEM
// ==========================================================

// --- EXMEM_GetAndResetConfig.cpp ---
// decomp: module=unk_autoload_0 addr=0x02332884 name=EXMEM_GetAndResetConfig
// NONMATCHING: reads/resets 2 bitfields of the EXMEMCNT hardware register (0x04000204, confirmed real NDS/DSi MMIO address, not application data) into an out struct's 2 int fields, then forces bits[3:2]=3 and clears bit4 - fully logic-correct, identical instruction shapes/count/order to target, but a systematic 3-way register recolor (target r1=ptr/r2=temp/r3=mask-const vs candidate r3=ptr/r1=temp/r2=mask-const) that didn't respond to 3 different C restructurings (direct global access, local volatile pointer, named mask constant local, various declaration orders per notes/tooling.md's register-pairing tip). Ghidra's cached size (0x30) also excluded the trailing pool word - true size is 0x34. (div=11). Logic verified correct vs ROM; not
// byte-matchable from C at mwccarm dsi/1.3 (see notes/matching-style.md).
// Counts as decompiled, not matched.
struct Out {
    int a;
    int b;
};

extern volatile unsigned short G_04000204;

void EXMEM_GetAndResetConfig(struct Out *out) {
    out->a = (G_04000204 & 0xc) >> 2;
    out->b = (G_04000204 & 0x10) >> 4;
    G_04000204 = (G_04000204 & ~0xc) | 0xc;
    G_04000204 = G_04000204 & ~0x10;
}


}
