//cpp
// decomp: module=unk_autoload_0 addr=0x0232f900 name=FUN_0232f900
// verify: python tools/match.py --c src/arm9/FUN_0232f900.cpp --func FUN_0232f900 --addr 0x0232f900 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
typedef unsigned short u16;
typedef unsigned int u32;

u16 *FUN_0232f5a4(int);
int FUN_0232fa88(int, int, int);
int FUN_0232f74c(int);
struct Context_0232f900 {
    u32 value : 24;
    u32 flags : 8;
};

Context_0232f900 *FUN_0232f5f0(u16);
int FUN_0232f9c8(u16, int, int, int, int *);
int FUN_0232fd24(int, int, int, u32, int);
void FUN_02337fa0(int, int, int);

int FUN_0232f900(int source, int flags, int arg2, int arg3, int *out)
{
    int i;
    u16 *item;
    int handle;
    register Context_0232f900 *context;
    int local;
    int error;

    item = FUN_0232f5a4(source);

    if (item == 0) {
        return 4;
    }
    if (flags & 2) {
        handle = FUN_0232fa88(*(int *)item, arg2, arg3);
        if (handle == 0) {
            return 8;
        }
    } else {
        handle = FUN_0232f74c(*(int *)item);
    }

    for (i = 0; i < 4; i++, item++) {
        if (0xffff != item[2]) {
            context = FUN_0232f5f0(item[2]);
            if (context == 0) {
                return 5;
            }
            error = FUN_0232f9c8(item[2], flags, arg2, arg3, &local);
            if (error != 0) {
                return error;
            }
            if ((context->flags & 1) && (flags & 4)) {
                if (FUN_0232fd24(local, handle, i, context->value, arg2) == 0) {
                    return 9;
                }
            }
            if (handle != 0 && local != 0) {
                FUN_02337fa0(handle, i, local);
            }
        }
    }
    if (out != 0) {
        *out = handle;
    }
    return 0;
}
}
