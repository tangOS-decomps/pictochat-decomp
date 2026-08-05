// decomp: module=arm7 addr=0x022c688c name=FUN_022c688c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=23  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c688c --addr 0x022c688c --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022c688c(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    iVar1 = *(int *)(param_1 + 0x14);
    if (iVar2 == 0) {
      *(int *)(DAT_022c68c0 + 0x10) = iVar1;
    }
    else {
      *(int *)(iVar2 + 0x14) = iVar1;
    }
    if (iVar1 == 0) {
      *(int *)(DAT_022c68c0 + 0xc) = iVar2;
    }
    else {
      *(int *)(iVar1 + 0x18) = iVar2;
    }
    return;
  }
  return;
}

