// decomp: module=unk_autoload_0 addr=0x0232cb34 name=FUN_0232cb34
// verify: python tools/match.py --c src/arm9/FUN_0232cb34.c --func FUN_0232cb34 --addr 0x0232cb34 --size 0x90 --module unk_autoload_0 --version 2.0/sp1

// Opens channel 7 with a caller-supplied config block. Claims the channel
// through FUN_0232c520, rejects a missing/inconsistent block (a non-zero
// payload length with a null payload pointer, or a canvas that would overflow
// 0x200 in either axis once the header allowance is added), then flushes the
// block (and its payload) out of the data cache before handing it to the
// channel. Reports 2 when the configure step returns 0.

#pragma thumb on

extern int FUN_0232c520(int, int);
extern int FUN_0232cbc4(void *);
extern void FUN_0232c3bc(int, int);
extern void FUN_023314e8(int, int);
extern int FUN_0232c408(int, int, int);

int FUN_0232cb34(int a, void *s)
{
    char *p = (char *)s;
    unsigned short flag;
    int r = FUN_0232c520(1, 2);
    if (r == 0) {
        if (p == 0) return 6;
        if (*(unsigned short *)(p + 4) != 0 && *(int *)p == 0) return 6;
        flag = *(unsigned short *)(p + 0x14);
        if (*(unsigned short *)(p + 0x34) + (flag ? 0x2a : 0) > 0x200 ||
            *(unsigned short *)(p + 0x36) + (flag ? 6 : 0) > 0x200) return 6;
        FUN_0232cbc4(p);
        FUN_0232c3bc(7, a);
        FUN_023314e8((int)p, 0x40);
        if (*(unsigned short *)(p + 4) != 0)
            FUN_023314e8(*(int *)p, *(unsigned short *)(p + 4));
        r = FUN_0232c408(7, 1, (int)p);
        if (r == 0) r = 2;
    }
    return r;
}
