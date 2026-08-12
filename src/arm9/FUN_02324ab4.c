// decomp: module=unk_autoload_0 addr=0x02324ab4 name=FUN_02324ab4
#pragma thumb on
// flags: -O4,s

extern int G_0239be54[];
extern unsigned short FUN_02322884(int, int);
extern unsigned short FUN_02322894(int, int);
extern void FUN_02336428(unsigned int *, unsigned int, unsigned int,
                         unsigned int, unsigned int);
extern void FUN_0232234c(void);
extern void FUN_02322004(void);
extern void FUN_02325040(void);

int FUN_02324ab4(void)
{
    unsigned int a;
    unsigned int b;
    int result;

    if (G_0239be54[0x14 / 4] < 0x10)
        G_0239be54[0x14 / 4]++;
    a = FUN_02322884(G_0239be54[0x14 / 4], 0x10);
    b = FUN_02322894(G_0239be54[0x14 / 4], 0x10);
    FUN_02336428((unsigned int *)0x04001050, 0x10, 0xf, b, a);
    FUN_0232234c();
    FUN_02322004();
    FUN_02325040();
    if (G_0239be54[0x14 / 4] == 0x10)
        result = 1;
    else
        result = 0;
    return result;
}
