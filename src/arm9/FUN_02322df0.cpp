//cpp
// flags: -O1,s
// decomp: module=unk_autoload_0 addr=0x02322df0 name=FUN_02322df0
#pragma opt_strength_reduction off
extern "C" void FUN_02322df0(unsigned char *p, int length) {
  p[0] = 10;
  for (unsigned int j = 1; j < 6; ++j) p[j] = 0;
  if (length > 16) length = 16;
  for (int i = 0; i < length; ++i) (p+i)[6] = 28;
}
