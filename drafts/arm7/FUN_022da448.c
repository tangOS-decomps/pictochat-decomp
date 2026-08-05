// decomp: module=arm7 addr=0x022da448 name=FUN_022da448
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022da448 --addr 0x022da448 --size 0x48 --module arm7 --version 2.0/sp1


void FUN_022da448(int param_1)

{
  int *piVar1;
  
  FUN_022ded7c();
  piVar1 = DAT_022da48c;
  *(undefined2 *)(*(int *)(*DAT_022da48c + 0x31c) + param_1 * 0x1c) = 0;
  *(short *)(*piVar1 + 0x52c) = *(short *)(*piVar1 + 0x52c) + -1;
  return;
}

