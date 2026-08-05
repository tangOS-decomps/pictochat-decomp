// decomp: module=arm7 addr=0x022d81b8 name=FUN_022d81b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=6  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d81b8 --addr 0x022d81b8 --size 0x30 --module arm7 --version 2.0/sp1


void FUN_022d81b8(void)

{
  FUN_022d81e8();
  func_0x037cb7a8(0,*DAT_022d81e4 + 0x53c,0xb4);
  return;
}

