// decomp: module=unk_autoload_0 addr=0x0232ad44 name=FUN_0232ad44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232ad44 --addr 0x0232ad44 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ad44(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  FUN_02337584(param_1,auStack_10,8);
  FUN_02337584(param_1 + 8,DAT_0232ad7c,0x60);
  FUN_0232a9f8();
  iVar1 = FUN_0232996c();
  if ((iVar1 == 8) || (iVar1 = FUN_0232996c(), iVar1 == 9)) {
    FUN_02329bd8(6);
  }
  return;
}

