// decomp: module=arm7 addr=0x022c81a8 name=FUN_022c81a8
// flags: -O4,s

// Same shape as FUN_022c8178 but for the two opcodes 0xe..0xf: marks the
// request block kind 2, sets the 0x1f46 timeout at +0x3c and forwards it to
// 0x022c864c.  No user word is stored.  Out-of-range opcodes give 0.

#pragma thumb on

extern void FUN_022c864c(void *req, int arg);

int FUN_022c81a8(void *req, int arg)
{
    unsigned char *p = (unsigned char *)req;
    unsigned char op = p[0];
    if (op < 0xe) return 0;
    if (op > 0xf) return 0;
    p[1] = 2;
    *(unsigned short *)(p + 0x3c) = 0x1f46;
    FUN_022c864c(req, arg);
    return 1;
}
