// decomp: module=arm7 addr=0x022d7bc8 name=FUN_022d7bc8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d7bc8 --addr 0x022d7bc8 --size 0x40 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7bc8(ushort *param_1)

{
  int iVar1;
  
  iVar1 = *DAT_022d7c04;
  *(ushort *)(iVar1 + 0x3a4) = *param_1;
  *(ushort *)(iVar1 + 0x3a6) = param_1[1] | *param_1;
  FUN_022d7c08();
  return 0;
}

