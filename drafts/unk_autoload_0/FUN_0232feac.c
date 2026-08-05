// decomp: module=unk_autoload_0 addr=0x0232feac name=FUN_0232feac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, thumb
// triage: noise=12 statements=24
// verify:  python tools/match.py --c <file> --func FUN_0232feac --addr 0x0232feac --size 0x74 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232feac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18;
  
  iVar1 = FUN_0232ebc0(param_1,param_2,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_0232eca4(param_2,iVar1);
  iVar3 = FUN_0232f900(param_3,6,uVar2,0,&local_18);
  if (iVar3 != 0) {
    thunk_FUN_0232ee10(iVar1);
    return 0;
  }
  FUN_0232ec2c(iVar1,param_6 + *(int *)(param_6 + 0x18),*param_5,local_18);
  FUN_0232e9a8(param_1,*(undefined1 *)((int)param_5 + 6));
  FUN_0232e9d8(param_1,*(undefined1 *)((int)param_5 + 7));
  FUN_0232ea14(param_1,param_7,param_8);
  return 1;
}

