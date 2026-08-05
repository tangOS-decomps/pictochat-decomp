// decomp: module=unk_autoload_0 addr=0x0233879c name=FUN_0233879c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x118, thumb
// triage: noise=6 statements=64
// verify:  python tools/match.py --c <file> --func FUN_0233879c --addr 0x0233879c --size 0x118 --module unk_autoload_0 --version 2.0/sp1


int FUN_0233879c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  bool bVar6;
  undefined1 auStack_60 [8];
  int local_58;
  undefined4 uStack_18;
  
  iVar5 = 0;
  uStack_18 = param_4;
  uVar2 = FUN_02332080();
  if ((*(uint *)(param_1 + 0x14) & 0x20) != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffffdf;
    piVar4 = *(int **)(param_1 + 8);
    while (piVar1 = piVar4, piVar1 != (int *)0x0) {
      piVar4 = (int *)*piVar1;
      if (((piVar1[3] & 2U) != 0) && (FUN_0233846c(piVar1,3), piVar4 == (int *)0x0)) {
        piVar4 = *(int **)(param_1 + 8);
      }
    }
  }
  FUN_02332094(uVar2);
  uVar2 = FUN_02332080();
  uVar3 = *(uint *)(param_1 + 0x14);
  if ((((uVar3 & 0x40) == 0) && ((uVar3 & 8) == 0)) && (*(int *)(param_1 + 8) != 0)) {
    bVar6 = (uVar3 & 0x10) == 0;
    if (bVar6) {
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x10;
    }
    FUN_02332094(uVar2);
    if (bVar6) {
      FUN_02338510(*(undefined4 *)(param_1 + 8),9);
    }
    uVar2 = FUN_02332080();
    if ((param_2 != 0) || (bVar6)) {
      iVar5 = *(int *)(param_1 + 8);
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x40;
    }
    if ((param_2 != 0) && ((*(uint *)(iVar5 + 0xc) & 4) != 0)) {
      FUN_02330f6c(iVar5 + 0x18);
      iVar5 = 0;
    }
    FUN_02332094(uVar2);
  }
  else {
    if (param_2 != 0) {
      if ((uVar3 & 0x10) != 0) {
        FUN_02338a20(auStack_60);
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffffef;
        local_58 = param_1;
        FUN_02338510(auStack_60,10);
      }
      if ((*(uint *)(param_1 + 0x14) & 0x40) != 0) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xffffffbf | 8;
        FUN_02330f6c(param_1 + 0xc);
      }
    }
    FUN_02332094(uVar2);
  }
  return iVar5;
}

