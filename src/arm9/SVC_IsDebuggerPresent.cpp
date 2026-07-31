// decomp: module=unk_autoload_0 addr=0x02332d42 name=SVC_IsDebuggerPresent
#pragma thumb on
extern "C" asm void SVC_IsDebuggerPresent(void) {
    swi 0x10
    bx lr
}
