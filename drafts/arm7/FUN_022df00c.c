// decomp: module=arm7 addr=0x022df00c name=FUN_022df00c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022df00c --addr 0x022df00c --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022df00c(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_022df094;
  iVar3 = *(int *)(*DAT_022df094 + param_1 * 0xc + 0x194);
  while (iVar1 = iVar3, iVar1 != -1) {
    iVar3 = func_0x037c5b10(iVar1);
    if (param_1 != 2) {
      FUN_022d9bf0(iVar1 + 0x10);
    }
    *(undefined2 *)(iVar1 + 0x18) = 2;
    if (param_2 != 0) {
      FUN_022dded8(*piVar2 + 0x194 + param_1 * 0xc,iVar1);
    }
  }
  return;
}

