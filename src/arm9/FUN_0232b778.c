// decomp: module=unk_autoload_0 addr=0x0232b778 name=FUN_0232b778
extern void (*G_023bd5ec)(int);

void FUN_0232b778(int *p)
{
    if (G_023bd5ec != 0)
        G_023bd5ec(*p);
    *p = 0;
}
