// decomp: module=unk_autoload_0 addr=0x02337f04 name=FUN_02337f04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, thumb
// triage: noise=9 statements=34
// verify:  python tools/match.py --c <file> --func FUN_02337f04 --addr 0x02337f04 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337f04(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  puVar2 = param_1;
  do {
    puVar2[0x10] = 0;
    iVar3 = 0;
    puVar4 = puVar2;
    do {
      iVar3 = iVar3 + 1;
      *(undefined2 *)(puVar4 + 8) = 0xffff;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    } while (iVar3 < 0x10);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 9;
  } while (iVar1 < 0x10);
  iVar1 = 0;
  puVar2 = param_1;
  do {
    iVar1 = iVar1 + 1;
    *(undefined2 *)(puVar2 + 0x98) = 0xffff;
    puVar2 = (undefined4 *)((int)puVar2 + 2);
  } while (iVar1 < 0x10);
  FUN_02331504(param_1,0x280);
  return;
}

