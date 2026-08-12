// decomp: module=unk_autoload_0 addr=0x0232f080 name=FUN_0232f080
#pragma thumb on

extern void FUN_023305c8(int *);
extern int FUN_023305d8(int *);
extern int FUN_023305a8(int *);
extern void FUN_0232f304(void);
extern void FUN_02337848(int, int, int);
extern int G_023bef1c[];

void FUN_0232f080(void)
{
    int *state = G_023bef1c;
    int x;

    if (state[0] != 0 && state[1] == 0) {
        int *value = state + 0xf;

        FUN_023305c8(value);
        if (state[0x13] != 0 && FUN_023305d8(value) != 0) {
            FUN_0232f304();
            return;
        }
        x = FUN_023305a8(value) >> 8;
        if (x != state[0x14]) {
            FUN_02337848(state[9], x, 0);
            state[0x14] = x;
        }
    }
}
