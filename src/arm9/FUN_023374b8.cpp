//cpp
// decomp: module=unk_autoload_0 addr=0x023374b8 name=FUN_023374b8
// flags: -O4,p -noThumb

// Fast word copy (32-byte ldm/stm blocks, then single words). Assembly in the
// original runtime, like its neighbour FUN_02337440.
extern "C" {
asm void FUN_023374b8(const void *src, void *dst, int len)
{
    stmfd sp!, {r4-r10}
    add r10, r1, r2
    mov ip, r2, lsr #5
    add ip, r1, ip, lsl #5
block:
    cmp r1, ip
    ldmltia r0!, {r2-r9}
    stmltia r1!, {r2-r9}
    blt block
word:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt word
    ldmfd sp!, {r4-r10}
    bx lr
}
}
