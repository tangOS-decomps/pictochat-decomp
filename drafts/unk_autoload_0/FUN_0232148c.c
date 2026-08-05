// decomp: module=unk_autoload_0 addr=0x0232148c name=FUN_0232148c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0, thumb
// triage: noise=2 statements=44
// verify:  python tools/match.py --c <file> --func FUN_0232148c --addr 0x0232148c --size 0xb0 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232148c(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_02321480(param_2,param_4);
  iVar2 = FUN_02321480(param_3,param_5);
  if (iVar2 < iVar1) {
    iVar1 = param_3;
    iVar2 = param_2;
    if (param_4 < param_2) {
      iVar1 = param_5;
      iVar2 = param_4;
      param_5 = param_3;
      param_4 = param_2;
    }
    iVar3 = FUN_02335e0c((param_5 - iVar1) * 0x1000,param_4 - iVar2);
    iVar5 = 0;
    for (iVar4 = 0; iVar4 < param_4 - iVar2; iVar4 = iVar4 + 1) {
      FUN_02321408(param_1,iVar2 + iVar4,iVar1 + (iVar5 >> 0xc),param_6);
      iVar5 = iVar5 + iVar3;
    }
  }
  else {
    iVar1 = param_3;
    iVar2 = param_2;
    if (param_5 < param_3) {
      iVar1 = param_5;
      iVar2 = param_4;
      param_5 = param_3;
      param_4 = param_2;
    }
    iVar3 = FUN_02335e0c((param_4 - iVar2) * 0x1000,param_5 - iVar1);
    iVar5 = 0;
    for (iVar4 = 0; iVar4 < param_5 - iVar1; iVar4 = iVar4 + 1) {
      FUN_02321408(param_1,iVar2 + (iVar5 >> 0xc),iVar1 + iVar4,param_6);
      iVar5 = iVar5 + iVar3;
    }
  }
  return;
}

