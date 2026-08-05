// decomp: module=arm7 addr=0x022d6d80 name=FUN_022d6d80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d6d80 --addr 0x022d6d80 --size 0x58 --module arm7 --version 2.0/sp1


void FUN_022d6d80(void)

{
  int iVar1;
  
  iVar1 = *DAT_022d6dd4;
  FUN_022d6dd8(iVar1 + 0x194);
  FUN_022d6dd8(iVar1 + 0x1a0);
  FUN_022d6dd8(iVar1 + 0x1ac);
  FUN_022d6dd8(iVar1 + 0x1b8);
  FUN_022d6dd8(iVar1 + 0x1c4);
  FUN_022d6dd8(iVar1 + 0x1d0);
  FUN_022d6dd8(iVar1 + 0x1dc);
  FUN_022d6dd8(iVar1 + 0x1e8);
  return;
}

