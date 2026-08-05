// decomp: module=unk_autoload_0 addr=0x023397a8 name=FUN_023397a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x56, thumb
// triage: noise=1 statements=30
// verify:  python tools/match.py --c <file> --func FUN_023397a8 --addr 0x023397a8 --size 0x56 --module unk_autoload_0 --version 2.0/sp1


void FUN_023397a8(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    *(int *)(param_2 + 8) = param_3;
    uVar3 = FUN_02332080();
    iVar2 = *param_1;
    iVar1 = 0;
    while (((iVar4 = iVar2, iVar4 != 0 && ((param_4 != 0 || (*(int *)(iVar4 + 8) <= param_3)))) &&
           ((param_4 != 1 || (*(int *)(iVar4 + 8) < param_3))))) {
      iVar1 = iVar4;
      iVar2 = *(int *)(iVar4 + 0xc);
    }
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    *(int *)(param_2 + 0xc) = iVar4;
    if (iVar1 == 0) {
      *param_1 = param_2;
    }
    else {
      *(int *)(iVar1 + 0xc) = param_2;
    }
    FUN_02332094(uVar3);
  }
  return;
}

