//cpp
#pragma opt_common_subs off
// decomp: module=unk_autoload_0 addr=0x023278ac name=FUN_023278ac
extern "C" unsigned int G_0239fe38[];
extern "C" void FUN_0232fdec(void *, unsigned int, int);
extern "C" void FUN_023278ac(int value) {
  G_0239fe38[1] = 0;
  FUN_0232fdec((void *)0x0239fe38, 0, value);
  switch (value) {
    case 13: G_0239fe38[2] = 2; break;
    case 14: G_0239fe38[2] = 10; break;
  }
}
