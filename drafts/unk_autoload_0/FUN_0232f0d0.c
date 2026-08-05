// decomp: module=unk_autoload_0 addr=0x0232f0d0 name=FUN_0232f0d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x234 (Ghidra's cache says 0x226 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=114
// verify:  python tools/match.py --c <file> --func FUN_0232f0d0 --addr 0x0232f0d0 --size 0x234 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232f0d0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
            undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9,int param_10,
            undefined4 param_11,undefined4 param_12,undefined4 param_13,int param_14,
            undefined4 param_15)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint a;
  bool bVar7;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_1c;
  
  puVar1 = DAT_0232f2f8;
  local_1c = 0;
  a = 0xffffffff;
  FUN_02331504(param_2,param_4);
  FUN_02331504(param_3,param_4);
  bVar7 = param_5 != 1;
  local_24 = FUN_02335e0c(DAT_0232f2fc,param_9);
  if (param_14 != 0) {
    uVar2 = param_4;
    if (bVar7) {
      uVar2 = param_4 >> 1;
    }
    uVar4 = local_24 + 0x10;
    local_24 = uVar4 & 0xffffffe0;
    iVar5 = (int)uVar4 >> 5;
    iVar3 = FUN_02336018(uVar2,param_13);
    local_28 = iVar5 * iVar3;
    local_2c = 0x20;
    if (bVar7) {
      local_2c = 0x10;
    }
    local_2c = local_2c * iVar5;
  }
  if (param_1 != 2) {
    local_1c = 10;
  }
  if ((param_14 != 0) && (a = FUN_0232e878(), (int)a < 0)) {
    return 0;
  }
  iVar3 = FUN_0232e84c(3);
  if (iVar3 == 0) {
    if (-1 < (int)a) {
      FUN_0232e8a4(a);
    }
    return 0;
  }
  iVar3 = FUN_0232e804(10);
  if (iVar3 != 0) {
    if (param_8 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 1;
    }
    uVar2 = param_4 >> 2;
    FUN_02337860(1,bVar7,param_2,uVar6,0,uVar2,param_10,0,local_24,param_11);
    FUN_023377c4(0,!bVar7,param_2,uVar2,param_8,param_6,param_7);
    if (param_8 == 0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 1;
    }
    FUN_02337860(3,bVar7,param_3,uVar6,0,uVar2,param_10,0,local_24,param_12);
    FUN_023377c4(1,!bVar7,param_3,uVar2,param_8,param_6,param_7);
    if (-1 < (int)a) {
      FUN_023377f4(a,local_28 + local_2c,local_28,DAT_0232f300,puVar1);
    }
    if (param_1 == 1) {
      FUN_023378c4(1,2,1,1);
    }
    if ((int)a < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1 << (a & 0xff);
    }
    FUN_02337768(local_1c,3,iVar3,0);
    *puVar1 = 1;
    puVar1[1] = param_1;
    puVar1[8] = 10;
    puVar1[9] = local_1c;
    puVar1[10] = 3;
    puVar1[0xb] = a;
    puVar1[2] = param_5;
    puVar1[3] = param_2;
    puVar1[4] = param_3;
    puVar1[5] = param_4;
    uVar6 = FUN_02336018(param_4,param_13);
    puVar1[6] = uVar6;
    puVar1[7] = 0;
    puVar1[0xc] = param_13;
    puVar1[0xd] = param_14;
    puVar1[0xe] = param_15;
    puVar1[0x14] = param_10;
    FUN_02330584((char *)(puVar1 + 0xf));
    FUN_02330590(puVar1 + 0xf,param_10 << 8,1);
    puVar1[0x13] = 0;
    return 1;
  }
  if (-1 < (int)a) {
    FUN_0232e8a4(a);
  }
  FUN_0232e868(3);
  return 0;
}

