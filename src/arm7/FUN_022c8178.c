// decomp: module=arm7 addr=0x022c8178 name=FUN_022c8178
// flags: -O4,s

// Submits a request block whose opcode byte at +0 lies in 8..0xd: marks it
// kind 1, stashes the user word at +0x44, sets the 0x1f46 timeout at +0x3c and
// forwards it to 0x022c864c.  Out-of-range opcodes are rejected with 0.

#pragma thumb on

extern void FUN_022c864c(void *req, int arg);

int FUN_022c8178(void *req, int user, int arg)
{
    unsigned char *p = (unsigned char *)req;
    unsigned char op = p[0];
    if (op < 8) return 0;
    if (op > 0xd) return 0;
    p[1] = 1;
    *(int *)(p + 0x44) = user;
    *(unsigned short *)(p + 0x3c) = 0x1f46;
    FUN_022c864c(req, arg);
    return 1;
}
