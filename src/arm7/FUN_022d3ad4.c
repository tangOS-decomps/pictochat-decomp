// decomp: module=arm7 addr=0x022d3ad4 name=FUN_022d3ad4
// flags: -O4,s -noThumb

// Queries the 0x22d0918 service into a 0x200-byte scratch block and reports the
// result over the 0x1f message channel: on a non-zero status it sends the
// long (0x305) form carrying the status word, otherwise the short form.

extern unsigned short *FUN_022d0918(void *buf);
extern unsigned short *FUN_037d14bc(void);
extern void FUN_037d1464(void);

void FUN_022d3ad4(void)
{
    unsigned char buf[0x200];
    unsigned short *r;
    unsigned short *p;
    unsigned short status;

    r = FUN_022d0918(buf);
    status = r[2];
    if (status != 0) {
        p = FUN_037d14bc();
        p[0] = 0x1f;
        p[1] = 1;
        p[2] = 0x305;
        p[3] = status;
        FUN_037d1464();
    } else {
        p = FUN_037d14bc();
        p[0] = 0x1f;
        p[1] = 0;
        FUN_037d1464();
    }
}
