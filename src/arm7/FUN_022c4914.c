// decomp: module=arm7 addr=0x022c4914 name=FUN_022c4914
// flags: -O4,s -noThumb
// Dispatches on the 7-bit sub-command packed into bits 8..14 of the second
// word.  Sub-command 0x10 is handled locally by raising the flag at
// 0x03804f60; everything else is forwarded to FUN_022c6e94.  The first
// parameter is unused by this handler.
// NOTE: verify with --size 0x34, not funcs.json's 0x30 - the stated size
// excludes this function's own trailing pool word.
extern unsigned short G_03804f60;
extern void FUN_022c6e94(unsigned short cmd);

void FUN_022c4914(int unused, unsigned int word) {
    unsigned short cmd = (unsigned short)((word & 0x7f00) >> 8);

    if (cmd == 0x10) {
        G_03804f60 = 1;
    } else {
        FUN_022c6e94(cmd);
    }
}
