// decomp: module=unk_autoload_0 addr=0x02336940 name=FUN_02336940
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02336940 --addr 0x02336940 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02336940(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  if ((*DAT_02336978 != -1) && (0x30 < param_3)) {
    FUN_02337240(*DAT_02336978,param_1,param_2 + 0x6400000,param_3,1);
    return;
  }
  FUN_02337454(param_1,param_2 + 0x6400000,param_3,param_3,param_4);
  return;
}

