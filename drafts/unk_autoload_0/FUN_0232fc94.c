// decomp: module=unk_autoload_0 addr=0x0232fc94 name=FUN_0232fc94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=34
// verify:  python tools/match.py --c <file> --func FUN_0232fc94 --addr 0x0232fc94 --size 0x90 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232fc94(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_023381cc();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_023381a8(param_1);
  iVar2 = param_1 + (*(int *)(param_1 + 0x38) + param_2) * 4;
  iVar3 = *(int *)(iVar2 + 0x3c);
  if (param_2 < iVar1 - 1U) {
    iVar1 = *(int *)(iVar2 + 0x40);
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
  }
  iVar1 = iVar1 - iVar3;
  if (param_4 == 0) {
    return 0;
  }
  iVar2 = FUN_0232f84c(param_4,iVar1 + 0x20,DAT_0232fd20,param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = FUN_0232f6a8(param_3,iVar2,iVar1,iVar3);
  if (iVar1 != iVar3) {
    return 0;
  }
  FUN_023314e8(iVar2,iVar1);
  FUN_023381ac(param_1,param_2,iVar2);
  return 1;
}

