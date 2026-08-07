// decomp: module=arm7 addr=0x022c1ff4 name=FUN_022c1ff4
// flags: -O4,s -noThumb

// Runs the wireless-hardware reset helper, then clears every pending source in
// the 0x048081ac status halfword and re-arms the 0x04808010 control halfword
// with 0x30.

// UNRESOLVED CALLEE: the leading BL encodes a pc-relative displacement that
// resolves to 0x00dd3a08, which is not a mapped ARM7 address (ARM7 code lives
// in main RAM at 0x02xxxxxx or in shared WRAM at 0x037xxxxx).  The BL slot is
// almost certainly an unapplied relocation in the extracted image rather than a
// real target, so `func_00dd3a08` is a placeholder name, NOT a resolved callee.
// match.py wildcards relocation slots, so this does not affect the byte match -
// but the callee identity is still unknown and must not be treated as settled.
extern void func_00dd3a08(void);

void FUN_022c1ff4(void)
{
    func_00dd3a08();
    *(volatile unsigned short *)0x048081ac = 0xffff;
    *(volatile unsigned short *)0x04808010 = 0x30;
}
