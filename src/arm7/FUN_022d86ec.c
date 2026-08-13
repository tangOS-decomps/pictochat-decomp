// decomp: module=arm7 addr=0x022d86ec name=FUN_022d86ec
// flags: -noThumb
// size: 0x70 - the stated 0x6c excludes the trailing pool word (0x0380fff4).

// Zeroes the four-halfword register-mirror block at state+0x5f8 and binds
// registers 0x40..0x43 (one halfword each) to its slots through FUN_022e2e4c.

extern void FUN_037cb774(int value, void *dst, unsigned int size);
extern void FUN_022e2e4c(int reg, int count, void *slot);

void FUN_022d86ec(void)
{
    unsigned short *p = (unsigned short *)(*(char **)0x0380fff4 + 0x5f8);

    FUN_037cb774(0, p, 0x10);
    FUN_022e2e4c(0x40, 1, &p[0]);
    FUN_022e2e4c(0x41, 1, &p[1]);
    FUN_022e2e4c(0x42, 1, &p[2]);
    FUN_022e2e4c(0x43, 1, &p[3]);
}
