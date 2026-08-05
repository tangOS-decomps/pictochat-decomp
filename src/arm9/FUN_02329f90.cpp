//cpp
// decomp: module=unk_autoload_0 addr=0x02329f90 name=FUN_02329f90

// Sets the flag at G_023bd60c+0x10, registers G_023bd640 with FUN_02331ef0, then
// runs FUN_02329e80.

#pragma thumb on
extern "C" {
extern void FUN_02331ef0(int *);
extern void FUN_02329e80(void);
extern int G_023bd60c[];
extern int G_023bd640[];
void FUN_02329f90(void)
{
    G_023bd60c[4] = 1;
    FUN_02331ef0(G_023bd640);
    FUN_02329e80();
}
}
