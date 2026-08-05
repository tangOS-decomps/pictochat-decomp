//cpp
#pragma thumb on
extern "C" {
extern int FUN_023311d8(void);
int FUN_02331218(void) { return (FUN_023311d8() & (1 << 28)) != 0; }
}