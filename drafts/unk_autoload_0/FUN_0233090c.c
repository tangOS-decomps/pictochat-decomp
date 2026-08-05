// decomp: module=unk_autoload_0 addr=0x0233090c name=FUN_0233090c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=5 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0233090c --addr 0x0233090c --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0233090c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  iVar1 = FUN_023309a4();
  while (0 < iVar1) {
    FUN_02332d10(0x400);
    iVar1 = FUN_023309a4(param_1,param_2,param_3,param_4,uVar2);
  }
  return;
}

