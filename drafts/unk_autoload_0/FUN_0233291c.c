// decomp: module=unk_autoload_0 addr=0x0233291c name=FUN_0233291c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x16, thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0233291c --addr 0x0233291c --size 0x16 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233291c(undefined4 param_1,int *param_2)

{
  if (*param_2 == 0) {
    thunk_FUN_023309fc();
  }
  FUN_02332094(param_2[1]);
  return;
}

