// decomp: module=unk_autoload_0 addr=0x02330b8c name=FUN_02330b8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e, thumb
// triage: noise=0 statements=28  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02330b8c --addr 0x02330b8c --size 0x3e --module unk_autoload_0 --version 2.0/sp1


int FUN_02330b8c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = *(int *)(iVar1 + 0x80);
  } while (iVar1 != param_2);
  iVar3 = *(int *)(iVar1 + 0x7c);
  if (*param_1 == iVar1) {
    *param_1 = iVar2;
  }
  else {
    *(int *)(iVar3 + 0x80) = iVar2;
  }
  if (param_1[1] == iVar1) {
    param_1[1] = iVar3;
  }
  else {
    *(int *)(iVar2 + 0x7c) = iVar3;
  }
  return iVar1;
}

