// decomp: module=arm7 addr=0x022d8600 name=FUN_022d8600
// flags: -noThumb

// Writes a command word with bit 13/14 set to the SPI-ish register at 0x04808158,
// runs the external transfer at 0x037c849c, and returns the reply from 0x0480815c.

extern void FUN_037c849c(void);
unsigned short FUN_022d8600(unsigned short v)
{
    *(volatile unsigned short *)0x04808158 = v | 0x6000;
    FUN_037c849c();
    return *(volatile unsigned short *)0x0480815c;
}
