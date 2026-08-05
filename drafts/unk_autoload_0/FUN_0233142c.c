// decomp: module=unk_autoload_0 addr=0x0233142c name=FUN_0233142c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0233142c --addr 0x0233142c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233142c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x8c);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x88) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x10) = param_2;
  }
  *(int *)(param_2 + 0x14) = iVar1;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(int *)(param_1 + 0x8c) = param_2;
  return;
}

