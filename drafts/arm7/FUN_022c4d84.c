// decomp: module=arm7 addr=0x022c4d84 name=FUN_022c4d84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022c4d84 --addr 0x022c4d84 --size 0x60 --module arm7 --version 2.0/sp1


void FUN_022c4d84(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_022c4de0;
  iVar2 = *(int *)(DAT_022c4de0 + 0x24);
  iVar4 = 0;
  while ((iVar3 = iVar2, iVar3 != 0 && (*(uint *)(iVar3 + 0x54) < *(uint *)(param_1 + 0x54)))) {
    iVar4 = iVar3;
    iVar2 = *(int *)(iVar3 + 0x4c);
  }
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x4c) = *(int *)(DAT_022c4de0 + 0x24);
    *(int *)(iVar1 + 0x24) = param_1;
  }
  else {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar4 + 0x4c);
    *(int *)(iVar4 + 0x4c) = param_1;
  }
  return;
}

