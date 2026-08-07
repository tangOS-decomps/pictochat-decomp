// decomp: module=arm7 addr=0x022da71c name=FUN_022da71c
// flags: -noThumb -O4,s

typedef unsigned short u16;

extern void func_0x037c6220(u16 val);
extern void FUN_022d81b8(void);

int FUN_022da71c(void *param_1, void *param_2)
{
    *(u16 *)((char *)param_2 + 2) = 1;
    u16 val = *(u16 *)((char *)param_1 + 0x10);
    if (val > 1) {
        return 5;
    }
    func_0x037c6220(val);
    if (*(u16 *)((char *)param_1 + 0x10) == 1) {
        FUN_022d81b8();
    }
    return 0;
}
