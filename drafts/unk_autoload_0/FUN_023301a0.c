// decomp: module=unk_autoload_0 addr=0x023301a0 name=FUN_023301a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023301a0 --addr 0x023301a0 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_023301a0(void)

{
  if (*DAT_023301b8 == 1) {
    FUN_0233791c(0);
  }
  FUN_0232f050();
  return;
}

