//cpp
// decomp: module=unk_autoload_0 addr=0x02330fb4 name=FUN_02330fb4

#pragma thumb on
extern "C" {
extern int FUN_02332080(int*);
extern void FUN_02330c4c(void);
extern void FUN_02332094(int);
void FUN_02330fb4(int* a) { int b = FUN_02332080(a); a[25] = 1; FUN_02330c4c(); FUN_02332094(b); }
}
