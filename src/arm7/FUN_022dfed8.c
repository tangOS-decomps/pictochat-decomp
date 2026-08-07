// decomp: module=arm7 addr=0x022dfed8 name=FUN_022dfed8
// flags: -O4,s -noThumb
//
// Allocates a 0x36-byte request block out of the heap at G_0380fff4+0x188,
// fills in the fixed header for a 2-byte body (total 0x1e, flags 0xc0) and
// hands back the body pointer at +0x10.  With a nonzero third argument the
// destination is validated by FUN_022df690 first.
// Verify with size 0x94, not 0x8c - the stated size excludes the two trailing
// pool words (0x0380fff4 and 0x0000ffff).

extern void *G_0380fff4;

extern int FUN_022df690(int dest);
extern void *FUN_037c58fc(void *heap, int size);
extern void FUN_022d9088(int code);
extern void FUN_022dffc4(void *body, int dest);

void *FUN_022dfed8(int dest, unsigned short a1, int check) {
    char *p;

    if (check != 0) {
        if (FUN_022df690(dest) == 0) {
            return 0;
        }
    }

    p = (char *)FUN_037c58fc((char *)G_0380fff4 + 0x188, 0x36);
    if (p == 0) {
        FUN_022d9088(2);
        return p;
    }

    *(unsigned short *)(p + 0xc) = 0xffff;
    FUN_022dffc4(p + 0x10, dest);
    *(unsigned short *)(p + 0x3c) = a1;
    *(unsigned short *)(p + 0x16) = 2;
    *(unsigned short *)(p + 0x22) = *(unsigned short *)(p + 0x16) + 0x1c;
    *(unsigned short *)(p + 0x24) = 0xc0;
    return p + 0x10;
}
