// decomp: module=unk_autoload_0 addr=0x0232ac90 name=FUN_0232ac90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x22, thumb
// triage: noise=6 statements=14
// verify:  python tools/match.py --c <file> --func FUN_0232ac90 --addr 0x0232ac90 --size 0x22 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ac90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  
  uStack_8 = param_4;
  FUN_02337584(param_1,auStack_10,8);
  FUN_0232a824();
  iVar1 = FUN_0232996c();
  if (iVar1 == 10) {
    FUN_02329bd8(7);
  }
  return;
}

