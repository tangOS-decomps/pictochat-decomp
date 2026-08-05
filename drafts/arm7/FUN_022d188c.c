// decomp: module=arm7 addr=0x022d188c name=FUN_022d188c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=6  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d188c --addr 0x022d188c --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022d188c(uint param_1)

{
  param_1 = param_1 ^ (uint)*DAT_022d18a4 << 1;
  *DAT_022d18a4 = (ushort)param_1 ^ (ushort)(param_1 >> 0x10);
  return;
}

