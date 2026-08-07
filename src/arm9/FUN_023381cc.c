// decomp: module=unk_autoload_0 addr=0x023381cc name=FUN_023381cc
extern void FUN_02337980(void);
extern void FUN_02337990(void);

void *FUN_023381cc(char *base, int index)
{
    FUN_02337980();
    unsigned int v = *(unsigned int *)(base + index * 4 + 0x3c);
    void *result;

    if (v != 0) {
        if (v < 0x02000000) {
            result = base + v;
        } else {
            result = (void *)v;
        }
    } else {
        result = 0;
    }

    FUN_02337990();
    return result;
}
