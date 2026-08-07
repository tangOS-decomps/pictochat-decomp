// decomp: module=arm7 addr=0x022d6ca8 name=FUN_022d6ca8
// flags: -noThumb

extern void *G_0380fff4;
extern void FUN_022d6c8c(void *dst, int n);
extern int FUN_037c58fc(void *dst, int n);

void FUN_022d6ca8(int *a0)
{
    char *heap = (char *)G_0380fff4;
    char *chan;

    *(int *)(heap + 0x17c) = a0[0];
    chan = heap + 0x344;
    *(int *)(heap + 0x180) = a0[1];
    *(int *)(heap + 0x184) = a0[2];

    FUN_022d6c8c(heap + 0x188, 2);
    FUN_022d6c8c(heap + 0x194, 3);
    FUN_022d6c8c(heap + 0x1a0, 4);
    FUN_022d6c8c(heap + 0x1ac, 5);
    FUN_022d6c8c(heap + 0x1b8, 6);
    FUN_022d6c8c(heap + 0x1c4, 7);
    FUN_022d6c8c(heap + 0x1d0, 8);
    FUN_022d6c8c(heap + 0x1dc, 9);
    FUN_022d6c8c(heap + 0x1e8, 0xa);
    FUN_022d6c8c(heap + 0x1f4, 0xb);
    FUN_022d6c8c(heap + 0x200, 0xc);

    {
        int r = FUN_037c58fc(heap + 0x188, 0x81);

        *(int *)(chan + 0x9c) = r + 0xc;
        *(unsigned short *)(chan + 0xa0) = 0;
        *(unsigned short *)(chan + 0xa4) = 0;
    }
}
