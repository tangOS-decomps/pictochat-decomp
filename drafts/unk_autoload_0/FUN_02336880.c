// decomp: module=unk_autoload_0 addr=0x02336880 name=FUN_02336880
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02336880 --addr 0x02336880 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02336880(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  if ((*DAT_023368b8 != -1) && (0x1c < param_3)) {
    FUN_023372b0(*DAT_023368b8,param_1,param_2 + DAT_023368bc,param_3,1);
    return;
  }
  FUN_02337424(param_1,param_2 + DAT_023368bc,param_3,param_3,param_4);
  return;
}

