// decomp: module=unk_autoload_0 addr=0x02339908 name=FUN_02339908
extern char G_023c35a0[];
extern void FUN_023381f8(void);
extern int FUN_023382f8(int ch, int a);
extern void FUN_023382ac(int ch, void (*cb)(void));
extern void FUN_02339ae4(void);

void FUN_02339908(void) {
    if (*(unsigned short *)G_023c35a0 != 0) {
        return;
    }
    *(unsigned short *)G_023c35a0 = 1;
    *(int *)(G_023c35a0 + 0x4) = 0;
    *(int *)(G_023c35a0 + 0x8) = 0;
    *(int *)(G_023c35a0 + 0x20) = 0;
    *(int *)(G_023c35a0 + 0xc) = 0;
    *(int *)(G_023c35a0 + 0x10) = 0;
    FUN_023381f8();
    while (FUN_023382f8(5, 1) == 0) {
    }
    FUN_023382ac(5, FUN_02339ae4);
}
