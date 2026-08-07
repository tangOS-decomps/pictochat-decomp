// decomp: module=unk_autoload_0 addr=0x0232e84c name=FUN_0232e84c
#pragma thumb on
extern int G_023be560[];

int FUN_0232e84c(int flags)
{
    if (flags & G_023be560[0])
        return 0;
    G_023be560[0] |= flags;
    return 1;
}
