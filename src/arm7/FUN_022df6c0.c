// decomp: module=arm7 addr=0x022df6c0 name=FUN_022df6c0
// flags: -noThumb -O4,s

extern void *G_0380fff4;
extern void *FUN_037c58fc(void *dst, int n);
extern void FUN_022d9088(int n);
extern void FUN_022dffc4(void *dst, int a0);

void *FUN_022df6c0(int a0, int a1)
{
    char *heap = (char *)G_0380fff4;
    char *node = (char *)FUN_037c58fc(heap + 0x188, 0x36);

    if (node == 0) {
        FUN_022d9088(2);
        return node;
    }

    *(unsigned short *)(node + 0xc) = 0xffff;
    FUN_022dffc4(node + 0x10, a0);
    *(unsigned short *)(node + 0x3c) = a1;
    *(unsigned short *)(node + 0x16) = 2;
    *(unsigned short *)(node + 0x22) = *(unsigned short *)(node + 0x16) + 0x1c;
    *(unsigned short *)(node + 0x24) = 0xa0;

    return node + 0x10;
}
