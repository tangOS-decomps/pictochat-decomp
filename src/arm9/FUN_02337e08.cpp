//cpp
// decomp: module=unk_autoload_0 addr=0x02337e08 name=FUN_02337e08
extern "C" unsigned int FUN_02332080();
extern "C" void FUN_02332094(unsigned int);
extern "C" int FUN_02331218();
extern "C" int FUN_02337e08() {
  if (!FUN_02331218()) return 1;
  unsigned int token = FUN_02332080();
  volatile unsigned int *reg = (volatile unsigned int *)0x04fff200;
  *reg = 16;
  unsigned int value = *reg;
  FUN_02332094(token);
  if (value) return 1;
  return 0;
}
