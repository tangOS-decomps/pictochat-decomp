// decomp: module=unk_autoload_0 addr=0x02330b0c name=FUN_02330b0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5a, thumb
// triage: noise=1 statements=33
// verify:  python tools/match.py --c <file> --func FUN_02330b0c --addr 0x02330b0c --size 0x5a --module unk_autoload_0 --version 2.0/sp1


void FUN_02330b0c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = *param_1; (iVar2 != 0 && (*(uint *)(iVar2 + 0x70) <= *(uint *)(param_2 + 0x70)));
      iVar2 = *(int *)(iVar2 + 0x80)) {
    if (iVar2 == param_2) {
      return;
    }
  }
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x7c);
    if (iVar1 != 0) {
      param_1 = (int *)(iVar1 + 0x80);
    }
    *param_1 = param_2;
    *(int *)(param_2 + 0x7c) = iVar1;
    *(int *)(param_2 + 0x80) = iVar2;
    *(int *)(iVar2 + 0x7c) = param_2;
    return;
  }
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    *param_1 = param_2;
  }
  else {
    *(int *)(iVar2 + 0x80) = param_2;
  }
  *(int *)(param_2 + 0x7c) = iVar2;
  *(undefined4 *)(param_2 + 0x80) = 0;
  param_1[1] = param_2;
  return;
}

