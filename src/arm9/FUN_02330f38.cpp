//cpp
// decomp: module=unk_autoload_0 addr=0x02330f38 name=FUN_02330f38
extern "C" unsigned int FUN_02332080();
extern "C" void FUN_02332094(unsigned int);
extern "C" unsigned int G_023c07c4[];
extern "C" void FUN_02330b0c(unsigned int, unsigned int *);
extern "C" void FUN_02330c4c();
extern "C" void FUN_02330f38(unsigned int value) {
  unsigned int token = FUN_02332080();
  unsigned int *p = *(unsigned int **)G_023c07c4[2];
  if (value) {p[30] = value; FUN_02330b0c(value, p);}
  p[25] = 0;
  FUN_02330c4c();
  FUN_02332094(token);
}
