// decomp: module=unk_autoload_0 addr=0x02323c84 name=FUN_02323c84
// Subsystem: InputController / Virtual Keyboard
// Purpose: Queries active soft keyboard layout index (QWERTY / Kana / Symbols)
extern "C" {
    extern unsigned short G_02323c84[];
    int FUN_02323c84(void) { return G_02323c84[23]; }
}
