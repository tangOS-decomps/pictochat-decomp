//cpp
// decomp: module=unk_autoload_0 addr=0x0233731c name=FUN_0233731c
extern "C" unsigned int FUN_02332080();
extern "C" void FUN_02332094(unsigned int);
extern "C" void FUN_0233731c(unsigned int channel) {
  unsigned int token = FUN_02332080();
  unsigned int offset = channel * 12;
  unsigned int mask = 0x80000000;
  volatile unsigned int *status = (volatile unsigned int *)0x040000b8;
  while (*(volatile unsigned int *)((unsigned int)status + offset) & mask) {}
  if (channel == 0) {
    volatile unsigned int *regs = (volatile unsigned int *)(0x040000b0 + offset);
    regs[0] = 0; regs[1] = 0; regs[2] = 0x81400001;
  }
  FUN_02332094(token);
}
