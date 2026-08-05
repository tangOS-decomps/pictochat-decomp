// decomp: module=unk_autoload_0 addr=0x02334dbc name=FUN_02334dbc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf8, thumb
// triage: noise=14 statements=59
// verify:  python tools/match.py --c <file> --func FUN_02334dbc --addr 0x02334dbc --size 0xf8 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334dbc(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  undefined8 uVar8;
  int local_68;
  undefined1 auStack_64 [38];
  undefined1 auStack_3e [38];
  undefined4 uStack_18;
  
  uVar8 = CONCAT44(param_3,param_2);
  uStack_18 = param_4;
  iVar2 = FUN_02334f88(param_2,param_3);
  bVar6 = iVar2 != 0;
  cVar7 = param_3 == 0;
  FUN_02335b58(0,0,param_2);
  if (cVar7 != '\0') {
    *(bool *)param_1 = bVar6;
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 5) = 0;
    return;
  }
  iVar2 = FUN_02334f98(param_2,param_3);
  if (iVar2 < 3) {
    *(bool *)param_1 = bVar6;
    *(undefined2 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 4) = 1;
    iVar2 = FUN_02334f98(param_2,param_3);
    if (iVar2 == 1) {
      uVar1 = 0x4e;
    }
    else {
      uVar1 = 0x49;
    }
    *(undefined1 *)(param_1 + 5) = uVar1;
    return;
  }
  if (bVar6) {
    uVar8 = FUN_02335708(0,0,param_2,param_3);
  }
  uVar8 = FUN_02334704((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),&local_68);
  uVar4 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar3 = (uint)uVar8;
  uVar5 = uVar4 | 0x100000;
  iVar2 = FUN_02334f14((uVar3 & -uVar3) - 1,
                       ((uVar5 & -(uint)(uVar3 != 0) - uVar5) - 1) + (uint)((uVar3 & -uVar3) != 0));
  FUN_02334b80(auStack_64,local_68 - (0x35 - iVar2));
  FUN_02334784(uVar3,uVar4,0x35 - iVar2);
  uVar8 = FUN_02335300();
  FUN_023349a4(auStack_3e,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
  FUN_02334a18(param_1,auStack_3e,auStack_64);
  *(bool *)param_1 = bVar6;
  return;
}

