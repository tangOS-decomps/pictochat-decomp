//cpp
// decomp: module=unk_autoload_0 addr=0x0232d9fc name=FUN_0232d9fc
extern "C" unsigned int G_02369d10[];
extern "C" void FUN_0232da34(void *, void *, void *);
extern "C" void FUN_023374b8(void *, void *, unsigned int);
extern "C" void FUN_0232d9fc(void *a, void *b, unsigned int c, void *d) {
  unsigned char work[256];
  G_02369d10[1] = (G_02369d10[1] & 0x80000000) | ((c - 1) & 0x7fffffff);
  FUN_0232da34(a, d, work);
  FUN_023374b8(d, b, 0x340);
}
