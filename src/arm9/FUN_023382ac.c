// decomp: module=unk_autoload_0 addr=0x023382ac name=FUN_023382ac
#pragma thumb on

extern int FUN_02332080(void);
extern void FUN_02332094(int state);
extern void *G_023C34A8[];

void FUN_023382ac(int idx, void *fn)
{
    unsigned int *mask = (unsigned int *)0x02fffc00;
    int state;

    state = FUN_02332080();
    G_023C34A8[idx] = fn;
    if (fn != 0) {
        mask[0xe2] |= 1 << idx;
    } else {
        mask[0xe2] &= ~(1 << idx);
    }
    FUN_02332094(state);
}
