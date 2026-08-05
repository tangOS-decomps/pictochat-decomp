// decomp: module=arm7 addr=0x022c0fb4 name=FUN_022c0fb4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c0fb4 --addr 0x022c0fb4 --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022c0fb4(int *param_1)

{
  if (*param_1 != 0) {
    FUN_022c0fec(*DAT_022c0fe8 + 0x200);
    FUN_022c0e48(2,0xb);
  }
  return;
}

