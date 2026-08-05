//cpp
// decomp: module=unk_autoload_0 addr=0x0232d250 name=FUN_0232d250

#pragma thumb on
extern "C" {
extern void FUN_0232d260(int*);
void FUN_0232d250(void) {
    FUN_0232d260((int *)0x80000080);  // literal in the ROM, not a symbol address
}
}
