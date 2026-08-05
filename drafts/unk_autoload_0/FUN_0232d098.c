// decomp: module=unk_autoload_0 addr=0x0232d098 name=FUN_0232d098
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x6a - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=22
// verify:  python tools/match.py --c <file> --func FUN_0232d098 --addr 0x0232d098 --size 0x70 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232d098(int param_1,int param_2,uint param_3,undefined4 param_4,undefined2 param_5,
                undefined1 param_6)

{
  int iVar1;
  
  iVar1 = FUN_0232c520(2,7,9);
  if (iVar1 == 0) {
    if (param_2 == 0) {
      return 6;
    }
    if (0x70 < param_3) {
      return 6;
    }
    FUN_02337424(param_2,DAT_0232d104,param_3);
    FUN_023314e8(DAT_0232d104,param_3);
    FUN_0232c3bc(0x18,param_1);
    iVar1 = FUN_0232c408(0x18,5,DAT_0232d104,param_3,param_4,param_5,param_6);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

