// decomp: module=arm7 addr=0x022c4c84 name=FUN_022c4c84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78, arm
// triage: noise=1 statements=35
// verify:  python tools/match.py --c <file> --func FUN_022c4c84 --addr 0x022c4c84 --size 0x78 --module arm7 --version 2.0/sp1


void FUN_022c4c84(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = *param_1; (iVar2 != 0 && (*(uint *)(iVar2 + 0x54) <= *(uint *)(param_2 + 0x54)));
      iVar2 = *(int *)(iVar2 + 100)) {
    if (iVar2 == param_2) {
      return;
    }
  }
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x60);
    if (iVar1 == 0) {
      *param_1 = param_2;
    }
    else {
      *(int *)(iVar1 + 100) = param_2;
    }
    *(int *)(param_2 + 0x60) = iVar1;
    *(int *)(param_2 + 100) = iVar2;
    *(int *)(iVar2 + 0x60) = param_2;
    return;
  }
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    *param_1 = param_2;
  }
  else {
    *(int *)(iVar2 + 100) = param_2;
  }
  *(int *)(param_2 + 0x60) = iVar2;
  *(undefined4 *)(param_2 + 100) = 0;
  param_1[1] = param_2;
  return;
}

