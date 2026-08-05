// decomp: module=unk_autoload_0 addr=0x02336c1c name=FUN_02336c1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02336c1c --addr 0x02336c1c --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02336c1c(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  void *pvVar1;
  
  pvVar1 = FUN_023366e8();
  if ((*DAT_02336c5c != -1) && (0x30 < param_3)) {
    FUN_02337240(*DAT_02336c5c,param_1,(int)pvVar1 + param_2,param_3,1,param_4);
    return;
  }
  FUN_02337454(param_1,(int)pvVar1 + param_2,param_3);
  return;
}

