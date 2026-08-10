//cpp
// decomp: module=unk_autoload_0 addr=0x02337440 name=FUN_02337440
// flags: -O4,p -noThumb

// Runtime word-fill primitive. This was assembly in the original runtime.
extern "C" {
asm void FUN_02337440(int value, int *dst, int len)
{
    add ip, r1, r2
loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loop
    bx lr
}
}
