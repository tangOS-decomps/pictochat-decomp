// decomp: module=arm7 addr=0x022c614c name=FUN_022c614c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c614c --addr 0x022c614c --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022c614c(uint param_1)

{
  *DAT_022c6164 = *DAT_022c6164 | (ushort)(1 << (param_1 & 0xff));
  return;
}

