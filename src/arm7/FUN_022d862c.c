// decomp: module=arm7 addr=0x022d862c name=FUN_022d862c
// flags: -O4,s -noThumb
// Writes a WiFi command/data register pair. The halfword at 0x0480815a is
// stored first, so that address is the pool constant and the command register
// at 0x04808158 is reached with the [r2,#-2] displacement.
// The result type must be UNSIGNED: for a signed `int` mwcc lowers the
// `cond ? -1 : 0` select to movne #1 / moveq #0 / rsb (one word too long);
// with an unsigned result it emits the mvnne #0 / moveq #0 pair the ROM has.
extern unsigned int func_037c849c(void);

unsigned int FUN_022d862c(unsigned short cmd, unsigned short data) {
    *(volatile unsigned short *)0x0480815a = data;
    *(volatile unsigned short *)0x04808158 = cmd | 0x5000;
    if (func_037c849c() != 0) {
        return 0xffffffffU;
    }
    return 0;
}
