// decomp: module=arm7 addr=0x022c6168 name=FUN_022c6168
// flags: -O4,s -noThumb
// size: 0x7c - 0x70 of code plus three trailing pool words.

// One-shot bring-up for the SPI/AUX block guarded by the flag word at
// 0x038051f0: marks it busy, sets bit 0 of the 0x038051ec status word, clears
// the two callback slots, resets REG_SPICNT/REG_SPIDATA and re-enables SPI with
// 0xc1, installs the 0x037fdc84 handler on IRQ source 8 and unmasks it.

extern int FUN_022c614c(unsigned int bit);
extern void FUN_022c4738(int mask, void *handler);
extern void FUN_022c486c(int mask);
extern void FUN_037fdc84(void);

typedef struct Spi {
    unsigned short busy;    // 0x00
    unsigned short pad;     // 0x02
    int state;              // 0x04
    int callback;           // 0x08
    int userdata;           // 0x0c
} Spi;

extern Spi G_038051f0;

void FUN_022c6168(void)
{
    if (G_038051f0.busy != 0) {
        return;
    }

    G_038051f0.busy = 1;
    FUN_022c614c(0);

    G_038051f0.callback = 0;
    G_038051f0.userdata = 0;

    *(volatile unsigned short *)0x04000102 = 0;
    *(volatile unsigned short *)0x04000100 = 0;
    *(volatile unsigned short *)0x04000102 = 0xc1;

    FUN_022c4738(8, (void *)FUN_037fdc84);
    FUN_022c486c(8);

    G_038051f0.state = 0;
}
