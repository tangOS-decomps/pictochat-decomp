// decomp: module=unk_autoload_0 addr=0x0232c884 name=FUN_0232c884
#pragma thumb on
extern unsigned int G_023bd8a0[];
extern unsigned int G_023bd8a8;
extern void FUN_0232c8b8(void);
extern void FUN_02339878(unsigned int *, int);

void FUN_0232c884(void)
{
    G_023bd8a0[2] = (unsigned int)FUN_0232c8b8;
    G_023bd8a0[3] = 0;
    FUN_02339878(&G_023bd8a8, 1000);
}
