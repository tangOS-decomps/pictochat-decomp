// decomp: module=arm7 addr=0x022d8500 name=FUN_022d8500
// flags: -O4,s -noThumb

// Folds a HID-style key report into the two 16-bit bitmasks at *out.  Byte +1
// of the report is the item count, bytes +2.. are the items; the low 7 bits of
// each item index the usage table at 0x023164ec (1-based, 0x78 entries) and
// bit 7 says whether the item is pressed.  Anything out of range, or mapped to
// 0xff, collapses onto bit 15.  out[1] always accumulates, out[0] only for
// pressed items.
// NOTE: verify with --size 0xb4, not funcs.json's 0xb0 - the stated size
// excludes this function's own trailing pool word.

extern unsigned int FUN_022d8d6c(unsigned char *addr);

extern unsigned short G_023164ec[];

void FUN_022d8500(unsigned char *report, unsigned short *out)
{
    unsigned char *items;
    unsigned int i;
    unsigned int n;

    out[0] = 0;
    out[1] = 0;

    n = FUN_022d8d6c(report + 1);
    items = report + 2;

    for (i = 0; i < n; i++) {
        unsigned int item = FUN_022d8d6c(items + i);
        unsigned int idx = (item & 0x7f) - 1;
        unsigned int bit;

        if (idx < 0x78 && (bit = G_023164ec[idx]) != 0xff) {
            out[1] |= 1 << bit;
            if (item & 0x80) {
                out[0] |= 1 << bit;
            }
        } else {
            out[1] |= 0x8000;
            if (item & 0x80) {
                out[0] |= 0x8000;
            }
        }
    }
}
