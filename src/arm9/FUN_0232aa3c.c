// decomp: module=unk_autoload_0 addr=0x0232aa3c name=FUN_0232aa3c
#pragma thumb on

extern int FUN_0232981c(void);
extern int FUN_0232ad80(void);
extern int FUN_0232996c(void);
extern void FUN_0232ad10(void *);
extern void FUN_0232ac60(void *);
extern volatile unsigned short G_023bd698[];

void FUN_0232aa3c(void *p)
{
    int state;

    if (FUN_0232981c() != 0)
        return;
    if (FUN_0232ad80() != 0)
        return;

    state = FUN_0232996c();
    if (state != 7 && state != 6 && state != 0xa && state != 9)
        return;
    if (*(unsigned short *)((char *)p + 4) != 0x15)
        return;
    if (G_023bd698[6] != 0 && G_023bd698[6] < 0x10)
        FUN_0232ad10(p);
    else
        FUN_0232ac60(p);
}
