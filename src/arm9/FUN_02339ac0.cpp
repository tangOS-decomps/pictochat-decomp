//cpp
// decomp: module=unk_autoload_0 addr=0x02339ac0 name=FUN_02339ac0
#pragma thumb on
struct State_023c35a0 {
    unsigned char pad[0x24];
    int handle;
};
extern "C" {
extern State_023c35a0 G_023c35a0;
extern int FUN_02339a48(int, int, void (*)(void), int);
extern void FUN_02339e48(void);
extern void FUN_02339e54(void);
int FUN_02339ac0(int a, int b)
{
    int handle = FUN_02339a48(a, b, FUN_02339e48, 0);
    G_023c35a0.handle = handle;
    if (handle == 0) {
        FUN_02339e54();
    }
    return G_023c35a0.handle;
}
}
