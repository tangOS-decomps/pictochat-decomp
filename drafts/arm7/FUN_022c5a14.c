// decomp: module=arm7 addr=0x022c5a14 name=FUN_022c5a14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5a14 --addr 0x022c5a14 --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022c5a14(void)

{
  if (*DAT_022c5a4c == 0) {
    *DAT_022c5a4c = 1;
    FUN_022c5a50();
    FUN_022c5a50(7);
    FUN_022c5a50(8);
  }
  return;
}

