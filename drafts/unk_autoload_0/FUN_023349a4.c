// decomp: module=unk_autoload_0 addr=0x023349a4 name=FUN_023349a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x72, thumb
// triage: noise=8 statements=35
// verify:  python tools/match.py --c <file> --func FUN_023349a4 --addr 0x023349a4 --size 0x72 --module unk_autoload_0 --version 2.0/sp1


void FUN_023349a4(undefined1 *param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  longlong lVar6;
  
  lVar6 = CONCAT44(param_3,param_2);
  *param_1 = 0;
  param_1[4] = 0;
  if (param_2 != 0 || param_3 != 0) {
    do {
      uVar5 = (undefined4)((ulonglong)lVar6 >> 0x20);
      bVar1 = param_1[4];
      param_1[4] = bVar1 + 1;
      uVar2 = FUN_02335db0((int)lVar6,uVar5,10,0,param_4);
      param_1[bVar1 + 5] = uVar2;
      lVar6 = FUN_02335da4((int)lVar6,uVar5,10,0);
    } while (lVar6 != 0);
  }
  puVar3 = param_1 + 5;
  puVar4 = puVar3 + ((byte)param_1[4] - 1);
  if (puVar3 < puVar4) {
    do {
      uVar2 = *puVar3;
      *puVar3 = *puVar4;
      *puVar4 = uVar2;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + -1;
    } while (puVar3 < puVar4);
  }
  *(ushort *)(param_1 + 2) = (byte)param_1[4] - 1;
  return;
}

