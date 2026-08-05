// decomp: module=unk_autoload_0 addr=0x02321328 name=FUN_02321328
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9a, thumb
// triage: noise=3 statements=47
// verify:  python tools/match.py --c <file> --func FUN_02321328 --addr 0x02321328 --size 0x9a --module unk_autoload_0 --version 2.0/sp1


void FUN_02321328(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_023212f8();
  uVar2 = FUN_02321304();
  iVar3 = FUN_023212ec();
  if (iVar3 == 1) {
    iVar3 = FUN_0232e004(param_2,uVar1,uVar2);
    param_1[1] = iVar3;
    iVar4 = -1;
    *param_1 = iVar3;
    if (iVar3 != -1) {
      iVar4 = 0;
    }
    param_1[2] = iVar4;
    return;
  }
  if ((*param_1 != -1) && (iVar3 = FUN_023212ec(), iVar3 == 2)) {
    iVar3 = FUN_0232e004(param_2,uVar1,uVar2);
    param_1[1] = iVar3;
    if (*param_1 == iVar3) {
      iVar3 = 1;
    }
    else {
      iVar3 = 2;
    }
    param_1[2] = iVar3;
    return;
  }
  if ((*param_1 != -1) && (iVar3 = FUN_023212ec(), iVar3 == 3)) {
    iVar3 = FUN_0232e004(param_2,uVar1,uVar2);
    param_1[1] = iVar3;
    if (*param_1 == iVar3) {
      iVar3 = 3;
    }
    else {
      iVar3 = 2;
    }
    param_1[2] = iVar3;
    return;
  }
  FUN_0232131c(param_1);
  return;
}

