// decomp: module=unk_autoload_0 addr=0x02321404 name=FUN_02321404
#pragma thumb on

struct Obj02321404 {
    char pad[0x24];
    void *f24;
};

extern int FUN_02321a94(int);
extern void FUN_023217ec(void *, void *, int, int, int, int, int, int);

void FUN_02321404(struct Obj02321404 *obj, int arg1, int arg2)
{
    int r = FUN_02321a94(arg2);
    r = r << 16;
    FUN_023217ec(obj->f24, obj, arg1, (unsigned int)r >> 16, arg2, 0, 0, -1);
}
