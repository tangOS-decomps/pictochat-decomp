//cpp
// decomp: module=unk_autoload_0 addr=0x023328e0 name=FUN_023328e0
#pragma thumb on
extern "C" {
int FUN_02332080(void);
int FUN_02330aa0(const void *);
int FUN_02330a1c(void *);
void FUN_02332094(int);
void FUN_02332d10(int);
void FUN_023328e0(void *arg, unsigned int *out)
{
    const void *reg = (const void *)0x02ffffe8;
    for (;;) {
        out[1] = FUN_02332080();
        out[0] = FUN_02330aa0(reg) & 0x40;
        if (out[0] != 0 || FUN_02330a1c(arg) == 0) {
            break;
        }
        FUN_02332094(out[1]);
        FUN_02332d10(1);
    }
}
}
