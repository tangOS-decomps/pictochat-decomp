// decomp: module=arm7 addr=0x022c554c name=FUN_022c554c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022c554c --addr 0x022c554c --size 0x38 --module arm7 --version 2.0/sp1


int FUN_022c554c(void)

{
  int iVar1;
  int unaff_r4;
  
  FUN_022c6d40();
  iVar1 = *(int *)(DAT_022c5580 + 4);
  if (iVar1 != -1) {
    *(int *)(DAT_022c5580 + 4) = iVar1 + 1;
    unaff_r4 = iVar1;
  }
  FUN_022c6d54();
  return unaff_r4;
}

