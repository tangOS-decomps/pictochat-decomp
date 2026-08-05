// decomp: module=unk_autoload_0 addr=0x0232fb10 name=FUN_0232fb10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xba - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=41  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232fb10 --addr 0x0232fb10 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232fb10(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0232f74c();
  if (iVar1 == 0) {
    iVar1 = FUN_0232f6a8(param_1,DAT_0232fbcc,0x3c,0);
    if (iVar1 != 0x3c) {
      return 0;
    }
    iVar5 = *(int *)(DAT_0232fbd0 + 0x38) * 4;
    iVar2 = *(int *)(DAT_0232fbd0 + 0x38) * 8;
    if (param_2 == 0) {
      return 0;
    }
    if (param_3 == 0) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = FUN_0232f54c();
    }
    iVar1 = FUN_0232f84c(param_2,iVar2 + 0x5c,DAT_0232fbd4,pvVar3,param_1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar4 = FUN_0232f6a8(param_1,iVar1,iVar5 + 0x3c,0);
    if (iVar4 != iVar5 + 0x3c) {
      return 0;
    }
    FUN_02337584(iVar1 + 0x3c,iVar1 + 0x3c + *(int *)(iVar1 + 0x38) * 4,iVar5);
    FUN_023374f0(iVar1 + 0x3c,0,iVar5);
    FUN_023314e8(iVar1,iVar2 + 0x3c);
    if (param_3 != 0) {
      FUN_0232f76c(param_1,iVar1);
    }
  }
  return iVar1;
}

