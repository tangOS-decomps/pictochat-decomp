// decomp: module=unk_autoload_0 addr=0x023393f0 name=FUN_023393f0
#pragma thumb on
extern int FUN_02339794(int a);
extern int FUN_02339298(int a, int b, int c);
int FUN_023393f0(int a) {
    if (FUN_02339794(a) != 0) {
        return FUN_02339298(0x10, (unsigned short)a, 0);
    } else {
        return 0;
    }
}
