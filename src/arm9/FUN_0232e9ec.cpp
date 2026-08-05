//cpp
// decomp: module=unk_autoload_0 addr=0x0232e9ec name=FUN_0232e9ec

// The FUN_0232e9d8 shape with one more argument, forwarding to FUN_02337730.

#pragma thumb on
extern "C" {
extern void FUN_02337730(unsigned int, int, int);
void FUN_0232e9ec(volatile int *p, int a, int b)
{
    if (*p != 0) FUN_02337730(*(unsigned char *)(*p + 0x3c), a, b);
}
}
