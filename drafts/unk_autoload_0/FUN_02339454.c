// decomp: module=unk_autoload_0 addr=0x02339454 name=FUN_02339454
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02339454 --addr 0x02339454 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02339454(undefined4 param_1)

{
  int iVar1;
  
  do {
    iVar1 = FUN_0233831c(8,param_1,0);
  } while (iVar1 != 0);
  return;
}

