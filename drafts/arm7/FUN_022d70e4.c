// decomp: module=arm7 addr=0x022d70e4 name=FUN_022d70e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022d70e4 --addr 0x022d70e4 --size 0x60 --module arm7 --version 2.0/sp1


undefined4 FUN_022d70e4(int param_1)

{
  func_0x037cb78c(param_1,DAT_022d7134,0x14);
  func_0x037cb78c(param_1 + 0x14,DAT_022d7138,0x14);
  func_0x037cb78c(param_1 + 0x28,DAT_022d713c,0x14);
  func_0x037cb78c(param_1 + 0x3c,DAT_022d7140,0x14);
  return 0;
}

