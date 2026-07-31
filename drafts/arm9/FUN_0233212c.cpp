// decomp: module=unk_autoload_0 addr=0x0233212c name=FUN_0233212c
// Ghidra's cached size (4) excluded the trailing literal-pool word (the
// G_02fffc40 address) - true size is 8. Called by FUN_02332120, which
// immediately does a halfword read on the returned pointer.
extern short G_02fffc40;

short *FUN_0233212c(void) {
    return &G_02fffc40;
}
