// decomp: module=unk_autoload_0 addr=0x02321a6c name=FUN_02321a6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x174 (Ghidra's cache says 0x16c - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=80
// verify:  python tools/match.py --c <file> --func FUN_02321a6c --addr 0x02321a6c --size 0x174 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321a6c(int param_1,int param_2,undefined4 *param_3,int param_4,int param_5,short *param_6
                 ,int param_7,undefined4 param_8)

{
  short sVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  short *local_44;
  int local_40;
  int local_3c;
  uint local_38;
  short local_34;
  short local_32;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int iStack_18;
  
  local_34 = *DAT_02321bd8;
  local_32 = DAT_02321bd8[1];
  iStack_18 = param_4;
  if (param_5 == DAT_02321bdc) {
    pvVar2 = FUN_0232dfa8(param_3,param_4);
    if (*(int *)((int)pvVar2 + 8) == 0) {
      local_44 = &local_34;
    }
    else {
      local_44 = (short *)((int)param_3 + *(int *)((int)pvVar2 + 8));
    }
  }
  else {
    local_44 = (short *)FUN_02321d04(param_5);
    if (*local_44 == 0) {
      local_44 = &local_34;
    }
  }
  if (param_6 != (short *)0x0) {
    local_44 = param_6;
  }
  FUN_023218cc(param_3,param_4,&local_24,&local_28,&local_2c,&local_30,local_44);
  *(int *)(param_2 + 0x24) = param_1;
  *(undefined4 **)(param_2 + 0x20) = param_3;
  *(short *)(param_2 + 0x1c) = (short)param_5;
  *(short *)(param_2 + 0x1e) = (short)param_4;
  *(undefined1 *)(param_2 + 0x28) = 0;
  pvVar2 = FUN_0232dfa8(param_3,param_4);
  *(ushort *)(param_2 + 0x16) = *(ushort *)((int)pvVar2 + 6) >> 8 & 0xf;
  *(short *)(param_2 + 8) = (short)local_24;
  *(short *)(param_2 + 10) = (short)local_28;
  *(ushort *)(param_2 + 0xc) = (ushort)local_2c & 0xff;
  *(ushort *)(param_2 + 0xe) = (ushort)local_30 & 0xff;
  if (param_7 == 0) {
    FUN_02321798(*(undefined4 *)(param_2 + 0x10),&local_1c,&local_20);
  }
  else {
    FUN_0232e0ac(param_1,param_2);
    *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)(param_1 + 0xe);
    uVar3 = FUN_02321864(local_2c,local_30);
    *(undefined4 *)(param_2 + 0x10) = uVar3;
    FUN_02321798(uVar3,&local_1c,&local_20);
    sVar1 = FUN_02335e0c(local_2c + -1,local_1c);
    *(short *)(param_2 + 0x18) = sVar1 + 1;
    sVar1 = FUN_02335e0c(local_30 + -1,local_20);
    *(short *)(param_2 + 0x1a) = sVar1 + 1;
  }
  local_38 = (uint)*(ushort *)(param_2 + 0x14);
  for (local_40 = 0; local_40 < (int)(uint)*(ushort *)(param_2 + 0x1a); local_40 = local_40 + 1) {
    for (local_3c = 0; local_3c < (int)(uint)*(ushort *)(param_2 + 0x18); local_3c = local_3c + 1) {
      iVar4 = FUN_02321940(param_1,param_3,param_4,local_1c * local_3c,local_20 * local_40,local_1c,
                           local_20,local_38,local_24,local_28,local_44,param_8);
      local_38 = local_38 + iVar4;
    }
  }
  if (param_7 != 0) {
    *(short *)(param_1 + 0xe) = (short)local_38;
  }
  return;
}

