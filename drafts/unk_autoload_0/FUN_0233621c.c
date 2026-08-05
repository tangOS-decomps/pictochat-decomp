// decomp: module=unk_autoload_0 addr=0x0233621c name=FUN_0233621c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=2 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0233621c --addr 0x0233621c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233621c(undefined1 *param_1,int param_2)

{
  if (param_1 != (undefined1 *)0x0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return;
}

