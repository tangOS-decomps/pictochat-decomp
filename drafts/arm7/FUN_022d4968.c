// decomp: module=arm7 addr=0x022d4968 name=FUN_022d4968
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9a8 (Ghidra's cache says 0x998 - it excludes this function's trailing literal pool), arm
// triage: noise=46 statements=414
// verify:  python tools/match.py --c <file> --func FUN_022d4968 --addr 0x022d4968 --size 0x9a8 --module arm7 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x022d4a4c) */

void FUN_022d4968(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  ushort *puVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined2 *puVar15;
  undefined2 uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  ushort uVar21;
  short sVar22;
  short sVar23;
  int iVar24;
  uint uVar25;
  ushort *puVar26;
  uint unaff_r5;
  uint uVar27;
  ushort *puVar28;
  ushort *puVar29;
  ushort *puVar30;
  undefined4 uVar31;
  int iVar32;
  short *psVar33;
  uint uVar34;
  uint unaff_r10;
  uint uVar35;
  bool bVar36;
  bool bVar37;
  uint local_2d8;
  uint local_2bc;
  uint local_2b8;
  uint local_2b0;
  uint local_2a0;
  uint local_298;
  ushort *local_28c;
  uint local_288;
  ushort *local_280;
  ushort local_22c [2];
  undefined1 auStack_228 [512];
  undefined4 local_28;
  
  iVar32 = *(int *)(DAT_022d5300 + 0x550);
  local_28 = param_4;
  func_0x037cb520();
  uVar17 = (uint)*(ushort *)(iVar32 + 0x182);
  uVar25 = (uint)*(ushort *)(iVar32 + 0x86);
  func_0x037cb534();
  local_22c[0] = 0;
  local_2d8 = param_1;
  if (*(short *)(iVar32 + 0x88) == 1) {
    local_2d8 = DAT_022d5304;
    *(undefined2 *)(iVar32 + 0x88) = 0;
  }
  if (*(short *)(iVar32 + 0x9e) != 0) {
    uVar31 = 0;
    *(undefined2 *)(iVar32 + 0x9e) = 0;
    uVar25 = DAT_022d5308;
    local_22c[0] = 0;
    unaff_r10 = 0;
    func_0x037cb520();
    *(short *)(iVar32 + 0x62) = *(short *)(iVar32 + 0x62) + 1;
    *(short *)(iVar32 + 100) = *(short *)(iVar32 + 100) + 1;
    func_0x037cb534();
    goto LAB_022d5290;
  }
  uVar1 = *(ushort *)(iVar32 + 0x3a);
  psVar33 = *(short **)(DAT_022d5300 + 0x550);
  local_280 = local_22c;
  uVar34 = (uint)(ushort)psVar33[0x1c];
  puVar28 = *(ushort **)(psVar33 + 0x3e);
  if ((uint)(ushort)psVar33[0x40] < (uVar34 + 0x1f & 0xffffffe0)) {
    bVar37 = true;
  }
  else if ((ushort)psVar33[0xc4] < 0x10) {
    if (*psVar33 == 9) {
      bVar37 = true;
    }
    else {
      if (*psVar33 != 10) {
        bVar37 = true;
        goto LAB_022d4e90;
      }
      bVar37 = false;
    }
    unaff_r5 = 0;
    unaff_r10 = 0;
    local_22c[0] = 0;
    local_2a0 = uVar25;
    if (bVar37) {
      if (psVar33[0x3e3] != 0) {
        local_2a0 = uVar17;
      }
      bVar7 = psVar33[0x3e3] == 0;
    }
    else {
      bVar7 = false;
    }
    local_2b0 = 0;
    bVar8 = true;
    func_0x037ca044(psVar33 + 0x38e);
    if (*(int *)(psVar33 + 0x39a) == 1) {
      func_0x037ca0c8(psVar33 + 0x38e);
      bVar37 = true;
    }
    else {
      psVar33[0x39a] = 1;
      psVar33[0x39b] = 0;
      local_298 = 0;
      unaff_r10 = 0;
      while ((uVar27 = DAT_022d5304, local_298 < 4 && (2 < (int)uVar34))) {
        uVar35 = (uint)(ushort)psVar33[local_298 * 2 + 0x386];
        puVar10 = (ushort *)(psVar33 + local_298 * 2 + 0x386);
        psVar11 = psVar33 + local_298 * 2 + 0x37e;
        local_288 = DAT_022d5304;
        uVar2 = (ushort)DAT_022d5304;
        local_28c = puVar10;
        while ((uVar35 != uVar27 && (2 < (int)uVar34))) {
          puVar26 = (ushort *)(psVar33 + uVar35 * 0x10 + 0x17c);
          uVar12 = (uint)puVar26[1];
          uVar20 = uVar35;
          if ((local_2b0 & 1 << (uVar12 & 0xff)) == 0) {
            local_2b0 = local_2b0 | 1 << (uVar12 & 0xff);
            uVar13 = (uint)puVar26[3];
            if ((!bVar7) || ((uVar13 & local_2a0 & ~(uVar25 & local_2d8)) == 0)) {
              bVar36 = (puVar26[1] & 8) != 0;
              uVar18 = 0;
              uVar5 = uVar13;
              if (bVar37) {
                uVar18 = uVar13 | 1;
                uVar5 = uVar27;
              }
              bVar6 = bVar37 && uVar18 != uVar5;
              if ((puVar26[7] & 1) == 1) {
                puVar26[7] = puVar26[7] + 1;
              }
              if (bVar36) {
                iVar14 = 2;
              }
              else {
                iVar14 = 0;
              }
              if (bVar8) {
                iVar24 = 0;
              }
              else {
                iVar24 = 2;
              }
              iVar19 = 0;
              if (bVar6) {
                iVar19 = 2;
              }
              if (!bVar37 || uVar18 == uVar5) {
                iVar19 = 0;
              }
              if ((int)(iVar19 + (uint)puVar26[7] + iVar24 + iVar14) <= (int)uVar34) {
                bVar9 = !bVar8;
                puVar29 = puVar28;
                if (bVar9) {
                  puVar29 = puVar28 + 1;
                  *puVar28 = 0;
                  local_280 = puVar28;
                }
                if (bVar9) {
                  unaff_r10 = unaff_r10 + 2;
                }
                *local_280 = *local_280 | (puVar26[1] & 0xf) << 8 | puVar26[7] >> 1 & 0xff;
                if (bVar9) {
                  uVar34 = uVar34 - 2;
                }
                func_0x037cb78c(*(undefined4 *)(puVar26 + 10),puVar29);
                uVar20 = (uint)puVar26[7];
                unaff_r10 = unaff_r10 + uVar20;
                puVar29 = (ushort *)((int)puVar29 + (uVar20 & 0xfffffffe));
                uVar34 = uVar34 - uVar20;
                puVar30 = puVar29;
                if (bVar36) {
                  if ((puVar26[8] & 1) == 0) {
                    uVar21 = (ushort)((int)(uint)puVar26[8] >> 1);
                  }
                  else {
                    uVar21 = psVar33[(uint)(ushort)psVar33[0xc4] * 8 + (puVar26[1] & 7) + 0xfc];
                    psVar33[(uint)(ushort)psVar33[0xc4] * 8 + (puVar26[1] & 7) + 0xfc] = uVar21 + 1;
                    puVar26[8] = uVar21 << 1;
                  }
                  unaff_r10 = unaff_r10 + 2;
                  puVar30 = puVar29 + 1;
                  *puVar29 = uVar21 & uVar2 + 0x8000;
                  uVar34 = uVar34 - 2;
                }
                puVar28 = puVar30;
                if (bVar6) {
                  unaff_r10 = unaff_r10 + 2;
                  uVar34 = uVar34 - 2;
                  *local_280 = *local_280 | 0x1000;
                  puVar28 = puVar30 + 1;
                  *puVar30 = puVar26[3];
                }
                if (bVar8) {
                  bVar8 = false;
                }
                if (puVar10[1] == uVar35) {
                  puVar10[1] = (ushort)local_288;
                }
                *local_28c = *puVar26;
                *puVar26 = uVar2;
                sVar4 = (short)uVar35;
                if ((ushort)psVar11[1] == uVar27) {
                  *psVar11 = sVar4;
                }
                else {
                  psVar33[(uint)(ushort)psVar11[1] * 0x10 + 0x17c] = sVar4;
                }
                local_2b0 = local_2b0 & ~(1 << (uVar12 & 0xff));
                psVar11[1] = sVar4;
                puVar26[5] = (ushort)(uVar13 & local_2a0);
                unaff_r5 = unaff_r5 | puVar26[2];
                uVar20 = local_288;
                if (psVar33[0x3e4] == 1) goto LAB_022d4e7c;
              }
            }
          }
          local_288 = uVar20;
          if (uVar20 == uVar27) {
            uVar35 = (uint)*puVar10;
            local_28c = puVar10;
          }
          else {
            uVar35 = (uint)(ushort)psVar33[uVar20 * 0x10 + 0x17c];
            local_28c = (ushort *)(psVar33 + uVar20 * 0x10 + 0x17c);
          }
        }
        local_298 = local_298 + 1;
      }
LAB_022d4e7c:
      func_0x037ca0c8(psVar33 + 0x38e);
      bVar37 = false;
    }
  }
  else {
    bVar37 = true;
  }
LAB_022d4e90:
  if (bVar37) {
    *(undefined2 *)(iVar32 + 0x62) = 0;
    *(undefined2 *)(iVar32 + 100) = 0;
    return;
  }
  uVar25 = uVar1 + 2;
  if (*(short *)(iVar32 + 0x7c6) != 1) {
    unaff_r5 = local_2d8;
  }
  uVar17 = unaff_r5 & uVar17;
  iVar14 = thunk_EXT_FUN_037fef94(uVar17);
  if ((int)((uVar1 + 0xc) * iVar14 + 0x29 & 0xffffffe0) <= (int)(uint)*(ushort *)(iVar32 + 0x72)) {
    bVar37 = *(short *)(iVar32 + 0x62) != 1;
    sVar4 = 1;
    if (bVar37) {
      sVar4 = *(short *)(iVar32 + 100);
    }
    if (bVar37 && sVar4 != 1) {
      uVar31 = 0;
    }
    else {
      uVar31 = FUN_022d5c68(unaff_r10,uVar25,uVar17,*(undefined2 *)(iVar32 + 0x40));
      local_22c[0] = local_22c[0] | 0x8000;
    }
LAB_022d5290:
    FUN_022d0350(auStack_228,0,0,uVar25 & 0xffff,uVar17,uVar31,*DAT_022d530c,unaff_r10 & 0xffff,
                 local_22c[0],*(undefined4 *)(iVar32 + 0x7c));
    *(short *)(iVar32 + 0x68) = (short)uVar17;
    *(ushort *)(iVar32 + 0x6a) = local_22c[0];
    *(short *)(iVar32 + 0x6c) = (short)uVar25;
    *(short *)(iVar32 + 0x6e) = (short)unaff_r10;
    return;
  }
  psVar33 = *(short **)(DAT_022d5300 + 0x550);
  if (*psVar33 == 9) {
    bVar37 = true;
  }
  else {
    if (*psVar33 != 10) goto LAB_022d5200;
    bVar37 = false;
  }
  func_0x037ca044(psVar33 + 0x38e);
  if (*(int *)(psVar33 + 0x39a) == 0) {
    func_0x037ca0c8(psVar33 + 0x38e);
  }
  else {
    if (bVar37) {
      func_0x037cb520();
      uVar1 = psVar33[0xc1];
      func_0x037cb534();
    }
    else {
      uVar1 = 1;
    }
    iVar14 = 0;
    do {
      uVar25 = DAT_022d5304;
      local_2b8 = DAT_022d5304;
      uVar2 = psVar33[iVar14 * 2 + 0x37e];
      puVar28 = (ushort *)(psVar33 + iVar14 * 2 + 0x37e);
      local_2bc = DAT_022d5304;
      while (uVar34 = DAT_022d5304, uVar27 = (uint)uVar2, uVar27 != uVar25) {
        puVar10 = (ushort *)(psVar33 + uVar27 * 0x10 + 0x17c);
        puVar10[4] = puVar10[4] | puVar10[5] & ~(ushort)uVar17;
        puVar10[3] = puVar10[3] & ~puVar10[4];
        puVar10[3] = puVar10[3] & uVar1;
        puVar10[5] = 0;
        uVar21 = (ushort)uVar25;
        if (puVar10[3] == 0) {
LAB_022d50a0:
          puVar15 = (undefined2 *)func_0x037d14bc();
          *puVar15 = 0x81;
          if (puVar10[3] == 0) {
            uVar16 = 0;
          }
          else {
            uVar16 = 0xf;
          }
          puVar15[1] = uVar16;
          puVar15[4] = 0x14;
          puVar15[5] = puVar10[1];
          puVar15[6] = puVar10[2];
          puVar15[7] = puVar10[3];
          puVar15[8] = puVar10[4];
          puVar15[0xc] = puVar10[7];
          *(undefined4 *)(puVar15 + 10) = *(undefined4 *)(puVar10 + 10);
          *(undefined4 *)(puVar15 + 0xe) = *(undefined4 *)(puVar10 + 0xc);
          *(undefined4 *)(puVar15 + 0x10) = *(undefined4 *)(puVar10 + 0xe);
          puVar15[0xd] = puVar10[8];
          sVar4 = psVar33[0x18];
          sVar22 = psVar33[0x19];
          sVar23 = sVar4;
          if (psVar33[0xc4] != 0) {
            sVar23 = sVar22;
          }
          puVar15[0x12] = sVar23;
          if (psVar33[0xc4] != 0) {
            sVar22 = sVar4;
          }
          puVar15[0x13] = sVar22;
          func_0x037d1464();
          if (*puVar10 == uVar25) {
            puVar28[1] = uVar21;
          }
          *puVar28 = *puVar10;
          *puVar10 = uVar21;
          if ((ushort)psVar33[0x37d] == uVar25) {
            psVar33[0x37c] = uVar2;
          }
          else {
            psVar33[(uint)(ushort)psVar33[0x37d] * 0x10 + 0x17c] = uVar2;
          }
          psVar33[0x37d] = uVar2;
          uVar34 = local_2bc;
          uVar27 = local_2b8;
        }
        else {
          uVar3 = puVar10[1];
          bVar37 = (uVar3 & 8) == 0;
          if (bVar37) {
            uVar3 = puVar10[9];
          }
          if (bVar37 && uVar3 == 0) goto LAB_022d50a0;
          if (puVar10[9] != 0) {
            puVar10[9] = puVar10[9] - 1;
          }
          if (*puVar10 == uVar25) {
            puVar28[1] = uVar21;
          }
          *puVar28 = *puVar10;
          *puVar10 = uVar21;
          uVar34 = uVar27;
          if (local_2b8 != uVar25) {
            psVar33[local_2b8 * 0x10 + 0x17c] = uVar2;
            uVar34 = local_2bc;
          }
        }
        local_2b8 = uVar27;
        local_2bc = uVar34;
        uVar2 = *puVar28;
      }
      if (local_2b8 != DAT_022d5304) {
        psVar33[local_2b8 * 0x10 + 0x17c] = psVar33[iVar14 * 2 + 0x386];
        if ((ushort)psVar33[iVar14 * 2 + 0x387] == uVar34) {
          psVar33[iVar14 * 2 + 0x387] = (short)local_2b8;
        }
        psVar33[iVar14 * 2 + 0x386] = (short)local_2bc;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < 4);
    psVar33[0x39a] = 0;
    psVar33[0x39b] = 0;
    func_0x037ca0c8(psVar33 + 0x38e);
  }
LAB_022d5200:
  *(undefined2 *)(iVar32 + 0x62) = 0;
  *(undefined2 *)(iVar32 + 100) = 0;
  return;
}

