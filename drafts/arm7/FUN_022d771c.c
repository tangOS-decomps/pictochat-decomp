// decomp: module=arm7 addr=0x022d771c name=FUN_022d771c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022d771c --addr 0x022d771c --size 0x58 --module arm7 --version 2.0/sp1


undefined4 FUN_022d771c(uint param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  puVar2 = DAT_022d7770;
  piVar1 = DAT_022d776c;
  if ((param_1 < 10) || (1000 < param_1)) {
    uVar3 = 5;
  }
  else {
    *(short *)(*DAT_022d776c + 0x3b2) = (short)param_1;
    *puVar2 = (short)param_1;
    FUN_022d7e6c(*(undefined2 *)(*piVar1 + 0x338));
    uVar3 = 0;
  }
  return uVar3;
}

