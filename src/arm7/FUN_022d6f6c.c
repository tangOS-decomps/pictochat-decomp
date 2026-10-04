// decomp: module=arm7 addr=0x022d6f6c name=FUN_022d6f6c
// flags: -O4,s -noThumb
// size: 0x80 - the nominal 0x74 excludes the three trailing pool words.
//
// Sets the link mode (0-3; anything larger is rejected with 5): stored at
// +0x32e and +0x350, written into the low three bits of the mode register
// 0x04808006, then the power state at +0x352 is re-applied through
// FUN_022d7c88 and bit 3 of the pending mask at +0x340 raised.

typedef unsigned short u16;

extern int FUN_022d7c88(unsigned short enable);

#define ST (*(char **)0x0380fff4)

int FUN_022d6f6c(u16 mode)
{
    if (mode > 3) {
        return 5;
    }
    *(u16 *)(ST + 0x32e) = mode;
    *(u16 *)(ST + 0x350) = mode;
    *(volatile u16 *)0x04808006 = (*(volatile u16 *)0x04808006 & 0xfff8) | mode;
    FUN_022d7c88(*(u16 *)(ST + 0x352));
    *(int *)(ST + 0x340) |= 8;
    return 0;
}
