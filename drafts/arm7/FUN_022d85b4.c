// decomp: module=arm7 addr=0x022d85b4 name=FUN_022d85b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d85b4 --addr 0x022d85b4 --size 0x4c --module arm7 --version 2.0/sp1


undefined4 FUN_022d85b4(void)

{
  short sVar1;
  
  sVar1 = *(short *)(*DAT_022d85fc + 0x330);
  if (sVar1 == 0) {
    if ((*(ushort *)(*DAT_022d85fc + 0x3a4) & 1) != 0) {
      return 10;
    }
  }
  else if (sVar1 == 1) {
    return 10;
  }
  return 0x14;
}

