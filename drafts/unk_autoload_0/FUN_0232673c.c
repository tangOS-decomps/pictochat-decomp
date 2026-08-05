// decomp: module=unk_autoload_0 addr=0x0232673c name=FUN_0232673c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x26, thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232673c --addr 0x0232673c --size 0x26 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232673c(int param_1)

{
  while ((param_1 < 0 || (0x3ff < param_1))) {
    if (param_1 < 0x400) {
      if (param_1 < 0) {
        param_1 = param_1 + 0x400;
      }
    }
    else {
      param_1 = param_1 + -0x400;
    }
  }
  return;
}

