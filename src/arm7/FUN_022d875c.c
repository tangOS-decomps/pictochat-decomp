// decomp: module=arm7 addr=0x022d875c name=FUN_022d875c
// flags: -noThumb

// Replays a 25-entry (offset, value) register script from G_02316488 into the
// DSi-only I/O block based at 0x04808000 (the wifi/SDIO window).
// The ROM re-derives base + i every iteration and keeps i as its own counter,
// so strength reduction has to be turned off (same lever as FUN_022ce5b4).

#pragma opt_strength_reduction off

typedef struct {
    unsigned short off;
    unsigned short val;
} RegWrite;

extern const RegWrite G_02316488[];

void FUN_022d875c(void)
{
    unsigned int i;
    for (i = 0; i < 0x19; i++) {
        *(volatile unsigned short *)(0x04808000 + G_02316488[i].off) = G_02316488[i].val;
    }
}
