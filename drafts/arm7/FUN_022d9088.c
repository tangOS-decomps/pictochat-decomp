// decomp: module=arm7 addr=0x022d9088 name=FUN_022d9088
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d9088 --addr 0x022d9088 --size 0x44 --module arm7 --version 2.0/sp1


void FUN_022d9088(ushort param_1)

{
  func_0x037c9084(0x1000000);
  *(ushort *)(*DAT_022d90c8 + 0x3f4) = *(ushort *)(*DAT_022d90c8 + 0x3f4) | param_1;
  func_0x037c904c();
  func_0x037c5628(2,0x15);
  return;
}

