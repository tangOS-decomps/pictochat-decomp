//cpp
// decomp: module=unk_autoload_0 addr=0x02339084 name=FUN_02339084
extern "C" unsigned int G_023c3564[];
extern "C" volatile unsigned int G_023c3590;
extern "C" unsigned int FUN_023320d8();
extern "C" void FUN_02338390();
extern "C" void FUN_02339084() {
  unsigned int busy = G_023c3564[11];
  volatile unsigned int *queue = &G_023c3590;
  while (busy) {
      if (FUN_023320d8() == 0x80 || *(volatile unsigned short *)0x04000208 == 0) FUN_02338390();
    busy = *queue;
  }
}
