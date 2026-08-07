// decomp: module=arm7 addr=0x022d9d68 name=FUN_022d9d68
// flags: -noThumb

// Writes bit `bit` of the pending mask at +0x52e of the ARM7 state block to
// `val`, then pokes the FIFO doorbell: 0x048080ac if any pending bit is still
// outside the acknowledged mask at +0x532, 0x048080ae once they all are.

void FUN_022d9d68(unsigned int bit, unsigned int val)
{
    unsigned short *p = (unsigned short *)(*(int *)0x0380fff4 + 0x52c);

    p[1] = (unsigned short)((p[1] & ~(1 << bit)) | (val << bit));

    if (p[1] & ~p[3]) {
        *(volatile unsigned short *)0x048080ac = 8;
    } else {
        *(volatile unsigned short *)0x048080ae = 8;
    }
}
