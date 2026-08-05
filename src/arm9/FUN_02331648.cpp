//cpp
// decomp: module=unk_autoload_0 addr=0x02331648 name=FUN_02331648

// Brings up channel 2: reset, then read-back/apply through two getter-setter
// pairs, then FUN_023318d4(1, 0x2000000, 0x2a).

#pragma thumb on
extern "C" {
extern void FUN_023311d8(void);
extern int FUN_02331678(int);
extern void FUN_0233178c(int, int);
extern int FUN_02331718(int);
extern void FUN_02331798(int, int);
extern void FUN_023318d4(int, int, int);
void FUN_02331648(void)
{
    int v;
    FUN_023311d8();
    v = FUN_02331678(2);
    FUN_0233178c(2, v);
    v = FUN_02331718(2);
    FUN_02331798(2, v);
    FUN_023318d4(1, 0x2000000, 0x2a);
}
}
