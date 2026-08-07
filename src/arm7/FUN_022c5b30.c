// decomp: module=arm7 addr=0x022c5b30 name=FUN_022c5b30
// flags: -O4,s -noThumb
//
// Region lookup by id. Id 1 answers with a fixed main-RAM symbol; ids 7 and 8
// answer with the low and high ends of the range between the ARM7 WRAM base
// 0x03800000 and the linker symbol G_03807258 (clamped so 7 never returns
// above the base and 8 never returns below it). Every other id gives NULL.
//
// The two `ldr rX,[pc,...]` of 0x03807258 are symbol relocations, not folded
// constants - that is why the comparisons against 0x03800000 survive -O4.

extern char G_0231966c[];
extern char G_03807258[];

void *FUN_022c5b30(int id)
{
    switch (id) {
    case 1:
        return G_0231966c;
    case 7: {
        char *p = G_03807258;
        if (p > (char *)0x03800000)
            p = (char *)0x03800000;
        return p;
    }
    case 8: {
        char *p = (char *)0x03800000;
        if (G_03807258 > (char *)0x03800000)
            p = G_03807258;
        return p;
    }
    }
    return 0;
}
