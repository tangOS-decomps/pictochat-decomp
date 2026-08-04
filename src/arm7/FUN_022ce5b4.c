// decomp: module=arm7 addr=0x022ce5b4 name=FUN_022ce5b4
// flags: -noThumb
// 2.0/* strength-reduces this loop's index into a pointer induction variable
// (`add rP,rP,#1` walking the array); the ROM re-derives `base + i` each
// iteration and keeps i as its own counter. This pragma is the documented
// lever for exactly that (sm64ds-decomp notes 6e: opt_strength_reduction is
// one of the few pragmas mwccarm actually honours). Four natural loop
// rewrites (unsigned index, while-form, explicit pointer arithmetic, named
// byte temp) were tried first and none defeat the reduction.
#pragma opt_strength_reduction off
extern unsigned char G_023180dc[];
extern int func_023018a0(unsigned int avg);

int FUN_022ce5b4(void) {
    int i;
    unsigned int sum = 0;
    for (i = 0; i < 0x20; i++) {
        sum += G_023180dc[0x1554 + i];
    }
    return func_023018a0(sum >> 5);
}
