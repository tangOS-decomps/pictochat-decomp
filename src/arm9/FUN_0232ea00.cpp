//cpp
// decomp: module=unk_autoload_0 addr=0x0232ea00 name=FUN_0232ea00

// The FUN_0232e9d8 shape with one more argument, forwarding to FUN_02337740.

#pragma thumb on
extern "C" {
extern void FUN_02337740(unsigned int, int, int);
void FUN_0232ea00(volatile int *p, int a, int b)
{
    if (*p != 0) FUN_02337740(*(unsigned char *)(*p + 0x3c), a, b);
}
}
