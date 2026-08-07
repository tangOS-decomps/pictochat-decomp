// decomp: module=arm7 addr=0x022c5350 name=FUN_022c5350
// flags: -noThumb

extern int FUN_022c6d40(void);
extern void FUN_022c4e28(void);
extern void FUN_022c6d54(int state);

void FUN_022c5350(char *object)
{
    int state = FUN_022c6d40();
    *(int *)(object + 0x48) = 1;
    FUN_022c4e28();
    FUN_022c6d54(state);
}
