// decomp: module=arm7 addr=0x022c73a0 name=FUN_022c73a0
// flags: -O4,s

// Installs (or clears) the handler for slot `idx` in the table at G_0380525c
// and keeps the matching bit of the enable mask at 0x02ffff8c in sync, with
// interrupts held off across the pair.
//
// The mask has to be reached through a plain pointer local rather than an
// extern array: with a symbol the compiler folds 0x380 of the 0x38c byte
// offset into the literal-pool word and uses `ldr rX, [base, #0xc]`, while the
// ROM keeps 0x02fffc00 whole in the pool and materialises 0x38c into a
// register (`movs #0xe3; lsls #2`) for a register-offset load.

#pragma thumb on

extern int FUN_022c6f28(void);
extern void FUN_022c6f34(int state);
extern void *G_0380525c[];

void FUN_022c73a0(int idx, void *fn)
{
    unsigned int *mask = (unsigned int *)0x02fffc00;
    int state;

    state = FUN_022c6f28();
    G_0380525c[idx] = fn;
    if (fn != 0) {
        mask[0xe3] |= 1 << idx;
    } else {
        mask[0xe3] &= ~(1 << idx);
    }
    FUN_022c6f34(state);
}
