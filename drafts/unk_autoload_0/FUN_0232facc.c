// decomp: module=unk_autoload_0 addr=0x0232facc name=FUN_0232facc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232facc --addr 0x0232facc --size 0x44 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232facc(int param_1,undefined4 param_2,int param_3)

{
  int b;
  void *pvVar1;
  
  b = FUN_0232f74c();
  if (b == 0) {
    if (param_3 == 0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = FUN_0232f54c();
    }
    b = FUN_0232fa24(param_1,DAT_0232fb0c,pvVar1,param_1,param_2);
    if ((param_3 != 0) && (b != 0)) {
      FUN_0232f76c(param_1,b);
    }
  }
  return b;
}

