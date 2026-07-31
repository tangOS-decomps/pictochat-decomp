// decomp: module=unk_autoload_0 addr=0x02321f9c name=FUN_02321f9c
extern "C" {
    extern void FUN_02321f74(void);
    extern int FUN_02321684(void *, void *, int);
    struct S_1f9c { char pad[0x14]; int f14; };
    extern struct S_1f9c G_1f9c;
    extern int G2_1f9c[];
    extern int G3_1f9c[];
    void FUN_02321f9c(void) {
        FUN_02321f74();
        FUN_02321684(G2_1f9c, G3_1f9c, G_1f9c.f14);
    }
}
