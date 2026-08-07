// decomp: module=arm7 addr=0x022c8254 name=FUN_022c8254
extern unsigned short FUN_022c8600(int value);

void FUN_022c8254(void *object, int value)
{
    *(unsigned short *)((char *)object + 0x1e) = FUN_022c8600(value);
}
