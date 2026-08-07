// decomp: module=unk_autoload_0 addr=0x0232f74c name=FUN_0232f74c
#pragma thumb on
extern int G_023bf010[];
int FUN_0232f74c(unsigned int i)
{
    int base = *(int *)(G_023bf010[0] + 0x84);
    if (i >= *(unsigned int *)(base + 8)) return 0;
    return *(int *)(base + i * 0x10 + 0x14);
}
