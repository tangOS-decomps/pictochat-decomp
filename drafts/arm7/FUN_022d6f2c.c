// decomp: module=arm7 addr=0x022d6f2c name=FUN_022d6f2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022d6f2c --addr 0x022d6f2c --size 0x40 --module arm7 --version 2.0/sp1


undefined4 FUN_022d6f2c(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_022d6f68;
  if ((param_1 & DAT_022d6f64) != 0) {
    *(short *)(*DAT_022d6f68 + 0x32c) = (short)param_1;
    *(uint *)(*piVar1 + 0x340) = *(uint *)(*piVar1 + 0x340) | 4;
    return 0;
  }
  return 5;
}

