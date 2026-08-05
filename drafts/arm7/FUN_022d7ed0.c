// decomp: module=arm7 addr=0x022d7ed0 name=FUN_022d7ed0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d7ed0 --addr 0x022d7ed0 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022d7ed0(void)

{
  int *piVar1;
  ushort *puVar2;
  
  piVar1 = DAT_022d7f14;
  *(undefined2 *)(*DAT_022d7f14 + 0x3ea) = 1;
  puVar2 = DAT_022d7f18;
  if (*(short *)(*piVar1 + 0x468) != 0) {
    return;
  }
  *DAT_022d7f18 = *DAT_022d7f18 & 0xfffd;
  puVar2[8] = 0;
  return;
}

