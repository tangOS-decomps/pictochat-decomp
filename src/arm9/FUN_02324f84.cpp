// decomp: module=unk_autoload_0 addr=0x02324f84 name=FUN_02324f84
// Subsystem: WirelessManager / Network Session
// Purpose: Queries whether PictoChat is connected to an active wireless chat room session
extern "C" {
    struct S_02324f84 { char pad[0x2c]; int f2c; };
    extern struct S_02324f84 G_02324f84;
    int FUN_02324f84(void) { return G_02324f84.f2c == 1; }
}
