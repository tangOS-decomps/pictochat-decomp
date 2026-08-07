// decomp: module=unk_autoload_0 addr=0x02321684 name=FUN_02321684
#pragma thumb on

extern int FUN_02321d14(int d);
extern void FUN_02321a6c(int a, int b, int c, int d, int e, int f, int g, int h);

void FUN_02321684(void *self, int b, int c)
{
    FUN_02321a6c(*(int *)((char *)self + 0x24), self, b, (unsigned short)FUN_02321d14(c), c, 0, 0, -1);
}
