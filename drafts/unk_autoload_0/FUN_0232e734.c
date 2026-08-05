// decomp: module=unk_autoload_0 addr=0x0232e734 name=FUN_0232e734
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232e734 --addr 0x0232e734 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e734(undefined4 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_0232e6bc();
  }
  if ((param_2 & 2) != 0) {
    FUN_0232e6cc(param_1);
  }
  return;
}

