// decomp: module=unk_autoload_0 addr=0x02339318 name=FUN_02339318
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=35
// verify:  python tools/match.py --c <file> --func FUN_02339318 --addr 0x02339318 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339318(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == 0) {
    if (param_2 == 1) {
      iVar2 = 6;
    }
    if (param_2 == 0) {
      iVar2 = 7;
    }
  }
  else if (param_1 == 1) {
    if (param_2 == 1) {
      iVar2 = 4;
    }
    if (param_2 == 0) {
      iVar2 = 5;
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 1) {
      iVar2 = 8;
    }
    if (param_2 == 0) {
      iVar2 = 9;
    }
  }
  if (iVar2 != 0) {
    uVar1 = FUN_02339250(iVar2,0,0,param_3,param_4,param_4);
    return uVar1;
  }
  return DAT_02339370;
}

