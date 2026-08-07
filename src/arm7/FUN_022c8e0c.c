// decomp: module=arm7 addr=0x022c8e0c name=FUN_022c8e0c
// flags: -O4,s

// Tears down slot `i` of `p`: looks the slot up through FUN_022c8dec, and when
// it exists flushes it (FUN_022c8d88 with value -1 = "leave alone"), releases
// its child list, clears the enable bit of the matching 0x40-byte record in
// G_03805fbc, and finally writes the 0xff free sentinel back into the index
// byte at +8+i.

#pragma thumb on

extern unsigned char G_03805fbc[];
extern void *FUN_022c8dec(int p, int i);
extern void FUN_022c8d88(void *obj, int arg, int value);
extern void FUN_022c8dcc(int p);

void FUN_022c8e0c(int p, int i)
{
    unsigned char *tbl;
    unsigned int v;
    void *slot = FUN_022c8dec(p, i);

    if (slot == 0) {
        return;
    }
    FUN_022c8d88(slot, p, -1);
    FUN_022c8dcc((int)slot);

    tbl = (unsigned char *)(p + 8);
    v = tbl[i];
    G_03805fbc[v * 0x40] &= ~1;
    tbl[i] = 0xff;
}
