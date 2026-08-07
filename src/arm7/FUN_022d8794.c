// decomp: module=arm7 addr=0x022d8794 name=FUN_022d8794
// flags: -O4,s -noThumb
// size: 0x68 - includes the trailing pool word.

// Streams 0x69 entries out to the codec: for each index i, reads register
// 0x64+i into a scratch word and hands it to FUN_022d862c, then issues the
// final 0x5a/2 command.
//
// FUN_022d862c's own definition takes unsigned short parameters, but this call
// site passes the scratch word straight through (`ldr r1,[sp]` with no
// narrowing), so the extern is declared with int parameters here - a u16
// parameter makes mwcc insert the lsl/lsr pair the ROM does not have.

extern void FUN_022e2e4c(int index, int n, unsigned char *dst);
extern unsigned int FUN_022d862c(int cmd, int data);

void FUN_022d8794(void)
{
    int buf;
    unsigned int i;
    int reg;

    *(volatile unsigned short *)0x04808160 = 0x100;
    buf = 0;
    reg = 0x64;
    for (i = 0; i < 0x69; i++) {
        FUN_022e2e4c(reg, 1, (unsigned char *)&buf);
        FUN_022d862c(i, buf);
        reg++;
    }
    FUN_022d862c(0x5a, 2);
}
