// decomp: module=unk_autoload_0 addr=0x0233844c name=FUN_0233844c
#pragma thumb on
int FUN_0233844c(unsigned int x)
{
    unsigned int idx = x - 9;
    int result = 0;
    if (idx > 0x1a)
        goto ret;
    if (!(0x0400030F & (1 << idx)))
        goto ret;
    result = 1;
ret:
    return result;
}
