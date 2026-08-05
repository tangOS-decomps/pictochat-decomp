//cpp
// decomp: module=unk_autoload_0 addr=0x02336764 name=FUN_02336764

// Sub-engine BG character base getter. Reads the display mode from the low 3
// bits of sub DISPCNT (0x04001000) and the BG0 control word from sub BG0CNT
// (0x0400100c); in modes 5 and up with the BG0CNT bit-7 flag set the background
// is not a character background at all and there is no pointer to return.
//
// Three details are load-bearing:
//   * the mode is read through `int`, giving the signed `blt` the ROM uses;
//     an unsigned read gives `bcc`.
//   * the control word is held in `unsigned int`, giving the logical `lsrs`;
//     `unsigned short` promotes to int and yields an arithmetic `asrs`.
//   * the pointer return is the if-body and `return 0` is the fallthrough. The
//     natural spelling (`if (bad) return 0;` first) inlines the zero path
//     instead of placing it after the body, and stops matching.

#pragma thumb on
extern "C" {
void *FUN_02336764(void)
{
    int mode = *(volatile int *)0x04001000 & 7;
    unsigned int cnt = *(volatile unsigned short *)0x0400100c;
    if (mode < 5 || (cnt & 0x80) == 0)
        return (void *)(((cnt & 0x3c) >> 2) * 0x4000 + 0x06200000);
    return 0;
}
}
