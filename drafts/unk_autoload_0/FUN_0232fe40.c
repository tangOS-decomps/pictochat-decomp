// decomp: module=unk_autoload_0 addr=0x0232fe40 name=FUN_0232fe40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6a, thumb
// triage: noise=8 statements=32
// verify:  python tools/match.py --c <file> --func FUN_0232fe40 --addr 0x0232fe40 --size 0x6a --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232fe40(undefined4 param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)FUN_0232f558(param_5);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar2 = FUN_0232f74c(*puVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = FUN_02330558(iVar2,param_6);
  if (iVar3 == 0) {
    return 0;
  }
  if ((int)param_4 < 0) {
    param_4 = (uint)*(byte *)(iVar3 + 8);
  }
  if ((int)param_3 < 0) {
    param_3 = (uint)*(ushort *)(iVar3 + 4);
  }
  if ((int)param_2 < 0) {
    param_2 = (uint)*(byte *)(iVar3 + 9);
  }
  uVar4 = FUN_0232feac(param_1,param_2,param_3,param_4,iVar3,iVar2,param_5,param_6);
  return uVar4;
}

