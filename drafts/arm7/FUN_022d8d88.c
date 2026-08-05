// decomp: module=arm7 addr=0x022d8d88 name=FUN_022d8d88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8d88 --addr 0x022d8d88 --size 0x34 --module arm7 --version 2.0/sp1


void FUN_022d8d88(ushort param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = *DAT_022d8db4;
  *(ushort *)(iVar1 + 0x5f0) = (param_1 & (ushort)DAT_022d8db8) + 5;
  *(ushort *)(iVar1 + 0x5f2) = param_2 | 1;
  return;
}

