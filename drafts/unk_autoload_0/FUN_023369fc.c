// decomp: module=unk_autoload_0 addr=0x023369fc name=FUN_023369fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_023369fc --addr 0x023369fc --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_023369fc(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0233648c();
  if ((*DAT_02336a3c != -1) && (0x1c < param_3)) {
    FUN_023372b0(*DAT_02336a3c,param_1,iVar1 + param_2,param_3,1,param_4);
    return;
  }
  FUN_02337424(param_1,iVar1 + param_2,param_3);
  return;
}

