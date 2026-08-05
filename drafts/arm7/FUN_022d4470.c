// decomp: module=arm7 addr=0x022d4470 name=FUN_022d4470
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4f8 (Ghidra's cache says 0x4f0 - it excludes this function's trailing literal pool), arm
// triage: noise=22 statements=219
// verify:  python tools/match.py --c <file> --func FUN_022d4470 --addr 0x022d4470 --size 0x4f8 --module arm7 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x022d4508) */

void FUN_022d4470(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  bool bVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  ushort *puVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  ushort uVar16;
  undefined4 in_r3;
  int iVar17;
  ushort *puVar18;
  uint uVar19;
  uint unaff_r6;
  ushort *puVar20;
  ushort *puVar21;
  ushort *puVar22;
  short *psVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  bool bVar27;
  bool bVar28;
  uint local_27c;
  ushort *local_260;
  uint local_25c;
  ushort *local_254;
  ushort local_22c [2];
  undefined1 auStack_228 [512];
  undefined4 local_28;
  
  iVar12 = DAT_022d4960;
  iVar26 = *(int *)(DAT_022d4960 + 0x550);
  if (*(short *)(iVar26 + 0x182) == 0) {
    return;
  }
  *(undefined2 *)(iVar26 + 0x8a) = 1;
  bVar28 = true;
  local_22c[0] = 0;
  psVar23 = *(short **)(iVar12 + 0x550);
  local_254 = local_22c;
  uVar24 = (uint)(ushort)psVar23[0x1c];
  puVar20 = *(ushort **)(psVar23 + 0x3e);
  local_28 = in_r3;
  if (((uVar24 + 0x1f & 0xffffffe0) <= (uint)(ushort)psVar23[0x40]) &&
     ((ushort)psVar23[0xc4] < 0x10)) {
    if (*psVar23 != 9) {
      if (*psVar23 != 10) goto LAB_022d4900;
      bVar28 = false;
    }
    unaff_r6 = 0;
    local_22c[0] = 0;
    local_27c = 0;
    bVar6 = true;
    func_0x037ca044(psVar23 + 0x38e);
    if (*(int *)(psVar23 + 0x39a) == 1) {
      func_0x037ca0c8(psVar23 + 0x38e);
      bVar28 = true;
    }
    else {
      psVar23[0x39a] = 1;
      psVar23[0x39b] = 0;
      uVar19 = 0;
      while ((uVar8 = DAT_022d4964, uVar19 < 4 && (2 < (int)uVar24))) {
        uVar25 = (uint)(ushort)psVar23[uVar19 * 2 + 0x386];
        puVar9 = (ushort *)(psVar23 + uVar19 * 2 + 0x386);
        psVar10 = psVar23 + uVar19 * 2 + 0x37e;
        local_25c = DAT_022d4964;
        uVar5 = (ushort)DAT_022d4964;
        local_260 = puVar9;
        while ((uVar25 != uVar8 && (2 < (int)uVar24))) {
          puVar18 = (ushort *)(psVar23 + uVar25 * 0x10 + 0x17c);
          uVar11 = (uint)puVar18[1];
          uVar15 = uVar25;
          if ((local_27c & 1 << (uVar11 & 0xff)) == 0) {
            local_27c = local_27c | 1 << (uVar11 & 0xff);
            uVar1 = puVar18[3];
            bVar27 = (puVar18[1] & 8) != 0;
            uVar13 = 0;
            uVar3 = (uint)uVar1;
            if (bVar28) {
              uVar13 = uVar1 | 1;
              uVar3 = uVar8;
            }
            bVar4 = bVar28 && uVar13 != uVar3;
            if ((puVar18[7] & 1) == 1) {
              puVar18[7] = puVar18[7] + 1;
            }
            if (bVar27) {
              iVar12 = 2;
            }
            else {
              iVar12 = 0;
            }
            if (bVar6) {
              iVar17 = 0;
            }
            else {
              iVar17 = 2;
            }
            iVar14 = 0;
            if (bVar4) {
              iVar14 = 2;
            }
            if (!bVar28 || uVar13 == uVar3) {
              iVar14 = 0;
            }
            if ((int)(iVar14 + (uint)puVar18[7] + iVar17 + iVar12) <= (int)uVar24) {
              bVar7 = !bVar6;
              puVar21 = puVar20;
              if (bVar7) {
                puVar21 = puVar20 + 1;
                *puVar20 = 0;
                local_254 = puVar20;
              }
              if (bVar7) {
                unaff_r6 = unaff_r6 + 2;
              }
              *local_254 = *local_254 | (puVar18[1] & 0xf) << 8 | puVar18[7] >> 1 & 0xff;
              if (bVar7) {
                uVar24 = uVar24 - 2;
              }
              func_0x037cb78c(*(undefined4 *)(puVar18 + 10),puVar21);
              uVar15 = (uint)puVar18[7];
              unaff_r6 = unaff_r6 + uVar15;
              puVar21 = (ushort *)((int)puVar21 + (uVar15 & 0xfffffffe));
              uVar24 = uVar24 - uVar15;
              puVar22 = puVar21;
              if (bVar27) {
                if ((puVar18[8] & 1) == 0) {
                  uVar16 = (ushort)((int)(uint)puVar18[8] >> 1);
                }
                else {
                  uVar16 = psVar23[(uint)(ushort)psVar23[0xc4] * 8 + (puVar18[1] & 7) + 0xfc];
                  psVar23[(uint)(ushort)psVar23[0xc4] * 8 + (puVar18[1] & 7) + 0xfc] = uVar16 + 1;
                  puVar18[8] = uVar16 << 1;
                }
                unaff_r6 = unaff_r6 + 2;
                puVar22 = puVar21 + 1;
                *puVar21 = uVar16 & uVar5 + 0x8000;
                uVar24 = uVar24 - 2;
              }
              puVar20 = puVar22;
              if (bVar4) {
                unaff_r6 = unaff_r6 + 2;
                uVar24 = uVar24 - 2;
                *local_254 = *local_254 | 0x1000;
                puVar20 = puVar22 + 1;
                *puVar22 = puVar18[3];
              }
              if (bVar6) {
                bVar6 = false;
              }
              if (puVar9[1] == uVar25) {
                puVar9[1] = (ushort)local_25c;
              }
              *local_260 = *puVar18;
              *puVar18 = uVar5;
              sVar2 = (short)uVar25;
              if ((ushort)psVar10[1] == uVar8) {
                *psVar10 = sVar2;
              }
              else {
                psVar23[(uint)(ushort)psVar10[1] * 0x10 + 0x17c] = sVar2;
              }
              local_27c = local_27c & ~(1 << (uVar11 & 0xff));
              psVar10[1] = sVar2;
              puVar18[5] = uVar1 & 1;
              uVar15 = local_25c;
              if (psVar23[0x3e4] == 1) goto LAB_022d48ec;
            }
          }
          local_25c = uVar15;
          if (uVar15 == uVar8) {
            uVar25 = (uint)*puVar9;
            local_260 = puVar9;
          }
          else {
            uVar25 = (uint)(ushort)psVar23[uVar15 * 0x10 + 0x17c];
            local_260 = (ushort *)(psVar23 + uVar15 * 0x10 + 0x17c);
          }
        }
        uVar19 = uVar19 + 1;
      }
LAB_022d48ec:
      func_0x037ca0c8(psVar23 + 0x38e);
      bVar28 = false;
    }
  }
LAB_022d4900:
  if (bVar28) {
    *(undefined2 *)(iVar26 + 0x8a) = 0;
  }
  else {
    uVar24 = *(uint *)(iVar26 + 0x1c);
    bVar28 = uVar24 == 1;
    if (bVar28) {
      uVar24 = (uint)local_22c[0];
    }
    if (bVar28) {
      local_22c[0] = (ushort)uVar24 | 0x8000;
    }
    iVar12 = FUN_022d02e8(auStack_228,unaff_r6 & 0xffff,local_22c[0],*(undefined4 *)(iVar26 + 0x7c))
    ;
    if (*(short *)(iVar12 + 4) != 0 && *(short *)(iVar12 + 4) != 8) {
      *(undefined2 *)(iVar26 + 0x8a) = 0;
    }
  }
  return;
}

