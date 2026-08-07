// decomp: module=arm7 addr=0x022c6e50 name=FUN_022c6e50
// flags: -O4,s -noThumb

// One-shot registration: the first time the flag halfword at 0x03805220 is
// clear it is set and the handler at 0x037fc3a4 is installed for slot 0xc.
// FUN_022c6e88 is the ARM->Thumb veneer the linker parked immediately after
// this function; its real target is the Thumb entry 0x037fee30 (see lever 5 -
// the reloc resolves to the veneer, not the entry).
// NOTE: verify with --size 0x38, not funcs.json's 0x30 - the boundary excludes
// this function's own two trailing pool words.

extern void FUN_022c6e88(int slot, void *handler);

extern unsigned short G_03805220;

void FUN_022c6e50(void)
{
    if (G_03805220 == 0) {
        G_03805220 = 1;
        FUN_022c6e88(0xc, (void *)0x037fc3a4);
    }
}
