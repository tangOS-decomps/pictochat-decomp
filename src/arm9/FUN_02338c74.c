// decomp: module=unk_autoload_0 addr=0x02338c74 name=FUN_02338c74
extern char G_023c3528[];
extern void FUN_023381f8(void);
extern int FUN_023382f8(int ch, int a);
extern void FUN_023382ac(int ch, void (*cb)(void));
extern void FUN_02338b04(void);

void FUN_02338c74(void) {
    if (*(unsigned short *)G_023c3528 != 0) {
        return;
    }
    *(unsigned short *)G_023c3528 = 1;
    FUN_023381f8();
    *(unsigned short *)(G_023c3528 + 0x10) = 0;
    *(int *)(G_023c3528 + 0x4) = 0;
    *(int *)(G_023c3528 + 0x14) = 0;
    *(unsigned short *)(G_023c3528 + 0x36) = 0;
    *(unsigned short *)(G_023c3528 + 0x34) = 0;
    *(unsigned short *)(G_023c3528 + 0x3a) = 0;
    *(unsigned short *)(G_023c3528 + 0x38) = 0;
    while (FUN_023382f8(6, 1) == 0) {
    }
    FUN_023382ac(6, FUN_02338b04);
}
