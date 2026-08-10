//cpp
// decomp: module=unk_autoload_0 addr=0x0232c85c name=FUN_0232c85c
#pragma thumb on
extern "C" {
extern unsigned int G_023bd8a0[];
extern unsigned int FUN_02332080(void);
extern void FUN_02332094(unsigned int);
unsigned short FUN_0232c85c(void)
{
    unsigned int result;
    unsigned int irq = FUN_02332080();
    void *object = (void *)G_023bd8a0[1];
    if (object != 0) {
        result = *(unsigned int *)((unsigned char *)object + 0x14c);
    } else {
        result = 0;
    }
    FUN_02332094(irq);
    return result;
}
}
