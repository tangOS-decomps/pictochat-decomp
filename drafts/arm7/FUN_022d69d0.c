// decomp: module=arm7 addr=0x022d69d0 name=FUN_022d69d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d69d0 --addr 0x022d69d0 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022d69d0(void)

{
  FUN_022d8bfc();
  FUN_022d7d30();
  FUN_022d875c();
  FUN_022d6d80();
  FUN_022d6c00();
  FUN_022d6e18(*(undefined4 *)(*DAT_022d6a18 + 0x31c),*(undefined2 *)(*DAT_022d6a18 + 800));
  FUN_022da700();
  FUN_022dc0cc();
  FUN_022da490();
  FUN_022d77ec();
  return;
}

