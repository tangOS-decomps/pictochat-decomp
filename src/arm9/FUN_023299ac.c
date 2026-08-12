// decomp: module=unk_autoload_0 addr=0x023299ac name=FUN_023299ac
#pragma thumb on

extern int FUN_0232996c(void);
extern int FUN_0232ca3c(void);

int FUN_023299ac(void)
{
    if (FUN_0232996c() == 0 || FUN_0232996c() >= 0xc)
        return 5;
    if (FUN_0232996c() == 7 || FUN_0232996c() == 6) {
        switch (FUN_0232ca3c()) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 5;
        }
    }
    return 4;
}
