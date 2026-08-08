//cpp
// decomp: module=unk_autoload_0 addr=0x02330ecc name=FUN_02330ecc
// verify: python tools/match.py --c src/arm9/FUN_02330ecc.cpp --func FUN_02330ecc --addr 0x02330ecc --size 0x28 --module unk_autoload_0 --version 2.0/sp1

// Fires and clears the one-shot hook at +0xb4 of the live object, re-masking
// interrupts afterwards, then runs the fixed follow-up.

#pragma thumb on
extern "C" {
typedef void (*Fn)(int);
typedef struct T {
    char pad[0xb4];
    Fn hook;
} T;
extern T **G_023c07c4[];
extern int FUN_02332080(void);
extern void FUN_02330ef4(void);
void FUN_02330ecc(int a)
{
    T *t = *G_023c07c4[2];
    Fn h = t->hook;

    if (h != 0) {
        t->hook = 0;
        h(a);
        FUN_02332080();
    }
    FUN_02330ef4();
}
}
