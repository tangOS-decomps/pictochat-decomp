// decomp: module=unk_autoload_0 addr=0x0232679c name=FUN_0232679c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x410 (Ghidra's cache says 0x3f0 - it excludes this function's trailing literal pool), thumb
// triage: noise=23 statements=240
// verify:  python tools/match.py --c <file> --func FUN_0232679c --addr 0x0232679c --size 0x410 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232679c(int param_1,uint param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int unaff_r5;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int local_d4;
  int local_d0;
  short local_c4;
  int local_c0;
  int local_a4;
  undefined4 local_a0 [7];
  int local_84 [7];
  int local_68 [7];
  int local_4c [7];
  undefined4 local_30 [7];
  
  param_2 = param_2 >> 0xb;
  if (param_1 != 0) {
    iVar12 = *(int *)(DAT_02326adc + 0x20);
    FUN_0233746c(0,*(int *)(DAT_02326adc + 0xc) + iVar12 * 0x400,0x400);
    local_c0 = FUN_02326764(iVar12);
    iVar12 = param_2 * 2;
    for (iVar13 = 0; iVar13 < iVar12; iVar13 = iVar13 + 1) {
      FUN_023374b8(param_1 + iVar13 * 0x400,*(int *)(DAT_02326adc + 0xc) + local_c0 * 0x400,0x400);
      local_c0 = FUN_02326764(local_c0);
    }
    iVar13 = *(int *)(DAT_02326adc + 0x20);
    FUN_023374b8(DAT_02326ae0,*(int *)(DAT_02326adc + 0x10) + iVar13 * 0x40,0x40);
    iVar13 = FUN_02326764(iVar13);
    for (iVar15 = 0; iVar15 < (int)((param_2 - 1) * 2 + 1); iVar15 = iVar15 + 1) {
      FUN_023374b8(DAT_02326ae4,*(int *)(DAT_02326adc + 0x10) + iVar13 * 0x40,0x40);
      iVar13 = FUN_02326764(iVar13);
    }
    FUN_023374b8(DAT_02326ae8,*(int *)(DAT_02326adc + 0x10) + iVar13 * 0x40,0x40);
    FUN_02326764(iVar13);
    if (param_3 < 0x10) {
      local_c4 = (((ushort)((uint)(param_3 * -0x80000000 + (param_3 >> 0x1f)) >> 0x1f) |
                  (ushort)((param_3 >> 0x1f) << 1)) - (short)(param_3 >> 0x1f)) * 0x20;
      unaff_r5 = param_3 / 2 + 8;
    }
    else {
      switch(param_3) {
      case 0x10:
        local_c4 = 0;
        unaff_r5 = 3;
        break;
      case 0x11:
        local_c4 = 0;
        unaff_r5 = 3;
        break;
      case 0x12:
        local_c4 = 0;
        unaff_r5 = 4;
        break;
      case 0x13:
        local_c4 = 0x20;
        unaff_r5 = 4;
      }
    }
    local_a4 = *(int *)(DAT_02326adc + 0x20);
    iVar13 = iVar12 + 1;
    for (iVar15 = 0; iVar15 < iVar13; iVar15 = iVar15 + 1) {
      iVar5 = 0;
      do {
        iVar14 = local_a4 * 0x40 + *(int *)(DAT_02326adc + 0x10);
        iVar16 = iVar5 * 2;
        uVar1 = *(ushort *)(iVar14 + iVar16);
        iVar5 = iVar5 + 1;
        *(ushort *)(iVar14 + iVar16) =
             (ushort)(unaff_r5 << 0xc) |
             (uVar1 & (ushort)DAT_02326aec) + local_c4 | uVar1 & 0x400 | uVar1 & 0x800;
      } while (iVar5 < 0x20);
      local_a4 = FUN_02326764(local_a4);
    }
    iVar15 = FUN_02326764(*(int *)(DAT_02326adc + 0x20));
    iVar5 = *(int *)(DAT_02326adc + 0xc);
    local_d0 = *(int *)(DAT_02326adc + 0x20);
    for (iVar14 = 0; iVar14 < iVar13; iVar14 = iVar14 + 1) {
      if ((param_4 == 0) || (iVar14 != 1)) {
        *(undefined2 *)(*(int *)(DAT_02326adc + 8) + local_d0 * 0x1c + 4) = 0;
      }
      else {
        FUN_02337424(param_4,*(int *)(DAT_02326adc + 8) + local_d0 * 0x1c + 4,0x14);
      }
      iVar16 = local_d0 * 0x1c;
      if (param_3 < 0x10) {
        iVar4 = *(int *)(DAT_02326adc + 8);
        uVar2 = (undefined1)param_3;
      }
      else {
        iVar4 = *(int *)(DAT_02326adc + 8);
        uVar2 = 0x10;
      }
      *(undefined1 *)(iVar4 + iVar16 + 0x1a) = uVar2;
      *(int *)(*(int *)(DAT_02326adc + 8) + iVar16) = iVar5 + iVar15 * 0x400;
      *(char *)(*(int *)(DAT_02326adc + 8) + iVar16 + 0x1b) = (char)param_2;
      local_d0 = FUN_02326764(local_d0);
    }
    iVar14 = *(int *)(DAT_02326adc + 0x20);
    iVar5 = *(int *)(DAT_02326adc + 0x18);
    uVar3 = FUN_0232673c(iVar14 + iVar12 + 1);
    iVar15 = DAT_02326adc;
    *(undefined4 *)(DAT_02326adc + 0x20) = uVar3;
    if (iVar14 == iVar5) {
      *(undefined4 *)(iVar15 + 0x18) = uVar3;
      *(undefined4 *)(iVar15 + 0x1c) = uVar3;
    }
    iVar15 = DAT_02326adc;
    iVar13 = *(int *)(DAT_02326adc + 4) + iVar13;
    *(int *)(DAT_02326adc + 4) = iVar13;
    if (0x380 < iVar13) {
      *(undefined4 *)(iVar15 + 4) = 0x380;
    }
    if (0x380 < *(int *)(DAT_02326adc + 4) + iVar12 + 1) {
      FUN_02332e10((int)local_a0);
      iVar5 = *(int *)(DAT_02326adc + 0x20);
      iVar15 = FUN_0232673c(iVar5 + 0x80);
      iVar13 = DAT_02326adc;
      for (; iVar5 != iVar15; iVar5 = FUN_02326764(iVar5)) {
        if (*(int *)(*(int *)(iVar13 + 8) + iVar5 * 0x1c) != 0) {
          FUN_0233746c(0,*(int *)(iVar13 + 0xc) + iVar5 * 0x400,0x400);
          FUN_0233746c(0,*(int *)(iVar13 + 0x10) + iVar5 * 0x40,0x40);
          puVar8 = local_a0;
          puVar11 = (undefined4 *)(*(int *)(iVar13 + 8) + iVar5 * 0x1c);
          iVar14 = 3;
          do {
            uVar3 = *puVar8;
            uVar7 = puVar8[1];
            puVar8 = puVar8 + 2;
            *puVar11 = uVar3;
            puVar11[1] = uVar7;
            puVar11 = puVar11 + 2;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          *puVar11 = *puVar8;
        }
      }
      iVar14 = iVar15 * 0x1c;
      iVar5 = *(int *)(DAT_02326adc + 8);
      iVar16 = 0;
      piVar10 = (int *)(iVar5 + iVar14);
      piVar9 = local_68;
      iVar13 = 3;
      do {
        iVar4 = *piVar10;
        iVar6 = piVar10[1];
        piVar10 = piVar10 + 2;
        *piVar9 = iVar4;
        piVar9[1] = iVar6;
        piVar9 = piVar9 + 2;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      *piVar9 = *piVar10;
      local_d4 = iVar15;
      if (local_68[0] != 0) {
        for (; iVar5 = *(int *)(DAT_02326adc + 8), local_68[0] == *(int *)(iVar5 + local_d4 * 0x1c);
            local_d4 = FUN_02326764(local_d4)) {
          iVar16 = iVar16 + 1;
        }
      }
      if (iVar16 != (uint)*(byte *)(iVar5 + iVar14 + 0x1b) * 2 + 1) {
        FUN_02332e10((int)local_30);
        iVar13 = DAT_02326adc;
        piVar9 = local_4c;
        iVar5 = 3;
        piVar10 = (int *)(*(int *)(DAT_02326adc + 8) + iVar14);
        do {
          iVar14 = *piVar10;
          iVar16 = piVar10[1];
          piVar10 = piVar10 + 2;
          *piVar9 = iVar14;
          piVar9[1] = iVar16;
          piVar9 = piVar9 + 2;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        *piVar9 = *piVar10;
        for (; local_4c[0] == *(int *)(*(int *)(iVar13 + 8) + iVar15 * 0x1c);
            iVar15 = FUN_02326764(iVar15)) {
          FUN_0233746c(0,*(int *)(iVar13 + 0xc) + iVar15 * 0x400,0x400);
          FUN_0233746c(0,*(int *)(iVar13 + 0x10) + iVar15 * 0x40,0x40);
          puVar8 = local_30;
          puVar11 = (undefined4 *)(*(int *)(iVar13 + 8) + iVar15 * 0x1c);
          iVar5 = 3;
          do {
            uVar3 = *puVar8;
            uVar7 = puVar8[1];
            puVar8 = puVar8 + 2;
            *puVar11 = uVar3;
            puVar11[1] = uVar7;
            puVar11 = puVar11 + 2;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          *puVar11 = *puVar8;
        }
      }
      iVar15 = FUN_02326774(*(int *)(DAT_02326ba8 + 0x18));
      iVar13 = DAT_02326ba8;
      if ((*(int *)(*(int *)(DAT_02326ba8 + 8) + iVar15 * 0x1c) == 0) &&
         (0x380 < *(int *)(DAT_02326ba8 + 4) + iVar12 + 1)) {
        iVar12 = *(int *)(DAT_02326ba8 + 0x18);
        while (iVar15 = DAT_02326ba8, iVar5 = *(int *)(iVar13 + 8),
              piVar9 = (int *)(iVar5 + iVar12 * 0x1c), *(int *)(iVar5 + iVar12 * 0x1c) == 0) {
          iVar12 = FUN_02326764(iVar12);
          *(int *)(iVar13 + 0x18) = iVar12;
        }
        piVar10 = local_84;
        iVar12 = 3;
        do {
          iVar13 = *piVar9;
          iVar5 = piVar9[1];
          piVar9 = piVar9 + 2;
          *piVar10 = iVar13;
          piVar10[1] = iVar5;
          piVar10 = piVar10 + 2;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *piVar10 = *piVar9;
        iVar12 = *(int *)(DAT_02326ba8 + 0x18);
        while (local_84[0] == *(int *)(*(int *)(iVar15 + 8) + iVar12 * 0x1c)) {
          iVar12 = FUN_02326764(iVar12);
          *(int *)(iVar15 + 0x18) = iVar12;
        }
      }
    }
  }
  return;
}

