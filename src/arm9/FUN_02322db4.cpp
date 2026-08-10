//cpp
// decomp: module=unk_autoload_0 addr=0x02322db4 name=FUN_02322db4
#pragma thumb on
extern "C" {
void FUN_0233ae70(void);
extern void (*G_0238ee3c)(void);
extern unsigned char G_0238ee44[];
void FUN_0232e980(void *);
void FUN_02322df0(void *, int);
void FUN_02322db4(void)
{
    unsigned char i = 0;
    G_0238ee3c = FUN_0233ae70;
    do {
        unsigned char *p = G_0238ee44 + i * 0x30;
        FUN_0232e980(p);
        *(int *)(p + 0x20) = 0;
        FUN_02322df0(p + 4, 0x10);
        ++i;
    } while (i < 4);
}
}
