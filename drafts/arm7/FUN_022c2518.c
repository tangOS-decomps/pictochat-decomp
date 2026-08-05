// decomp: module=arm7 addr=0x022c2518 name=FUN_022c2518
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4bc (Ghidra's cache says 0x490 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=178
// verify:  python tools/match.py --c <file> --func FUN_022c2518 --addr 0x022c2518 --size 0x4bc --module arm7 --version 2.0/sp1


void FUN_022c2518(void)

{
  int iVar1;
  ushort uVar2;
  undefined2 *puVar3;
  short sVar4;
  ushort uVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  uint uVar12;
  ushort *puVar13;
  ushort *puVar14;
  ushort *puVar15;
  ushort *puVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  ushort *puVar20;
  uint uVar21;
  ushort uVar22;
  uint uVar23;
  ushort *puVar24;
  bool bVar25;
  undefined8 uVar26;
  
  puVar3 = DAT_022c29ac;
  iVar19 = *DAT_022c29a8;
  uVar5 = *(ushort *)(iVar19 + 0x690);
  *DAT_022c29ac = 1;
  sVar4 = (short)iVar19 + 0xdc;
  bVar25 = *(short *)(iVar19 + 0x350) == 0;
  if (bVar25) {
    sVar4 = puVar3[0x22];
  }
  if (bVar25) {
    puVar3[0x25] = sVar4;
  }
  puVar24 = DAT_022c29b0 + -0x38;
  puVar6 = DAT_022c29b0 + 0xda;
  puVar7 = DAT_022c29b4 + -0xaa;
  puVar8 = DAT_022c29b0 + -0x22;
  uVar9 = DAT_022c29b8 - 0x29;
  uVar10 = DAT_022c29b8 + 0x3d;
  puVar11 = DAT_022c29bc + -0x12;
  uVar12 = DAT_022c29b8 + 0x710;
  do {
    uVar21 = (uint)*(ushort *)(iVar19 + 0x4e0);
    uVar2 = *puVar8;
    uVar23 = (uint)uVar2;
    if (uVar21 == uVar23) {
LAB_022c2928:
      if ((uVar5 & 1) != 0) {
        sVar4 = *DAT_022c29cc;
        uVar5 = FUN_022c2f98();
        if ((uVar5 != 0) && (sVar4 == *DAT_022c29cc)) {
          if ((uVar5 & 2) == 0) {
            if ((uVar5 & 1) != 0) {
              func_0x00dd48a8(0x100);
            }
          }
          else {
            func_0x00dd48a8(0x80);
          }
        }
      }
      if (*DAT_022c29d0 != DAT_022c29d0[-3]) {
        FUN_022c0e48(0,0xf);
      }
      return;
    }
    if (DAT_022c29b0[0x30] < DAT_022c29b0[0x30]) {
      uVar22 = *puVar7 << 0xc | DAT_022c29b0[0x30] >> 4;
    }
    else {
      uVar22 = *puVar7 << 0xc | DAT_022c29b0[0x30] >> 4;
    }
    if ((uVar9 <= uVar21) && (uVar21 <= DAT_022c29b8)) {
      func_0x00dd3a08();
    }
    iVar17 = uVar21 * 2;
    puVar20 = (ushort *)(&DAT_04804000 + iVar17);
    puVar13 = (ushort *)FUN_022c2f70(&DAT_04804002 + iVar17);
    puVar14 = (ushort *)FUN_022c2f70(puVar13 + 1);
    puVar15 = (ushort *)FUN_022c2f70(puVar14 + 2);
    puVar16 = (ushort *)FUN_022c2f70(iVar17 + 0x480400e);
    *(ushort *)(&DAT_04804000 + iVar17) =
         *(ushort *)(&DAT_04804000 + iVar17) | (*puVar13 & 0x200) << 1;
    *puVar14 = uVar22;
    uVar18 = (uint)*puVar15;
    uVar21 = (uVar18 + uVar21 * 2 + 0xf >> 2) * 2;
    if (0xfaf < uVar21) {
      uVar21 = uVar21 - (*(ushort *)(iVar19 + 0x3de) >> 1);
    }
    uVar22 = (ushort)DAT_022c29c0;
    if (uVar10 < uVar18) {
      *puVar20 = uVar22;
      *(short *)(iVar19 + 0x3f8) = *(short *)(iVar19 + 0x3f8) + 1;
      uVar21 = uVar23;
    }
    else if ((uVar5 & 1) != 0 && uVar21 != uVar23) {
      iVar1 = uVar21 * 2;
      puVar14 = (ushort *)(&DAT_04804000 + iVar1);
      if (puVar14 < puVar11) {
        uVar23 = *(ushort *)(iVar1 + 0x4804006) & 0xff;
      }
      else {
        uVar23 = (int)puVar14 - (uint)*(ushort *)(iVar19 + 0x3de);
      }
      if (puVar14 >= puVar11) {
        uVar23 = (uint)*(ushort *)(uVar23 + 6);
      }
      if ((((*(ushort *)(&DAT_04804000 + iVar1) & 0x7c00) != 0) || (uVar23 != 10 && uVar23 != 0x14))
         || (uVar12 < uVar18)) {
        *(short *)(iVar19 + 0x3f8) = *(short *)(iVar19 + 0x3f8) + 1;
        *puVar20 = uVar22;
        *(ushort *)(iVar19 + 0x4e0) = uVar2;
        *puVar13 = uVar2;
        goto LAB_022c2928;
      }
    }
    if ((*puVar20 & 0xf) == 0xc) {
      puVar14 = (ushort *)FUN_022c2f70(iVar17 + 0x480400c);
      uVar2 = *puVar14;
      puVar14 = (ushort *)FUN_022c2f70(iVar17 + 0x4804022);
      uVar22 = *puVar14;
      if ((*(ushort *)(iVar19 + 0x4dc) == uVar22) && ((uVar2 & 0x800) != 0)) {
        *(int *)(*DAT_022c29a8 + 0x57c) = *(int *)(*DAT_022c29a8 + 0x57c) + 1;
        *puVar20 = (ushort)DAT_022c29c0;
      }
      else {
        iVar17 = *DAT_022c29a8;
        uVar23 = iVar17 + 0x300;
        bVar25 = -1 < (int)((uint)*(ushort *)(iVar17 + 0x33a) << 0x18);
        if (bVar25) {
          uVar23 = (uint)*(ushort *)(iVar17 + 0x34c);
        }
        if (bVar25 && uVar23 == 0x40) {
          if ((*puVar24 == 0) || ((*DAT_022c29b0 & 0x8000) == 0)) {
            uVar22 = (ushort)DAT_022c29c0;
            *DAT_022c29bc = uVar22;
            *puVar6 = uVar22;
            *DAT_022c29b4 = uVar22;
            *puVar20 = uVar22;
          }
          else {
            FUN_022c6600(iVar17 + 0x660);
            uVar23 = (uint)((ulonglong)DAT_022c29c4 * (ulonglong)*puVar16 >> 0x20);
            uVar26 = FUN_022c3f7c((uint)((ulonglong)DAT_022c29c4 * (ulonglong)*puVar16) >> 6 |
                                  uVar23 * 0x4000000,uVar23 >> 6,1000);
            FUN_022c651c(*DAT_022c29a8 + 0x660,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20),
                         DAT_022c29c8,0);
          }
        }
      }
      *(ushort *)(iVar19 + 0x4dc) = uVar22;
      uVar23 = FUN_022c2f98();
      if ((uVar23 & 1) != 0) {
        *(int *)(*DAT_022c29a8 + 0x5a8) = *(int *)(*DAT_022c29a8 + 0x5a8) + 1;
      }
    }
    else if ((*puVar20 & 0xf) == 0xd) {
      iVar17 = *DAT_022c29a8;
      uVar23 = iVar17 + 0x300;
      bVar25 = -1 < (int)((uint)*(ushort *)(iVar17 + 0x33a) << 0x18);
      if (bVar25) {
        uVar23 = (uint)*(ushort *)(iVar17 + 0x34c);
      }
      if ((bVar25 && uVar23 == 0x40) && ((*puVar24 == 0 || ((*DAT_022c29b0 & 0x8000) == 0)))) {
        *puVar20 = (ushort)DAT_022c29c0;
      }
    }
    *(ushort *)(iVar19 + 0x4e0) = (ushort)uVar21;
    *puVar13 = (ushort)uVar21;
  } while( true );
}

