// decomp: module=arm7 addr=0x022c9c18 name=FUN_022c9c18
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022c9c18 --addr 0x022c9c18 --size 0x30 --module arm7 --version 2.0/sp1


void FUN_022c9c18(void)

{
  undefined4 in_r3;
  
  thunk_EXT_FUN_037fd118(DAT_022c9c38,DAT_022c9c3c,8,in_r3,in_r3);
  FUN_022c73a0(7,DAT_022c9c40);
  *DAT_022c9c44 = 0;
  return;
}

