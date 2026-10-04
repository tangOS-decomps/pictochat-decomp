//cpp
// decomp: module=unk_autoload_0 addr=0x023374f0 name=FUN_023374f0
// flags: -noThumb

// Byte fill (MI_CpuFill8): fills `size` bytes at `dst` with `value` using only
// halfword and word stores, merging a leading/trailing odd byte into the
// neighbouring halfword. Hand-written ARM in the original SDK, like its
// neighbours FUN_02337440 and FUN_023374b8. C cannot reproduce it: the ROM
// keeps `subs` after the odd-byte store, uses ip then a fresh r3 for the
// leading merge and a fresh ip for the end pointer while r3 is already dead -
// mwccarm hoists the subs and reuses the dead register (best C draft: 14/37).
extern "C" {
asm void FUN_023374f0(void *dst, unsigned char value, unsigned int size)
{
    cmp r2, #0
    bxeq lr
    tst r0, #1
    beq @even
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    bxeq lr
@even:
    cmp r2, #2
    blo @tail
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq @words
    strh r1, [r0], #2
    subs r2, r2, #2
    bxeq lr
@words:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq @half
    sub r2, r2, r3
    add ip, r3, r0
@loop:
    str r1, [r0], #4
    cmp r0, ip
    blo @loop
@half:
    tst r2, #2
    strneh r1, [r0], #2
@tail:
    tst r2, #1
    bxeq lr
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}
}
