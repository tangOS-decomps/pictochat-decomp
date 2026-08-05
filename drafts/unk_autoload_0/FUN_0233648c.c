// decomp: module=unk_autoload_0 addr=0x0233648c name=FUN_0233648c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=4  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233648c --addr 0x0233648c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_0233648c(void)

{
  return ((int)(*DAT_023364a4 & 0x1f00) >> 8) * 0x800 + 0x6200000;
}

