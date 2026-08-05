// decomp: module=arm7 addr=0x022c3ba8 name=FUN_022c3ba8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c3ba8 --addr 0x022c3ba8 --size 0x2c --module arm7 --version 2.0/sp1


void FUN_022c3ba8(void)

{
  int iVar1;
  
  iVar1 = 4000;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if ((*DAT_022c3bd0 & 0x80) != 0) break;
    iVar1 = iVar1 + -1;
  }
  return;
}

