// decomp: module=unk_autoload_0 addr=0x02331a3c name=FUN_02331a3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02331a3c --addr 0x02331a3c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02331a3c(void)

{
  if (*DAT_02331a4c != 0) {
    *DAT_02331a54 = DAT_02331a50;
  }
  return;
}

