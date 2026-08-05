// decomp: module=arm7 addr=0x022da01c name=FUN_022da01c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=4  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022da01c --addr 0x022da01c --size 0x20 --module arm7 --version 2.0/sp1


uint FUN_022da01c(uint param_1)

{
  return (int)(uint)*(ushort *)(*DAT_022da038 + 0x530) >> (param_1 & 0xff) & 1;
}

