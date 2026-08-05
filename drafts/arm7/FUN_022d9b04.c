// decomp: module=arm7 addr=0x022d9b04 name=FUN_022d9b04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022d9b04 --addr 0x022d9b04 --size 0x5c --module arm7 --version 2.0/sp1


void FUN_022d9b04(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_022d9b5c;
  uVar1 = func_0x037c9084(0x1000000);
  if (*(short *)(iVar2 + 0x1b4) == 0) {
    FUN_022da128(0);
  }
  func_0x037c5a18(param_1,iVar2 + 0x1ac,param_2);
  func_0x037c904c(uVar1);
  return;
}

