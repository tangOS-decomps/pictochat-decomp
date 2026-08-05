// decomp: module=unk_autoload_0 addr=0x02333a38 name=FUN_02333a38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4e8 (Ghidra's cache says 0x4b8 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=341
// verify:  python tools/match.py --c <file> --func FUN_02333a38 --addr 0x02333a38 --size 0x4e8 --module unk_autoload_0 --version 2.0/sp1


byte * FUN_02333a38(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,
                   undefined4 param_5,undefined4 param_6,uint param_7)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  char extraout_r1;
  ushort uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  char cVar13;
  uint local_64;
  byte local_58;
  undefined1 local_54 [2];
  undefined2 local_52;
  char acStack_50 [2];
  short local_4e;
  byte local_4c;
  byte local_4b [35];
  uint uStack_28;
  
  local_64 = param_7;
  uVar11 = (uint)param_5._1_1_;
  uVar1 = param_4 >> 0x18;
  uVar3 = param_4 >> 8 & 0xff;
  if (DAT_02333d14 < (int)param_7) {
    return (byte *)0x0;
  }
  local_54[0] = 0;
  local_52 = 0x20;
  uStack_28 = param_4;
  FUN_02334eb4(local_54,param_1,param_2,acStack_50);
  pbVar2 = DAT_02333d38;
  pbVar5 = DAT_02333d34;
  pbVar10 = DAT_02333d30;
  pbVar9 = DAT_02333d2c;
  pbVar4 = local_4b + local_4c;
  while ((1 < local_4c && (pbVar4 = pbVar4 + -1, *pbVar4 == 0x30))) {
    local_4c = local_4c - 1;
    local_4e = local_4e + 1;
  }
  if (local_4b[0] == 0x30) {
    local_4e = 0;
  }
  else {
    if (local_4b[0] == 0x49) {
      cVar13 = '\0';
      FUN_02335abc(param_1,param_2,0,0);
      pbVar2 = DAT_02333d28;
      pbVar5 = DAT_02333d24;
      pbVar10 = DAT_02333d20;
      pbVar9 = DAT_02333d1c;
      if (cVar13 != '\0') {
        pbVar9 = (byte *)(param_3 + -4);
        if (uVar11 < 0x80) {
          uVar7 = *(ushort *)(DAT_02333d18 + uVar11 * 2) & 0x200;
        }
        else {
          uVar7 = 0;
        }
        if (uVar7 == 0) {
          *pbVar9 = *DAT_02333d28;
          *(byte *)(param_3 + -3) = pbVar2[1];
          *(byte *)(param_3 + -2) = pbVar2[2];
          *(byte *)(param_3 + -1) = pbVar2[3];
          return pbVar9;
        }
        *pbVar9 = *DAT_02333d24;
        *(byte *)(param_3 + -3) = pbVar5[1];
        *(byte *)(param_3 + -2) = pbVar5[2];
        *(byte *)(param_3 + -1) = pbVar5[3];
        return pbVar9;
      }
      pbVar5 = (byte *)(param_3 + -5);
      if (uVar11 < 0x80) {
        uVar7 = *(ushort *)(DAT_02333d18 + uVar11 * 2) & 0x200;
      }
      else {
        uVar7 = 0;
      }
      if (uVar7 == 0) {
        *pbVar5 = *DAT_02333d20;
        *(byte *)(param_3 + -4) = pbVar10[1];
        *(byte *)(param_3 + -3) = pbVar10[2];
        *(byte *)(param_3 + -2) = pbVar10[3];
        *(byte *)(param_3 + -1) = pbVar10[4];
        return pbVar5;
      }
      *pbVar5 = *DAT_02333d1c;
      *(byte *)(param_3 + -4) = pbVar9[1];
      *(byte *)(param_3 + -3) = pbVar9[2];
      *(byte *)(param_3 + -2) = pbVar9[3];
      *(byte *)(param_3 + -1) = pbVar9[4];
      return pbVar5;
    }
    if (local_4b[0] == 0x4e) {
      if (acStack_50[0] != '\0') {
        pbVar5 = (byte *)(param_3 + -5);
        if (uVar11 < 0x80) {
          uVar7 = *(ushort *)(DAT_02333d18 + uVar11 * 2) & 0x200;
        }
        else {
          uVar7 = 0;
        }
        if (uVar7 == 0) {
          *pbVar5 = *DAT_02333d30;
          *(byte *)(param_3 + -4) = pbVar10[1];
          *(byte *)(param_3 + -3) = pbVar10[2];
          *(byte *)(param_3 + -2) = pbVar10[3];
          *(byte *)(param_3 + -1) = pbVar10[4];
          return pbVar5;
        }
        *pbVar5 = *DAT_02333d2c;
        *(byte *)(param_3 + -4) = pbVar9[1];
        *(byte *)(param_3 + -3) = pbVar9[2];
        *(byte *)(param_3 + -2) = pbVar9[3];
        *(byte *)(param_3 + -1) = pbVar9[4];
        return pbVar5;
      }
      pbVar9 = (byte *)(param_3 + -4);
      if (uVar11 < 0x80) {
        uVar7 = *(ushort *)(DAT_02333d18 + uVar11 * 2) & 0x200;
      }
      else {
        uVar7 = 0;
      }
      if (uVar7 == 0) {
        *pbVar9 = *DAT_02333d38;
        *(byte *)(param_3 + -3) = pbVar2[1];
        *(byte *)(param_3 + -2) = pbVar2[2];
        *(byte *)(param_3 + -1) = pbVar2[3];
        return pbVar9;
      }
      *pbVar9 = *DAT_02333d34;
      *(byte *)(param_3 + -3) = pbVar5[1];
      *(byte *)(param_3 + -2) = pbVar5[2];
      *(byte *)(param_3 + -1) = pbVar5[3];
      return pbVar9;
    }
  }
  local_4e = local_4e + (local_4c - 1);
  pbVar9 = (byte *)(param_3 + -1);
  *pbVar9 = 0;
  if (uVar11 < 0x66) {
    if (uVar11 < 0x65) {
      if (0x47 < uVar11) {
        return pbVar9;
      }
      if (uVar11 < 0x45) {
        return pbVar9;
      }
      if (uVar11 != 0x45) {
        if (uVar11 != 0x46) {
          if (uVar11 != 0x47) {
            return pbVar9;
          }
          goto LAB_02333c80;
        }
        goto LAB_02333e04;
      }
    }
LAB_02333ce8:
    if ((int)(local_64 + 1) < (int)(uint)local_4c) {
      FUN_02333980(acStack_50);
    }
    iVar6 = (int)local_4e;
    local_58 = 0x2b;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
      local_58 = 0x2d;
    }
    for (iVar12 = 0; (iVar6 != 0 || (iVar12 < 2)); iVar12 = iVar12 + 1) {
      pbVar9 = pbVar9 + -1;
      FUN_02335e0c(iVar6,10);
      *pbVar9 = extraout_r1 + 0x30;
      iVar6 = FUN_02335e0c(iVar6,10);
    }
    pbVar9[-1] = local_58;
    pbVar10 = pbVar9 + -2;
    *pbVar10 = param_5._1_1_;
    if (DAT_02333f1c < (int)(local_64 + (param_3 - (int)pbVar10))) {
      return (byte *)0x0;
    }
    if ((int)(uint)local_4c < (int)(local_64 + 1)) {
      for (iVar6 = (local_64 - local_4c) + 1; iVar6 != 0; iVar6 = iVar6 + -1) {
        pbVar10 = pbVar10 + -1;
        *pbVar10 = 0x30;
      }
    }
    uVar11 = (uint)local_4c;
    pbVar9 = local_4b + uVar11;
    while (uVar11 = uVar11 - 1, uVar11 != 0) {
      pbVar9 = pbVar9 + -1;
      pbVar10 = pbVar10 + -1;
      *pbVar10 = *pbVar9;
    }
    if ((local_64 != 0) || (uVar1 != 0)) {
      pbVar10 = pbVar10 + -1;
      *pbVar10 = 0x2e;
    }
    pbVar9 = pbVar10 + -1;
    *pbVar9 = local_4b[0];
    if (acStack_50[0] == '\0') {
      if (uVar3 == 1) {
        pbVar9 = pbVar10 + -2;
        *pbVar9 = 0x2b;
      }
      else if (uVar3 == 2) {
        pbVar9 = pbVar10 + -2;
        *pbVar9 = 0x20;
      }
    }
    else {
      pbVar9 = pbVar10 + -2;
      *pbVar9 = 0x2d;
    }
  }
  else {
    if (uVar11 < 0x67) {
      if (uVar11 != 0x66) {
        return pbVar9;
      }
    }
    else {
      if (uVar11 != 0x67) {
        return pbVar9;
      }
LAB_02333c80:
      if ((int)param_7 < (int)(uint)local_4c) {
        FUN_02333980(acStack_50,param_7);
      }
      iVar6 = (int)local_4e;
      if ((iVar6 < -4) || ((int)param_7 <= iVar6)) {
        if (uVar1 == 0) {
          param_7 = (uint)local_4c;
        }
        local_64 = param_7 - 1;
        if (uVar11 == 0x67) {
          param_5._1_1_ = 0x65;
        }
        else {
          param_5._1_1_ = 0x45;
        }
        goto LAB_02333ce8;
      }
      if (uVar1 == 0) {
        local_64 = (uint)local_4c - (iVar6 + 1);
        if ((int)local_64 < 0) {
          local_64 = 0;
        }
      }
      else {
        local_64 = param_7 - (iVar6 + 1);
      }
    }
LAB_02333e04:
    iVar6 = (int)local_4e;
    uVar11 = (uint)local_4c;
    iVar12 = (uVar11 - iVar6) + -1;
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    if ((int)local_64 < iVar12) {
      FUN_02333980(acStack_50,uVar11 - (iVar12 - local_64));
      iVar6 = (int)local_4e;
      uVar11 = (uint)local_4c;
      iVar12 = (uVar11 - iVar6) + -1;
      if (iVar12 < 0) {
        iVar12 = 0;
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (DAT_02333f1c < iVar6 + iVar12) {
      return (byte *)0x0;
    }
    pbVar10 = local_4b + uVar11;
    iVar8 = 0;
    if (0 < (int)(local_64 - iVar12)) {
      do {
        pbVar9 = pbVar9 + -1;
        iVar8 = iVar8 + 1;
        *pbVar9 = 0x30;
      } while (iVar8 < (int)(local_64 - iVar12));
    }
    for (iVar8 = 0; (iVar8 < iVar12 && (iVar8 < (int)(uint)local_4c)); iVar8 = iVar8 + 1) {
      pbVar10 = pbVar10 + -1;
      pbVar9 = pbVar9 + -1;
      *pbVar9 = *pbVar10;
    }
    for (; iVar8 < iVar12; iVar8 = iVar8 + 1) {
      pbVar9 = pbVar9 + -1;
      *pbVar9 = 0x30;
    }
    if ((local_64 != 0) || (uVar1 != 0)) {
      pbVar9 = pbVar9 + -1;
      *pbVar9 = 0x2e;
    }
    if (iVar6 == 0) {
      pbVar9 = pbVar9 + -1;
      *pbVar9 = 0x30;
    }
    else {
      iVar12 = 0;
      if (0 < (int)(iVar6 - (uint)local_4c)) {
        do {
          pbVar9 = pbVar9 + -1;
          *pbVar9 = 0x30;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)(iVar6 - (uint)local_4c));
      }
      for (; iVar12 < iVar6; iVar12 = iVar12 + 1) {
        pbVar10 = pbVar10 + -1;
        pbVar9 = pbVar9 + -1;
        *pbVar9 = *pbVar10;
      }
    }
    if (acStack_50[0] == '\0') {
      if (uVar3 == 1) {
        pbVar9 = pbVar9 + -1;
        *pbVar9 = 0x2b;
      }
      else if (uVar3 == 2) {
        pbVar9 = pbVar9 + -1;
        *pbVar9 = 0x20;
      }
    }
    else {
      pbVar9 = pbVar9 + -1;
      *pbVar9 = 0x2d;
    }
  }
  return pbVar9;
}

