//cpp
// decomp: module=unk_autoload_0 addr=0x0232fb10 name=FUN_0232fb10
// verify: python tools/match.py --c src/arm9/FUN_0232fb10.cpp --func FUN_0232fb10 --addr 0x0232fb10 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1

extern "C" {
int FUN_0232f74c(int);
int FUN_0232f6a8(int, void *, int, int);
void *FUN_0232f54c(void);
int FUN_0232f84c(int, int, void *, void *, int);
void FUN_02337584(void *, void *, int);
void FUN_023374f0(void *, int, int);
void FUN_023314e8(void *, int);
void FUN_0232f76c(int, int);

struct Global_023bf014 {
    char pad00[0x38];
    int count;
};

extern Global_023bf014 G_023bf014;

int FUN_0232fb10(int input, int owner, int notify)
{
    int result = FUN_0232f74c(input);
    if (result == 0) {
        int n4;
        int n8;
        void *context;

        if (FUN_0232f6a8(input, (void *)0x023bf014, 0x3c, 0) != 0x3c) {
            return 0;
        }
        n4 = G_023bf014.count * 4;
        n8 = n4 * 2 + 0x3c;
        if (owner == 0) {
            return 0;
        }
        context = notify ? FUN_0232f54c() : 0;
        result = FUN_0232f84c(owner, n8 + 0x20, (void *)0x0232fc55, context, input);
        if (result == 0) {
            return 0;
        }
        int copied = FUN_0232f6a8(input, (void *)result, n4 + 0x3c, 0);
        if (copied != n4 + 0x3c) {
            return 0;
        }
        FUN_02337584((void *)(result + 0x3c),
                     (void *)(result + 0x3c + *(int *)(result + 0x38) * 4), n4);
        FUN_023374f0((void *)(result + 0x3c), 0, n4);
        FUN_023314e8((void *)result, n8);
        if (notify) {
            FUN_0232f76c(input, result);
        }
    }
    return result;
}
}
