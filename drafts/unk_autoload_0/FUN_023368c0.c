// decomp: module=unk_autoload_0 addr=0x023368c0 name=FUN_023368c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_023368c0 --addr 0x023368c0 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_023368c0(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  if ((*DAT_023368fc != -1) && (0x30 < param_3)) {
    FUN_02337240(*DAT_023368fc,param_1,param_2 + 0x7000000,param_3,1);
    return;
  }
  FUN_02337454(param_1,param_2 + 0x7000000,param_3,param_3,param_4);
  return;
}

