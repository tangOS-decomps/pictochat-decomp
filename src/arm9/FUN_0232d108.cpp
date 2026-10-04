//cpp
// decomp: module=unk_autoload_0 addr=0x0232d108 name=FUN_0232d108
extern "C" {
extern char G_023be3e0[];
extern int G_02369d08;
extern void FUN_023371d8(int a);
extern void FUN_02332d32(void *src, void *dst, int ctrl);

void FUN_0232d108(int x) {
    int z;
    *(int *)(G_023be3e0 + 0x14) = 0x027ff800;
    *(int *)(G_023be3e0 + 0x0) = 0x02fff860;
    *(int *)(G_023be3e0 + 0x4) = 0x02fffc80;
    *(volatile unsigned short *)0x04000204 |= 0x8000;
    FUN_023371d8(3);
    z = 0;
    FUN_02332d32(&z, (void *)0x02fff860, 0x0100001b);
    G_02369d08 = x;
    *(volatile int *)0x02fff880 = 2;
}
}
