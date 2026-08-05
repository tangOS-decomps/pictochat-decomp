// decomp: module=unk_autoload_0 addr=0x0232dc4c name=FUN_0232dc4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232dc4c --addr 0x0232dc4c --size 0xe --module unk_autoload_0 --version 2.0/sp1


void FUN_0232dc4c(int param_1)

{
  if (*(short *)(param_1 + 8) == 0) {
    FUN_0232dbd0();
  }
  return;
}

