// decomp: module=unk_autoload_0 addr=0x0233221c name=FUN_0233221c
#pragma thumb on

extern int FUN_02332080(void);
extern void FUN_02332094(int);
extern int FUN_023321f4(unsigned int);
extern int G_023c0b14;
extern unsigned short G_023c0b18[];

void FUN_0233221c(unsigned int flags, int value)
{
    int state = FUN_02332080();
    unsigned int remaining = (flags & G_023c0b14) & 0x1ff;

    for (;;) {
        int bit = 0x1f - FUN_023321f4(remaining);
        unsigned int bitmask;

        if (bit < 0)
            break;
        bitmask = 1u << bit;
        remaining &= ~bitmask;
        if (G_023c0b18[bit] == value) {
            G_023c0b18[bit] = 0;
            G_023c0b14 &= ~bitmask;
        }
    }

    FUN_02332094(state);
}
