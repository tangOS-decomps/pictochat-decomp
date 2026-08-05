// decomp: module=unk_autoload_0 addr=0x02332934 name=FUN_02332934
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e, thumb
// triage: noise=4 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02332934 --addr 0x02332934 --size 0x2e --module unk_autoload_0 --version 2.0/sp1


void FUN_02332934(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0233831c(0xd,param_1,0,param_4,param_4);
  while (iVar1 != 0) {
    FUN_02332d10(1);
    iVar1 = FUN_0233831c(0xd,param_1,0);
  }
  return;
}

