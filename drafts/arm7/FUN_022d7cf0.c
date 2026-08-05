// decomp: module=arm7 addr=0x022d7cf0 name=FUN_022d7cf0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022d7cf0 --addr 0x022d7cf0 --size 0x2c --module arm7 --version 2.0/sp1


undefined4 FUN_022d7cf0(uint param_1)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_022d7d18;
  *(short *)(*DAT_022d7d14 + 0x354) = (short)(param_1 >> 1);
  *puVar1 = (short)param_1;
  return 0;
}

