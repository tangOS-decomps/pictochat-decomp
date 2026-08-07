// decomp: module=arm7 addr=0x022dff6c name=FUN_022dff6c
// flags: -O4,s -noThumb

// Fills in the scratch frame hanging off +0x45c of the object at G_0380fff4:
// clears the first three header halfwords, sets length 0x14 / type 0xa4 and
// stores `arg` with the two top control bits forced on, then hands the body
// (+0x10) to FUN_022d8138 to be filled from the two 3-halfword records at
// +0x3a8 and +0x324 of the same object.
//
// The base pointer is reloaded before the FUN_022d8138 arguments are formed -
// the halfword stores through the frame alias it, which is exactly what the
// ROM's second `ldr r2, [ip]` is.
// Lever 3, reversed: naming the global (`extern char *G_0380fff4;`) compiles to
// the same 21 instructions but with r1/ip/r3/r2 permuted throughout. Spelling
// it as the plain pointer literal *(char **)0x0380fff4 is what puts the pool
// address in ip and the frame in r3, as the ROM has it.
// NOTE: verify with --size 0x58, not funcs.json's 0x54 - the boundary excludes
// this function's own trailing pool word.

#define WM_BASE (*(char **)0x0380fff4)

extern void FUN_022d8138(unsigned short *dst, unsigned short *srcA,
                         unsigned short *srcB);

void FUN_022dff6c(int arg)
{
    unsigned short *f = *(unsigned short **)(WM_BASE + 0x45c);

    f[0] = 0;
    f[1] = 0;
    f[2] = 0;
    f[5] = 0x14;
    f[6] = 0xa4;
    f[7] = (unsigned short)(arg | 0xc000);

    FUN_022d8138(f + 8,
                 (unsigned short *)(WM_BASE + 0x3a8),
                 (unsigned short *)(WM_BASE + 0x324));
}
