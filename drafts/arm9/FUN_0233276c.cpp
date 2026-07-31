// decomp: module=unk_autoload_0 addr=0x0233276c name=FUN_0233276c
// Ghidra's cached size (0x12) excluded this function's trailing literal-
// pool words (the G_02fffc30 address and the 0xffff comparand) - true size
// is 0x1c. G_02fffc30 sits high in DSi's 16MB main-RAM range (this is a
// DSi title, not a plain DS one) - likely a sentinel/uninitialized-state
// halfword; this function reports whether it's still unset (0xffff).
extern unsigned short G_02fffc30;

int FUN_0233276c(void) {
    if (G_02fffc30 == 0xffff) {
        return 0;
    }
    return 1;
}
