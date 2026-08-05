// decomp: module=unk_autoload_0 addr=0x023293fc name=FUN_023293fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xe2 - it excludes this function's trailing literal pool), thumb
// triage: noise=18 statements=68
// verify:  python tools/match.py --c <file> --func FUN_023293fc --addr 0x023293fc --size 0xe8 --module unk_autoload_0 --version 2.0/sp1


void FUN_023293fc(undefined2 *param_1,undefined2 *param_2,int param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined1 auStack_140 [4];
  uint local_13c;
  uint local_138;
  undefined1 auStack_130 [20];
  undefined2 local_11c;
  undefined1 auStack_11a [258];
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  puVar2 = (undefined2 *)FUN_023294e4();
  if (puVar2 == (undefined2 *)0x0) {
    FUN_02334628(auStack_130,param_2,10);
    local_11c = 0;
    puVar3 = FUN_023260bc();
    FUN_02329628(auStack_11a,*puVar3,auStack_130);
    if (param_3 != 0) {
      uVar4 = FUN_02329994();
      iVar5 = FUN_02332e38(uVar4,param_1,6);
      if (iVar5 != 0) {
        FUN_02326488(auStack_11a,0x10);
        FUN_02322c00(auStack_140);
        if ((*(byte *)(param_2 + 0x25) == local_13c) &&
           (*(byte *)((int)param_2 + 0x4b) == local_138)) {
          FUN_02329640((int)auStack_11a,(int)auStack_130);
          FUN_02326488(auStack_11a,0x12);
        }
      }
    }
    for (iVar5 = 0; iVar5 < 0x10; iVar5 = iVar5 + 1) {
      puVar2 = (undefined2 *)(DAT_023294e0 + iVar5 * 0x58);
      if (*(int *)(puVar2 + 0x2a) == 0) goto LAB_023294a6;
    }
    puVar2 = (undefined2 *)0x0;
  }
LAB_023294a6:
  if (puVar2 != (undefined2 *)0x0) {
    puVar6 = puVar2 + 3;
    iVar5 = 0x26;
    *puVar2 = *param_1;
    puVar2[1] = param_1[1];
    puVar2[2] = param_1[2];
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *puVar6 = uVar1;
      puVar6 = puVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (param_3 == 0) {
      iVar5 = 2;
    }
    else {
      iVar5 = 1;
    }
    *(int *)(puVar2 + 0x2a) = iVar5;
    if (iVar5 == 2) {
      FUN_023274f8();
    }
  }
  return;
}

