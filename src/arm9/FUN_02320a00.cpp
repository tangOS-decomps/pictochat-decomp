// decomp: module=unk_autoload_0 addr=0x02320a00 name=FUN_02320a00
// test: comment-only touch to trigger PR link validation, no code change
extern int G[];
void FUN_02320a00(void) { G[2] = 1; }
