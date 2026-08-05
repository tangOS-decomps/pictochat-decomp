// decomp: module=unk_autoload_0 addr=0x0232fa24 name=FUN_0232fa24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x62, thumb
// triage: noise=5 statements=26
// verify:  python tools/match.py --c <file> --func FUN_0232fa24 --addr 0x0232fa24 --size 0x62 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232fa24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = param_4;
  iVar1 = FUN_0232f688();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_5 == 0) {
    return 0;
  }
  iVar2 = FUN_0232f84c(param_5,iVar1 + 0x20,param_2,param_3,param_4,param_1,uVar4);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = FUN_0232f6a8(param_1,iVar2,iVar1,0);
  if (iVar1 != iVar3) {
    return 0;
  }
  FUN_023314e8(iVar2,iVar1);
  return iVar2;
}

