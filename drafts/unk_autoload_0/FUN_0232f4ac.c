// decomp: module=unk_autoload_0 addr=0x0232f4ac name=FUN_0232f4ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=51
// verify:  python tools/match.py --c <file> --func FUN_0232f4ac --addr 0x0232f4ac --size 0x90 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f4ac(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_02337454(param_2,param_1,0x30);
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + *(int *)(param_1 + 0x18);
  }
  *(int *)(param_1 + 0x8c) = iVar2;
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + *(int *)(param_1 + 0x20);
  }
  *(int *)(param_1 + 0x84) = iVar2;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + *(int *)(param_1 + 0x10);
  }
  *(int *)(param_1 + 0x88) = iVar2;
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  iVar2 = *(int *)(param_1 + 0x84);
  if (*(int *)(iVar2 + 8) != 0) {
    iVar3 = 0;
    do {
      iVar4 = *(int *)(iVar2 + 0xc + iVar3);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_2 + iVar4;
      }
      *(int *)(iVar2 + 0xc + iVar3 + 8) = iVar4;
      iVar2 = *(int *)(param_1 + 0x84);
      uVar1 = uVar1 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar1 < *(uint *)(iVar2 + 8));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *DAT_0232f538 = param_1;
  return;
}

