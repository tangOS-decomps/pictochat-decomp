//cpp
// decomp: module=unk_autoload_0 addr=0x02331534 name=FUN_02331534
// flags: -O4,p -noThumb

// Hardware primitive: temporarily masks interrupts, waits for VCOUNT zero,
// then restores the previous IME word. Its register sequence is the operation.
extern "C" {
asm void FUN_02331534(void)
{
    mov ip, #0x04000000
    ldr r1, [ip, #0x208]
    str ip, [ip, #0x208]
wait_vcount:
    ldrh r0, [ip, #6]
    cmp r0, #0
    bne wait_vcount
    str r1, [ip, #0x208]
    bx lr
}
}
