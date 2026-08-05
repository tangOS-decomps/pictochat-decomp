// decomp: module=arm7 addr=0x022da700 name=FUN_022da700
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=5
// verify:  python tools/match.py --c <file> --func FUN_022da700 --addr 0x022da700 --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022da700(void)

{
  *(undefined2 *)(*DAT_022da718 + 0x428) = 0;
  return;
}

