// decomp: module=arm7 addr=0x022d793c name=FUN_022d793c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28c (Ghidra's cache says 0x27c - it excludes this function's trailing literal pool), arm
// triage: noise=19 statements=82
// verify:  python tools/match.py --c <file> --func FUN_022d793c --addr 0x022d793c --size 0x28c --module arm7 --version 2.0/sp1


undefined4 FUN_022d793c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  code *unaff_r9;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  
  puVar5 = DAT_022d7bc4;
  if (param_2 != 0) {
    unaff_r9 = DAT_022d7bbc;
  }
  if (param_2 == 0) {
    unaff_r9 = DAT_022d7bc0;
  }
  if (((uint)*(ushort *)(*DAT_022d7bb8 + 0x32c) & 1 << (param_1 & 0xff)) == 0) {
    return 5;
  }
  uVar1 = *DAT_022d7bc4;
  *DAT_022d7bc4 = 0x8001;
  piVar3 = DAT_022d7bb8;
  do {
    do {
      sVar2 = puVar5[0xea];
    } while ((int)(uint)(ushort)puVar5[-2] >> 8 != 2);
  } while (sVar2 != 0 && sVar2 != 9);
  *(short *)(*DAT_022d7bb8 + 0x3be) = (short)param_1;
  iVar6 = *piVar3;
  sVar2 = *(short *)(iVar6 + 0x5f8);
  local_28 = param_4;
  if (sVar2 != 2) {
    if (sVar2 == 3) {
      iVar6 = *(ushort *)(iVar6 + 0x5fc) + 0xcf;
      for (uVar7 = 0; piVar4 = DAT_022d7bb8, uVar7 < *(ushort *)(*piVar3 + 0x600); uVar7 = uVar7 + 1
          ) {
        local_2c = 0;
        local_30 = 0;
        (*unaff_r9)(iVar6,1,&local_30);
        (*unaff_r9)(iVar6 + param_1,1,&local_2c);
        FUN_022d862c(local_30,local_2c);
        iVar6 = iVar6 + 0xf;
      }
      for (uVar7 = 0; uVar7 < *(ushort *)(*piVar4 + 0x5fe); uVar7 = uVar7 + 1) {
        local_2c = 0;
        (*unaff_r9)(iVar6,1,&local_2c);
        local_2c = local_2c << 8;
        (*unaff_r9)(iVar6 + param_1,1,&local_2c);
        local_2c = local_2c | 0x50000;
        FUN_022d865c();
        iVar6 = iVar6 + 0xf;
      }
      goto LAB_022d7b98;
    }
    if (sVar2 != 5) goto LAB_022d7b98;
  }
  iVar6 = (param_1 - 1) * 6;
  local_2c = 0;
  (*unaff_r9)(iVar6 + 0xf2,3,&local_2c);
  FUN_022d865c(local_2c);
  (*unaff_r9)(iVar6 + 0xf5,3,&local_2c);
  FUN_022d865c(local_2c);
  local_2c = 0;
  if ((*(uint *)(*DAT_022d7bb8 + 0x604) & 0x10000) == 0) {
    (*unaff_r9)(param_1 + 0x145,1,&local_2c);
    FUN_022d862c(0x1e,local_2c);
  }
  else if ((*(uint *)(*DAT_022d7bb8 + 0x604) & 0x8000) == 0) {
    (*unaff_r9)(param_1 + 0x153,1,&local_2c);
    local_2c = *(uint *)(*DAT_022d7bb8 + 0x604) | (local_2c & 0x1f) << 10;
    FUN_022d865c();
  }
LAB_022d7b98:
  puVar5 = DAT_022d7bc4;
  *DAT_022d7bc4 = uVar1;
  puVar5[4] = 3;
  return 0;
}

