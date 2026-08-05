// decomp: module=arm7 addr=0x022c4cfc name=FUN_022c4cfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, arm
// triage: noise=0 statements=28  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c4cfc --addr 0x022c4cfc --size 0x58 --module arm7 --version 2.0/sp1


int FUN_022c4cfc(int *param_1,int param_2)

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
    iVar2 = *(int *)(iVar1 + 100);
  } while (iVar1 != param_2);
  iVar3 = *(int *)(iVar1 + 0x60);
  if (*param_1 == iVar1) {
    *param_1 = iVar2;
  }
  else {
    *(int *)(iVar3 + 100) = iVar2;
  }
  if (param_1[1] == iVar1) {
    param_1[1] = iVar3;
  }
  else {
    *(int *)(iVar2 + 0x60) = iVar3;
  }
  return iVar1;
}

