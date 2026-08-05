// decomp: module=unk_autoload_0 addr=0x023392c0 name=FUN_023392c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=22
// verify:  python tools/match.py --c <file> --func FUN_023392c0 --addr 0x023392c0 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023392c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 1) {
    iVar1 = 1;
  }
  else if (param_1 == 2) {
    iVar1 = 3;
  }
  else if (param_1 == 3) {
    iVar1 = 2;
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    uVar2 = FUN_02339250(iVar1,0,0,param_2,param_3);
    return uVar2;
  }
  return DAT_023392f4;
}

