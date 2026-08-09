//cpp
// decomp: module=unk_autoload_0 addr=0x0232bb1c name=FUN_0232bb1c

#pragma thumb on
typedef unsigned short u16;

extern "C" {
extern int FUN_0232981c(void);
extern void FUN_02337584(void *, void *, int);
extern void FUN_0232ba40(void *, u16 *);
extern void FUN_0232ba7c(void *, u16 *);
extern void FUN_0232bac4(void *, u16 *);

void FUN_0232bb1c(void *param)
{
    u16 scratch[10];
    u16 command[10];
    char *p = (char *)param;

    if (FUN_0232981c() == 0) {
        if (*(u16 *)(p + 2) == 0 && *(u16 *)(p + 0x10) != 0 &&
            *(u16 *)(p + 4) == 0x15) {
            FUN_02337584(*(void **)(p + 0xc), scratch, 0x14);
        }
        if (*(u16 *)(p + 2) == 0 && *(u16 *)(p + 0x10) != 0 &&
            *(u16 *)(p + 4) == 0x15) {
            FUN_02337584(*(void **)(p + 0xc), command, 0x14);
            switch (command[0]) {
            case 0:
                FUN_0232ba40(param, command);
                return;
            case 1:
                FUN_0232ba7c(param, command);
                return;
            case 3:
                FUN_0232bac4(param, command);
                break;
            default:
                return;
            }
        }
    }
}
}
