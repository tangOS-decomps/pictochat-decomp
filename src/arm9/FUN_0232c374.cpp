//cpp
// decomp: module=unk_autoload_0 addr=0x0232c374 name=FUN_0232c374
#pragma thumb on
extern "C" {
extern unsigned int FUN_02332080(void);
extern void FUN_02332094(unsigned int);
extern int FUN_0232c4dc(void);
extern int FUN_0232c520(int, ...);
extern void FUN_0232c820(void);
extern void FUN_023382ac(int, int);

struct State_0232c374 {
    unsigned short field0;
    unsigned short pad2;
    int field4;
};

int FUN_0232c374(void)
{
    unsigned int key = FUN_02332080();

    if (FUN_0232c4dc() != 0) {
        FUN_02332094(key);
        return 3;
    }

    int rc = FUN_0232c520(1, 0);
    if (rc != 0)
        return rc;

    FUN_0232c820();
    FUN_023382ac(10, 0);

    State_0232c374 *s = (State_0232c374 *)0x023bd8a0;
    s->field4 = 0;
    s->field0 = 0;

    FUN_02332094(key);
    return 0;
}
}
