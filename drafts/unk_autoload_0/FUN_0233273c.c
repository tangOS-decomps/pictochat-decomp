// decomp: module=unk_autoload_0 addr=0x0233273c name=FUN_0233273c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e, thumb
// triage: noise=4 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0233273c --addr 0x0233273c --size 0x2e --module unk_autoload_0 --version 2.0/sp1


void FUN_0233273c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0233831c(0xe,param_1,0,param_4,param_4);
  while (iVar1 != 0) {
    FUN_02332d10(param_2);
    iVar1 = FUN_0233831c(0xe,param_1,0);
  }
  return;
}

