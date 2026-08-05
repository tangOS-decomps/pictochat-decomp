// decomp: module=arm7 addr=0x022d71b4 name=FUN_022d71b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022d71b4 --addr 0x022d71b4 --size 0x38 --module arm7 --version 2.0/sp1


undefined4 FUN_022d71b4(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_022d71e8;
  if (param_1 < 0x100) {
    *(undefined2 *)(*DAT_022d71e8 + 0x3c4) = 0;
    *(short *)(*piVar1 + 0x3c2) = (short)param_1;
    return 0;
  }
  return 5;
}

