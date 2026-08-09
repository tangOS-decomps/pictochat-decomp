//cpp
// decomp: module=unk_autoload_0 addr=0x0232ae14 name=FUN_0232ae14

#pragma thumb on
typedef unsigned short u16;

extern "C" {
extern char G_023bd698[];
extern int FUN_0232981c(void);
extern void FUN_0232aabc(void);
extern void FUN_0232aadc(void *);
extern void FUN_0232ab40(void *);
extern void FUN_0232abc0(void *);
extern void FUN_0232ac1c(void *);
extern void FUN_02329bd8(int);

void FUN_0232ae14(void *param)
{
    char *p = (char *)param;
    if (FUN_0232981c() != 0) {
        FUN_0232aabc();
        return;
    }
    if (*(u16 *)(p + 2) != 0 || *(u16 *)(p + 8) != 9 ||
        *(int *)(G_023bd698 + 0x30) == 0) {
        if (*(u16 *)(p + 2) == 0) {
            int command = *(u16 *)(p + 8);
            switch (command) {
            case 0:
                FUN_0232aadc(param);
                return;
            case 2:
                FUN_0232ab40(param);
                return;
            case 7:
                FUN_0232abc0(param);
                return;
            case 9:
                FUN_0232ac1c(param);
                return;
            default:
                return;
            }
        } else {
            FUN_02329bd8(0xc);
        }
    }
}
}
