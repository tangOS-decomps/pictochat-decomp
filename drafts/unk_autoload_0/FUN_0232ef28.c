// decomp: module=unk_autoload_0 addr=0x0232ef28 name=FUN_0232ef28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ef28 --addr 0x0232ef28 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ef28(int param_1)

{
  if (*(int *)(param_1 + 0x2c) << 0x1f < 0) {
    FUN_0232ef7c();
  }
  return;
}

