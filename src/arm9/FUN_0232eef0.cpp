//cpp
// decomp: module=unk_autoload_0 addr=0x0232eef0 name=FUN_0232eef0
#pragma thumb on
extern "C" {
void FUN_02337768(int, int, int, int);
void FUN_0233984c(void *);
void FUN_02339864(void *);
void FUN_0232eef0(void *self)
{
    char *p = (char *)self;
    FUN_02337768(*(int *)(p + 0x4c), 0, 1 << *(int *)(p + 0x48), 0);
    if (((*(int *)(p + 0x2c) << 30) >> 31) == 0) {
        FUN_0233984c(p + 8);
        FUN_02339864(p + 0x18);
        *(unsigned int *)(p + 0x2c) |= 2;
    }
}
}
