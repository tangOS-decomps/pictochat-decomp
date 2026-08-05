// decomp: module=unk_autoload_0 addr=0x023392f8 name=FUN_023392f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=12
// verify:  python tools/match.py --c <file> --func FUN_023392f8 --addr 0x023392f8 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


int FUN_023392f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_8 [2];
  
  local_8[0] = param_4;
  iVar1 = FUN_023392c0(param_1,DAT_02339310,local_8);
  if (iVar1 == 0) {
    (*(code *)*DAT_02339314)();
    iVar1 = local_8[0];
  }
  return iVar1;
}

