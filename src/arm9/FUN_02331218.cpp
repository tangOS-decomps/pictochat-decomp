//cpp
// decomp: module=unk_autoload_0 addr=0x02331218 name=FUN_02331218

#pragma thumb on
extern "C" {
extern int FUN_023311d8(void);
int FUN_02331218(void) { return (FUN_023311d8() & (1 << 28)) != 0; }
}
