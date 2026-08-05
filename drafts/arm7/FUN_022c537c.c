// decomp: module=arm7 addr=0x022c537c name=FUN_022c537c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022c537c --addr 0x022c537c --size 0x28 --module arm7 --version 2.0/sp1


void FUN_022c537c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_022c53a0 + 0x24);
  while( true ) {
    if (iVar1 != 0) {
      param_2 = *(int *)(iVar1 + 0x48);
    }
    if (iVar1 == 0 || param_2 == 1) break;
    iVar1 = *(int *)(iVar1 + 0x4c);
  }
  return;
}

