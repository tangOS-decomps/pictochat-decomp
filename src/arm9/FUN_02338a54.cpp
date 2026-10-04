//cpp
// decomp: module=unk_autoload_0 addr=0x02338a54 name=FUN_02338a54
extern "C" {
extern int FUN_0233895c(void *, int, int);
int FUN_02338a54(unsigned char *self, int arg1, int arg2) {
    int args[2];
    *(int **)(self + 16) = args;
    args[0] = arg1;
    args[1] = arg2;
    if (FUN_0233895c(self, 0, 1)) arg2 = args[1];
    else if (*(int *)(self + 20) == 6) arg2 = -1;
    else arg2 = args[1];
    return arg2;
}
}
