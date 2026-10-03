//cpp
// decomp: module=unk_autoload_0 addr=0x02337dd8 name=FUN_02337dd8
extern "C" unsigned int FUN_02332080();
extern "C" void FUN_02332094(unsigned int);
extern "C" unsigned int G_023c1960[];
extern "C" unsigned int *FUN_02337dd8() {
  unsigned int token = FUN_02332080();
  unsigned int *p = (unsigned int *)G_023c1960[0];
  if (!p) {FUN_02332094(token); return 0;}
  unsigned int next = p[0];
  G_023c1960[0] = next;
  if (!next) G_023c1960[4] = 0;
  FUN_02332094(token);
  return p;
}
