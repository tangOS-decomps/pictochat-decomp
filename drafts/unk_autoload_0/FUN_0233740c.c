// decomp: module=unk_autoload_0 addr=0x0233740c name=FUN_0233740c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0233740c --addr 0x0233740c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233740c(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 2) {
    *(undefined2 *)(param_2 + iVar1) = param_1;
  }
  return;
}

