//cpp
// decomp: module=unk_autoload_0 addr=0x02331d84 name=FUN_02331d84
struct State {unsigned short flag; unsigned short pad; unsigned int a,b;};
extern "C" State G_023c0af0;
extern "C" void FUN_02331be8();
extern "C" void FUN_023307f8(int);
extern "C" void FUN_02331d84(unsigned int unused) {
  unsigned short flag = G_023c0af0.flag;
  unsigned short *flagp = &G_023c0af0.flag;
  if (flag == 0) {
    *flagp = 1;
    FUN_02331be8();
    G_023c0af0.a = 0; G_023c0af0.b = 0;
    FUN_023307f8(16);
  }
}
