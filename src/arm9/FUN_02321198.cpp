// decomp: module=unk_autoload_0 addr=0x02321198 name=FUN_02321198
extern "C" {
    extern int PTR_1198[];
    extern void F_1198(int, void *, int);
    struct S_1198 { char pad[0x24]; int flag; };
    extern struct S_1198 G2_1198;
    void FUN_02321198(void) {
        F_1198(0, PTR_1198, 0x28);
        G2_1198.flag = 1;
    }
}
