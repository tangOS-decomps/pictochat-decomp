// decomp: module=arm7 addr=0x022c5584 name=FUN_022c5584
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5584 --addr 0x022c5584 --size 0x38 --module arm7 --version 2.0/sp1


int FUN_022c5584(void)

{
  int iVar1;
  int iVar2;
  
  FUN_022c6d40();
  iVar1 = *(int *)(DAT_022c55b8 + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    *(int *)(DAT_022c55b8 + 4) = iVar1 + -1;
    iVar2 = iVar1;
  }
  FUN_022c6d54();
  return iVar2;
}

