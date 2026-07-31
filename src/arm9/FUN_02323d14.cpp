// decomp: module=unk_autoload_0 addr=0x02323d14 name=FUN_02323d14
// Subsystem: InputController / Touch Screen
// Purpose: Checks whether a soft keyboard touch-down event is active
extern "C" {
    struct S_02323d14 { char pad[0xc]; int fc; };
    extern struct S_02323d14 G_02323d14;
    int FUN_02323d14(void) { return G_02323d14.fc != 0; }
}
