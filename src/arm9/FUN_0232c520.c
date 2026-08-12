// decomp: module=unk_autoload_0 addr=0x0232c520 name=FUN_0232c520
#pragma thumb on

extern int FUN_0232c4dc(void);
extern void FUN_023314cc(void *, int);
extern unsigned short **G_023bd8a0[];

int FUN_0232c520(int count, ...)
{
    unsigned short value;
    unsigned char *base;
    unsigned char *ap;
    int result;
    int rc;

    rc = FUN_0232c4dc();
    if (rc != 0)
        return rc;
    FUN_023314cc(G_023bd8a0[1][1], 2);
    base = (unsigned char *)((unsigned int)&count & ~3);
    value = *G_023bd8a0[1][1];
    result = 3;
    ap = base + 4;
    while (count != 0) {
        ap += 4;
        if (*(int *)(ap - 4) == value)
            result = 0;
        count--;
    }
    return result;
}
