// decomp: module=unk_autoload_0 addr=0x023324f8 name=FUN_023324f8
#pragma thumb on

// Issues an 8-byte slot-1 card command: waits for ROMCTRL's busy bit to
// clear, sets AUXSPICNT's transfer-mode bits to 3 (clearing bit13), then
// writes the two big-endian-swapped 32-bit halves of the command built from
// (param_1:cmd byte, param_2:24-bit payload) into CARD_COMMAND (0x1A8/0x1AC).

void FUN_023324f8(unsigned int param_1, unsigned int param_2)
{
    unsigned int hi;
    unsigned int lo;
    unsigned short ctrl;

    hi = (param_2 >> 8) | (param_1 << 24);
    lo = param_2 << 24;

    do {
    } while ((*(volatile unsigned int *)0x040001A4 & 0x80000000) != 0);

    ctrl = *(volatile unsigned short *)0x040001A0;
    ctrl = (ctrl & ~0x2000) | 0xC000;
    *(volatile unsigned short *)0x040001A0 = ctrl;

    *(volatile unsigned int *)0x040001A8 =
        ((hi & 0xff000000) >> 24) | ((hi & 0xff0000) >> 8) | ((hi & 0xff00) << 8) | (hi << 24);
    *(volatile unsigned int *)0x040001AC =
        ((lo & 0xff000000) >> 24) | ((lo & 0xff0000) >> 8) | ((lo & 0xff00) << 8) | (lo << 24);
}
