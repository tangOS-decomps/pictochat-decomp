// decomp: module=unk_autoload_0 addr=0x0232fdec name=FUN_0232fdec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x52, thumb
// triage: noise=12 statements=22
// verify:  python tools/match.py --c <file> --func FUN_0232fdec --addr 0x0232fdec --size 0x52 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232fdec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)FUN_0232f558(param_2);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar2 = FUN_0232f74c(*puVar1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = FUN_02330558(iVar2,param_3);
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = FUN_0232feac(param_1,*(undefined1 *)(iVar3 + 9),*(undefined2 *)(iVar3 + 4),
                       *(undefined1 *)(iVar3 + 8),iVar3,iVar2,param_2,param_3,param_4);
  return uVar4;
}

