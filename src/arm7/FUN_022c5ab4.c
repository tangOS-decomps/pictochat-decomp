// decomp: module=arm7 addr=0x022c5ab4 name=FUN_022c5ab4
// flags: -O4,s -noThumb
// size: 0x7c - the nominal 0x68 excludes the five trailing pool words.
//
// Low-end counterpart of FUN_022c5b30: region lookup by id. Id 1 answers with
// a fixed main-RAM address, id 7 with the ARM7 WRAM base, and id 8 with the
// bottom of the system stack - computed from the WRAM arena start (clamped to
// the WRAM base) when the stack size symbol is negative, or from the IRQ stack
// bottom otherwise. A zero stack size leaves the clamped arena start.
//
// The two stack-size words in the pool are separate symbol relocations (both
// read 0x400); that is why the comparisons against them survive -O4.

extern char G_03807258[];
extern char SDK_IRQ_STACKSIZE[];
extern char SDK_SYS_STACKSIZE[];

void *FUN_022c5ab4(int id)
{
    switch (id) {
    case 1:
        return (void *)0x027ff000;
    case 7:
        return (void *)0x03800000;
    case 8: {
        char *irqLo = (char *)0x0380ff80 - (int)SDK_IRQ_STACKSIZE;
        char *p = (char *)0x03800000;

        if (G_03807258 > (char *)0x03800000)
            p = G_03807258;
        if ((int)SDK_SYS_STACKSIZE == 0)
            return p;
        if ((int)SDK_SYS_STACKSIZE < 0)
            p -= (int)SDK_SYS_STACKSIZE;
        else
            p = irqLo - (int)SDK_SYS_STACKSIZE;
        return p;
    }
    }
    return 0;
}
