// decomp: module=arm7 addr=0x022d8600 name=FUN_022d8600
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=6
// verify:  python tools/match.py --c <file> --func FUN_022d8600 --addr 0x022d8600 --size 0x2c --module arm7 --version 2.0/sp1


undefined2 FUN_022d8600(ushort param_1)

{
  *DAT_022d8624 = param_1 | 0x6000;
  func_0x037c849c();
  return *DAT_022d8628;
}

