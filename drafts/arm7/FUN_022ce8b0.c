// decomp: module=arm7 addr=0x022ce8b0 name=FUN_022ce8b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1194, arm
// triage: noise=244 statements=733
// verify:  python tools/match.py --c <file> --func FUN_022ce8b0 --addr 0x022ce8b0 --size 0x1194 --module arm7 --version 2.0/sp1


void FUN_022ce8b0(void)

{
  ushort uVar1;
  ushort uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  void *msg;
  int iVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  ushort uVar12;
  int extraout_r1;
  uint uVar13;
  undefined1 uVar14;
  uint uVar15;
  ushort *in_r3;
  void *ctx;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  ushort *unaff_r8;
  ushort *puVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  bool bVar23;
  undefined8 uVar24;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  void *local_2c;
  ushort *local_28;
  
  local_28 = in_r3;
  do {
    do {
      while( true ) {
        func_0x037c9f1c(DAT_022cf72c + 0x28,&local_2c,1);
        msg = local_2c;
        if (local_2c == (void *)0x0) {
          func_0x037c9920();
          return;
        }
        uVar12 = *(ushort *)((int)local_2c + 0xc);
        if (((uVar12 & 0xff00) == 0 || (uVar12 & 0xff00) == 0x100) && ((uVar12 & 0x80) != 0)) break;
        func_0x037c9e90(DAT_022cf72c + 0x58,local_2c,1);
      }
      bVar22 = *(int *)(DAT_022cf730 + 0x54c) == 0;
      if (!bVar22) {
        unaff_r8 = *(ushort **)(DAT_022cf730 + 0x550);
        in_r3 = (ushort *)(uint)*unaff_r8;
      }
    } while (bVar22 || in_r3 == (ushort *)0x1);
    uVar15 = (uint)*(ushort *)((int)local_2c + 0xc);
    if (DAT_022cf734 < (int)uVar15) {
      if (DAT_022cf734 + 3 < (int)uVar15) {
        if (uVar15 == DAT_022cf734 + 4U) {
          uVar12 = unaff_r8[0x3e6];
          bVar22 = uVar12 != 1;
          if (!bVar22) {
            uVar12 = *(ushort *)((int)local_2c + 0x10);
          }
          if (bVar22 || uVar12 != 0x20) {
            puVar10 = FUN_022ce718();
            uVar7 = DAT_022cfa3c;
            if (puVar10 == (undefined4 *)0x0) {
              iVar5 = 0;
            }
            else {
              *puVar10 = 0x25;
              puVar10[2] = uVar7;
              uVar12 = *unaff_r8;
              if (uVar12 == 9 || uVar12 == 7) {
                puVar10[1] = DAT_022cfa40;
              }
              else if (uVar12 == 10 || uVar12 == 8) {
                puVar10[1] = 1;
              }
              iVar5 = func_0x037c9e90(DAT_022cf738,puVar10,0);
            }
            if (iVar5 == 0) {
              puVar6 = (undefined2 *)func_0x037d14bc();
              *puVar6 = 0x80;
              puVar6[1] = 8;
              puVar6[2] = 0x16;
              puVar6[3] = 0x25;
              func_0x037d1464();
            }
          }
          else {
            uVar7 = func_0x037cb520();
            func_0x037cade0(DAT_022cf748);
            unaff_r8[0x42] = 0;
            func_0x037cb534(uVar7);
            unaff_r8[0x45] = 0;
            FUN_022d5540(1);
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 0x80;
            puVar6[1] = 0;
            puVar6[2] = 0x17;
            puVar6[3] = 1;
            func_0x037d1464();
          }
        }
      }
      else if ((int)uVar15 < DAT_022cf734 + 3) {
        if ((uVar15 == 0x184) && (*(int *)(unaff_r8 + 6) != 0)) {
          if ((*(short *)((int)local_2c + 0x12) == 0) &&
             ((unaff_r8[0x33] != 1 || (*(short *)((int)local_2c + 0x10) == 0)))) {
            if (unaff_r8[0x33] != 0) {
              unaff_r8[0x33] = 0;
            }
            in_r3 = (ushort *)(uint)unaff_r8[0x38];
            puVar17 = *(ushort **)(unaff_r8 + (int)in_r3 * 2 + 0x3a);
            uVar15 = (uint)*(ushort *)((int)local_2c + 0x16) *
                     (uint)*(ushort *)((int)local_2c + 0x14) + 10;
            if (unaff_r8[0x39] < uVar15) {
              uVar15 = (uint)unaff_r8[0x39];
            }
            func_0x037cb8b4((int)local_2c + 0x10,puVar17,uVar15);
            iVar5 = *(int *)(DAT_022cf730 + 0x550);
            uVar15 = (uint)*(ushort *)(iVar5 + 0xbe);
            if ((*puVar17 == 0) && (*(short *)((int)msg + 0x14) != 0)) {
              for (iVar16 = 0; iVar16 < (int)(uint)*(ushort *)((int)msg + 0x14); iVar16 = iVar16 + 1
                  ) {
                uVar8 = FUN_022cfa7c((uint)*(byte *)((int)msg +
                                                    (uint)*(ushort *)((int)msg + 0x16) * iVar16 +
                                                    0x1d));
                if (uVar8 < uVar15) {
                  uVar15 = uVar8;
                }
              }
              *(short *)(iVar5 + 0xbe) = (short)uVar15;
            }
            uVar24 = func_0x037caa3c();
            iVar5 = (int)((ulonglong)uVar24 >> 0x20);
            uVar15 = (uint)uVar24 | 1;
            uVar20 = (uint)*puVar17;
            uVar8 = 0x18000 - DAT_022cf754;
            puVar19 = puVar17 + 5;
            for (uVar12 = 0; uVar12 < puVar17[2]; uVar12 = uVar12 + 1) {
              uVar1 = puVar19[2];
              uVar18 = (uint)uVar1;
              uVar13 = (uint)*puVar19;
              if ((uVar18 != 0) && (uVar18 < 0x10)) {
                if ((uVar13 < 2) || (uVar13 == uVar8)) {
                  if (uVar13 == 0) {
                    uVar13 = *(uint *)(unaff_r8 + uVar18 * 4 + 0x39c);
                    uVar20 = uVar20 | 1 << (uVar18 & 0xff);
                    uVar21 = *(uint *)(unaff_r8 + 0x3de);
                    puVar9 = *(ushort **)(unaff_r8 + 0x3dc);
                    in_r3 = (ushort *)0x0;
                    if ((uVar21 != 0 || puVar9 != (ushort *)0x0) &&
                       (*(int *)(unaff_r8 + uVar18 * 4 + 0x39e) != 0 || uVar13 != 0)) {
                      in_r3 = (ushort *)(uVar15 - uVar13);
                      uVar13 = iVar5 - (*(int *)(unaff_r8 + uVar18 * 4 + 0x39e) +
                                       (uint)(uVar15 < uVar13));
                      bVar22 = uVar21 <= uVar13;
                      if (uVar13 == uVar21) {
                        bVar22 = puVar9 <= in_r3;
                      }
                      if (bVar22 && (uVar13 != uVar21 || in_r3 != puVar9)) {
                        puVar10 = FUN_022ce718();
                        iVar16 = 0;
                        (unaff_r8 + uVar18 * 4 + 0x39c)[0] = 0;
                        (unaff_r8 + uVar18 * 4 + 0x39c)[1] = 0;
                        (unaff_r8 + uVar18 * 4 + 0x39e)[0] = 0;
                        (unaff_r8 + uVar18 * 4 + 0x39e)[1] = 0;
                        if (puVar10 != (undefined4 *)0x0) {
                          *puVar10 = 0x25;
                          puVar10[1] = 1 << (uVar18 & 0xff);
                          puVar10[2] = DAT_022cf754;
                          iVar16 = func_0x037c9e90(DAT_022cf738,puVar10,0);
                        }
                        if (iVar16 == 0) {
                          puVar6 = (undefined2 *)func_0x037d14bc();
                          *puVar6 = 0x80;
                          puVar6[1] = 8;
                          puVar6[2] = 0x16;
                          puVar6[3] = 0x25;
                          func_0x037d1464();
                        }
                      }
                    }
                  }
                }
                else {
                  in_r3 = (ushort *)(uVar13 - 2 & 0xffff);
                  *puVar19 = (ushort)((uVar13 - 2) * 0x10000 >> 0x10);
                  unaff_r8[0x43] = unaff_r8[0x43] | (ushort)(1 << (uVar18 & 0xff));
                  *(uint *)(unaff_r8 + uVar18 * 4 + 0x39c) = uVar15;
                  *(int *)(unaff_r8 + uVar18 * 4 + 0x39e) = iVar5;
                  if (in_r3 != (ushort *)0x0) {
                    FUN_022d5a64(uVar1,(uint)puVar19[4],puVar19 + 5,(uint)in_r3,puVar17);
                  }
                }
              }
              puVar19 = (ushort *)((int)puVar19 + (uint)puVar17[3]);
            }
            FUN_022d5540(0,uVar20 & 0xffff);
            bVar22 = *puVar17 != 0;
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0;
            puVar6[2] = 0xb;
            *(ushort **)(puVar6 + 4) = puVar17;
            func_0x037d1464();
            unaff_r8[0x38] = unaff_r8[0x38] ^ 1;
            func_0x037cb520();
            if (!bVar22) {
              unaff_r8[0x31] = unaff_r8[0x31] - 1;
            }
            if (0 < (short)unaff_r8[0x32]) {
              unaff_r8[0x32] = unaff_r8[0x32] - 1;
            }
            uVar12 = unaff_r8[0x31];
            if (0 < (short)uVar12) {
              uVar12 = unaff_r8[0x32];
            }
            uVar15 = (uint)(0 < (short)uVar12);
            if ((short)uVar12 < 1) {
              uVar15 = 0;
            }
            func_0x037cb534();
            if (uVar15 != 0) {
              if (bVar22) {
                uVar15 = (uint)*(ushort *)((int)msg + 0x10);
              }
              if (!bVar22) {
                uVar15 = DAT_022cf758;
              }
              if (unaff_r8[0x22] == 0) {
                FUN_022cfb24(uVar15);
              }
              else {
                func_0x037cade0(DAT_022cf75c);
                in_r3 = DAT_022cf760;
                func_0x037cacfc(DAT_022cf75c,*(undefined4 *)(unaff_r8 + 0x24),
                                *(undefined4 *)(unaff_r8 + 0x26),DAT_022cf760,uVar15);
              }
            }
          }
          else {
            FUN_022cfa90();
          }
        }
      }
      else {
        iVar5 = 0;
        if (*(int *)(unaff_r8 + 6) != 0) {
          if (*(short *)((int)local_2c + 0xe) == 0) {
            iVar16 = 1;
            uVar12 = DAT_022cf764[1];
            if ((uint)*DAT_022cf764 < (uint)*DAT_022cf764) {
              uVar12 = DAT_022cf764[1];
            }
            in_r3 = (ushort *)(uint)uVar12;
            if ((int)((((int)(uint)*DAT_022cf764 >> 4 | ((uint)in_r3 & 0xf) << 0xc) -
                      (uint)unaff_r8[0x41]) * 0x10000) >> 0x10 < 1) goto switchD_022ce940_default;
          }
          else {
            iVar16 = 0;
          }
          uVar11 = func_0x037cb520();
          uVar7 = DAT_022cf748;
          if (unaff_r8[0x42] == 0) {
            func_0x037cb534();
          }
          else {
            unaff_r8[0x42] = 0;
            uVar12 = unaff_r8[0x48];
            func_0x037cade0(uVar7);
            func_0x037cb534(uVar11);
            in_r3 = (ushort *)(uint)unaff_r8[0x46];
            uVar14 = 1;
            if ((in_r3 != (ushort *)0x0) &&
               ((iVar16 != 0 ||
                (((uint)*(ushort *)((int)msg + 0x3e) & 1 << (unaff_r8[0xc4] & 0xff)) == 0)))) {
              uVar14 = 0;
            }
            if (in_r3 != (ushort *)0x0) {
              unaff_r8[0x46] = 0;
            }
            if (unaff_r8[0x47] != 0) {
              unaff_r8[0x47] = 0;
              iVar5 = FUN_022d5540(iVar16,uVar14);
            }
            if (uVar12 != 0) {
              puVar6 = (undefined2 *)func_0x037d14bc();
              *puVar6 = 0xe;
              if (iVar16 == 0) {
                if (((uint)*(ushort *)((int)msg + 0x3e) & 1 << (unaff_r8[0xc4] & 0xff)) == 0) {
                  puVar6[1] = 0;
                }
                else {
                  puVar6[1] = 0xf;
                }
              }
              else {
                puVar6[1] = 9;
              }
              puVar6[2] = 0xd;
              *(undefined4 *)(puVar6 + 4) = 0;
              if (iVar16 == 0) {
                puVar6[6] = *(undefined2 *)((int)msg + 0x1c);
                puVar6[7] = *(undefined2 *)((int)msg + 0x1e);
                func_0x037cb8b4((int)msg + 0x28,puVar6 + 8,6);
                func_0x037cb8b4((int)msg + 0x2e,puVar6 + 0xb,6);
                puVar6[0xe] = *(undefined2 *)((int)msg + 0x3a);
                puVar6[0xf] = *(undefined2 *)((int)msg + 0x3c);
                puVar6[0x10] = *(undefined2 *)((int)msg + 0x3e);
              }
              uVar15 = func_0x037d1464(puVar6);
              if (uVar12 != 0) {
                if (iVar5 != 1) {
                  uVar15 = (uint)unaff_r8[0x2f];
                }
                if (iVar5 != 1 && uVar15 != 0) {
                  unaff_r8[0x2f] = 0;
                  unaff_r8[0x30] = 1;
                  unaff_r8[0x44] = 0;
                }
                else if (unaff_r8[0x23] == 0) {
                  FUN_022cfc48();
                }
                else {
                  func_0x037cade0(DAT_022cf75c);
                  in_r3 = DAT_022cfa38;
                  func_0x037cacfc(DAT_022cf75c,*(undefined4 *)(unaff_r8 + 0x28),
                                  *(undefined4 *)(unaff_r8 + 0x2a),DAT_022cfa38,0);
                }
              }
            }
          }
        }
      }
    }
    else if ((int)uVar15 < DAT_022cf734) {
      if (uVar15 < 0x8e) {
        switch(uVar15) {
        case 0x84:
          puVar6 = (undefined2 *)func_0x037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x13;
          func_0x037d1464();
          break;
        case 0x85:
          if (in_r3 == (ushort *)0x7 || in_r3 == (ushort *)0x9) {
            func_0x037cb8b4((int)local_2c + 0x10,&local_34,6);
            uVar15 = 0;
            for (iVar5 = 0; iVar5 < 0xf; iVar5 = iVar5 + 1) {
              uVar7 = func_0x037cb520();
              uVar8 = iVar5 + 1;
              if (((uint)unaff_r8[0xc1] & 1 << (uVar8 & 0xff)) != 0) {
                iVar16 = iVar5 * 6;
                puVar17 = (ushort *)(uint)local_34;
                in_r3 = (ushort *)(uint)(byte)unaff_r8[iVar5 * 3 + 0x94];
                bVar22 = puVar17 == in_r3;
                if (bVar22) {
                  puVar17 = (ushort *)(uint)local_33;
                  in_r3 = (ushort *)(uint)*(byte *)((int)unaff_r8 + iVar16 + 0x129);
                }
                bVar23 = bVar22 && puVar17 == in_r3;
                if (bVar22 && puVar17 == in_r3) {
                  in_r3 = (ushort *)(uint)(byte)unaff_r8[iVar5 * 3 + 0x95];
                  bVar23 = (ushort *)(uint)local_32 == in_r3;
                }
                bVar22 = false;
                if (bVar23) {
                  in_r3 = (ushort *)(uint)*(byte *)((int)unaff_r8 + iVar16 + 299);
                  bVar22 = (ushort *)(uint)local_31 == in_r3;
                }
                bVar23 = false;
                if (bVar22) {
                  in_r3 = (ushort *)(uint)(byte)unaff_r8[iVar5 * 3 + 0x96];
                  bVar23 = (ushort *)(uint)local_30 == in_r3;
                }
                bVar22 = false;
                if (bVar23) {
                  in_r3 = (ushort *)(uint)local_2f;
                  bVar22 = in_r3 == (ushort *)(uint)*(byte *)((int)unaff_r8 + iVar16 + 0x12d);
                }
                if (bVar22) {
                  uVar15 = uVar8 & 0xffff;
                  uVar12 = ~(ushort)(1 << (uVar8 & 0xff));
                  unaff_r8[0xc1] = unaff_r8[0xc1] & uVar12;
                  in_r3 = unaff_r8 + uVar15 * 4;
                  unaff_r8[0x43] = unaff_r8[0x43] & uVar12;
                  in_r3[0x39c] = 0;
                  in_r3[0x39d] = 0;
                  in_r3[0x39e] = 0;
                  in_r3[0x39f] = 0;
                  func_0x037cb820(unaff_r8 + iVar5 * 3 + 0x94,0,6);
                  func_0x037cb534(uVar7);
                  break;
                }
              }
              func_0x037cb534(uVar7);
            }
            if (uVar15 != 0) {
              puVar6 = (undefined2 *)func_0x037d14bc();
              *puVar6 = 8;
              puVar6[1] = 0;
              puVar6[4] = 9;
              puVar6[9] = *(undefined2 *)((int)msg + 0x16);
              puVar6[8] = (short)uVar15;
              func_0x037cb8b4((int)msg + 0x10,puVar6 + 5,6);
              puVar6[0x16] = unaff_r8[0x18];
              puVar6[0x17] = unaff_r8[0x19];
              func_0x037d1464(puVar6);
              if (*(int *)(unaff_r8 + 6) == 1) {
                FUN_022d5870(1 << (uVar15 & 0xff) & 0xffff);
              }
            }
          }
          else {
            uVar7 = func_0x037cb520();
            if (unaff_r8[0xc1] == 0) {
              func_0x037cb534();
            }
            else {
              iVar5 = *(int *)(unaff_r8 + 6);
              if (iVar5 == 1) {
                unaff_r8[6] = 0;
                unaff_r8[7] = 0;
                FUN_022d3bd4();
                FUN_022ce658();
              }
              unaff_r8[0xc1] = 0;
              unaff_r8[0x43] = 0;
              unaff_r8[10] = 0;
              unaff_r8[0xb] = 0;
              unaff_r8[8] = 0;
              unaff_r8[9] = 0;
              unaff_r8[0xe] = 0;
              unaff_r8[0xf] = 0;
              unaff_r8[0xcc] = 0;
              unaff_r8[0xcd] = 0;
              unaff_r8[0xcb] = 0;
              func_0x037cb820(unaff_r8 + 0xce,0,0x50);
              FUN_022ce784();
              unaff_r8[0x61] = 0;
              *unaff_r8 = 3;
              func_0x037cb534(uVar7);
              puVar6 = (undefined2 *)func_0x037d14bc();
              *puVar6 = 0xc;
              puVar6[1] = 0;
              puVar6[4] = 9;
              puVar6[6] = *(undefined2 *)((int)msg + 0x16);
              puVar6[5] = unaff_r8[0xc4];
              func_0x037cb8b4(unaff_r8 + 0xc5,puVar6 + 8,6);
              puVar6[0xb] = unaff_r8[0x18];
              puVar6[0xc] = unaff_r8[0x19];
              func_0x037d1464(puVar6);
              if (iVar5 == 1) {
                FUN_022d5870(1);
              }
            }
          }
          break;
        case 0x86:
          uVar12 = *(ushort *)((int)local_2c + 0x16);
          uVar15 = (uint)uVar12;
          if ((uVar15 != 0) && (uVar15 < 0x10)) {
            if (unaff_r8[0x7b] == 0) {
              puVar10 = FUN_022ce718();
              if (puVar10 == (undefined4 *)0x0) {
                iVar5 = 0;
              }
              else {
                in_r3 = (ushort *)0x22;
                *puVar10 = 0x22;
                func_0x037cb8b4((int)msg + 0x10,puVar10 + 1,6);
                iVar5 = func_0x037c9e90(DAT_022cf738,puVar10,0);
              }
              if (iVar5 == 0) {
                puVar6 = (undefined2 *)func_0x037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 8;
                puVar6[2] = 0x16;
                puVar6[3] = 0x22;
                func_0x037d1464();
              }
            }
            else {
              uVar7 = func_0x037cb520();
              unaff_r8[0xc1] = unaff_r8[0xc1] | (ushort)(1 << (uVar15 & 0xff));
              unaff_r8[0x43] = unaff_r8[0x43] & ~(ushort)(1 << (uVar15 & 0xff));
              uVar24 = func_0x037caa3c();
              in_r3 = unaff_r8 + 0x94;
              *(uint *)(unaff_r8 + uVar15 * 4 + 0x39c) = (uint)uVar24 | 1;
              *(int *)(unaff_r8 + uVar15 * 4 + 0x39e) = (int)((ulonglong)uVar24 >> 0x20);
              func_0x037cb8b4((int)msg + 0x10,in_r3 + (uVar15 - 1) * 3);
              func_0x037cb534(uVar7);
              func_0x037cb774(1,unaff_r8 + uVar15 * 8 + 0xfc,0x10);
              puVar6 = (undefined2 *)func_0x037d14bc();
              *puVar6 = 8;
              puVar6[1] = 0;
              puVar6[4] = 7;
              func_0x037cb8b4((int)msg + 0x10,puVar6 + 5,6);
              puVar6[8] = uVar12;
              func_0x037cb78c((int)msg + 0x22,puVar6 + 10,0x18);
              puVar6[0x16] = unaff_r8[0x18];
              puVar6[0x17] = unaff_r8[0x19];
              func_0x037d1464(puVar6);
            }
          }
          break;
        case 0x87:
          puVar6 = (undefined2 *)func_0x037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x12;
          func_0x037d1464();
          break;
        case 0x88:
          puVar6 = (undefined2 *)func_0x037d14bc();
          *puVar6 = 0x80;
          puVar6[1] = 0;
          puVar6[2] = 0x11;
          func_0x037d1464();
          break;
        case 0x89:
          break;
        case 0x8a:
          break;
        case 0x8b:
          if (unaff_r8[0x61] != 0) {
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 0xc;
            puVar6[1] = 0;
            puVar6[4] = 8;
            func_0x037d1464();
          }
          break;
        case 0x8c:
          if (unaff_r8[0x61] != 0) {
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 8;
            puVar6[1] = 0;
            puVar6[4] = 2;
            func_0x037d1464();
          }
          break;
        case 0x8d:
          uVar15 = FUN_022cfa7c((uint)*(byte *)((int)local_2c + 0x1f));
          uVar15 = uVar15 ^ (uint)*DAT_022cf73c << 1;
          *DAT_022cf73c = (ushort)uVar15 ^ (ushort)(uVar15 >> 0x10);
          if (*unaff_r8 == 8 || *unaff_r8 == 10) {
            if (unaff_r8[0x5d] == *(ushort *)((int)msg + 0x44)) {
              if (*(short *)(*(int *)(DAT_022cf730 + 0x550) + 0xc2) != 0) {
                puVar6 = (undefined2 *)func_0x037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 0;
                puVar6[2] = 0x10;
                puVar6[3] = *(undefined2 *)((int)msg + 0x44);
                puVar6[4] = *unaff_r8;
                uVar12 = *(ushort *)((int)msg + 0x16);
                puVar6[5] = uVar12;
                if (uVar12 < 0x81) {
                  func_0x037cb78c((int)msg + 0x3c,puVar6 + 6,uVar12 + 1 & 0xfffffffe);
                }
                func_0x037d1464(puVar6);
              }
            }
            else {
              puVar10 = FUN_022ce718();
              if (puVar10 == (undefined4 *)0x0) {
                iVar5 = 0;
              }
              else {
                *puVar10 = 0x25;
                in_r3 = DAT_022cf740;
                puVar10[1] = 1;
                uVar7 = DAT_022cf738;
                puVar10[2] = in_r3;
                iVar5 = func_0x037c9e90(uVar7,puVar10,0);
              }
              if (iVar5 == 0) {
                puVar6 = (undefined2 *)func_0x037d14bc();
                *puVar6 = 0x80;
                puVar6[1] = 8;
                puVar6[2] = 0x16;
                puVar6[3] = 0x25;
                func_0x037d1464();
              }
            }
          }
        }
      }
      else if ((uVar15 == 0x180) && (*(int *)(unaff_r8 + 8) != 0)) {
        iVar5 = FUN_022cfa7c((uint)*(byte *)((int)local_2c + 0x1f));
        FUN_022ce538(iVar5);
        iVar5 = FUN_022ce5b4();
        unaff_r8[0x5e] = (ushort)iVar5;
        iVar5 = FUN_022ce2c4((uchar *)((int)msg + 0x2e));
        if ((iVar5 != 1) && (*(ushort *)((int)msg + 0x16) <= DAT_022cf744)) {
          unaff_r8[0x57] = unaff_r8[0x57] ^ 1;
          iVar5 = *(int *)(unaff_r8 + (uint)unaff_r8[0x57] * 2 + 0x58);
          func_0x037cb8b4((int)msg + 0x10,iVar5,*(ushort *)((int)msg + 0x16) + 0x2d & 0xfffffffe);
          func_0x037cb8b4((int)msg + 0x28,iVar5 + 0x18,6);
          func_0x037cb8b4((int)msg + 0x2e,iVar5 + 0x1e,6);
          puVar6 = (undefined2 *)func_0x037d14bc();
          *puVar6 = 0x11;
          puVar6[1] = 0;
          puVar6[2] = 0xf;
          *(int *)(puVar6 + 4) = iVar5;
          func_0x037d1464();
        }
      }
    }
    else {
      uVar15 = FUN_022cfa7c((uint)*(byte *)((int)local_2c + 0x1f));
      if (uVar15 < unaff_r8[0x5f]) {
        unaff_r8[0x5f] = (ushort)uVar15;
      }
      if (*(int *)(unaff_r8 + 6) != 0) {
        if (unaff_r8[0x30] == 1) {
          unaff_r8[0x30] = 0;
        }
        uVar12 = unaff_r8[0x47];
        unaff_r8[0x38] = unaff_r8[0x38] ^ 1;
        uVar15 = *(ushort *)((int)msg + 0x16) + 0x30;
        ctx = *(void **)(unaff_r8 + (uint)unaff_r8[0x38] * 2 + 0x3a);
        if (unaff_r8[0x39] < uVar15) {
          uVar15 = (uint)unaff_r8[0x39];
        }
        func_0x037cb8b4((int)msg + 0x10,ctx,uVar15);
        uVar7 = func_0x037cb520();
        uVar1 = unaff_r8[0x42];
        if (uVar1 == 1) {
          func_0x037cade0(DAT_022cf748);
        }
        unaff_r8[0x42] = 1;
        uVar15 = DAT_022cf74c;
        unaff_r8[0x41] = *(ushort *)((int)ctx + 10);
        uVar2 = *(ushort *)((int)msg + 0x18);
        bVar22 = (uVar2 & 0x2000) != 0;
        unaff_r8[0x48] = (ushort)bVar22;
        uVar3 = (ulonglong)uVar15 *
                (ulonglong)
                ((((uint)*(ushort *)((int)ctx + 10) - (uint)*(ushort *)((int)ctx + 0xc) & 0xffff) +
                 0x80) * 0x10);
        uVar4 = uVar3 >> 6;
        in_r3 = DAT_022cf750;
        func_0x037cacfc(DAT_022cf748,(uint)uVar4 >> 10 | (int)(uVar4 >> 0x20) << 0x16,
                        (uint)(uVar3 >> 0x30),DAT_022cf750,0);
        bVar23 = (uVar2 & 0x2800) == 0x2800;
        iVar5 = extraout_r1;
        if (bVar23) {
          iVar5 = 1;
        }
        if (!bVar23) {
          iVar5 = 0;
        }
        bVar23 = (uVar2 & 0x6000) == 0x6000;
        if (bVar23) {
          unaff_r8[0x45] = 0;
        }
        unaff_r8[0x47] = (ushort)(iVar5 != 0);
        unaff_r8[0x46] = (ushort)bVar23;
        if ((bVar22) &&
           (iVar5 = *(ushort *)((int)ctx + 0x2c) - 0x66,
           uVar15 = ((int)(iVar5 + ((uint)(iVar5 >> 1) >> 0x1e)) >> 2) - 0x20, -1 < (int)uVar15)) {
          if (0x200 < (int)uVar15) {
            uVar15 = 0x200;
          }
          if (uVar15 != unaff_r8[0x19]) {
            FUN_022ce884(uVar15 & 0xffff);
          }
        }
        func_0x037cb534(uVar7);
        if (uVar1 == 1) {
          if (uVar12 == 1) {
            FUN_022d5540(1,0);
          }
          puVar6 = (undefined2 *)func_0x037d14bc();
          *puVar6 = 0xe;
          puVar6[1] = 9;
          puVar6[2] = 0xd;
          *(undefined4 *)(puVar6 + 4) = 0;
          func_0x037d1464();
        }
        if (bVar22) {
          func_0x037cb8b4((int)msg + 0x28,(int)ctx + 0x18,6);
          func_0x037cb8b4((int)msg + 0x2e,(int)ctx + 0x1e,6);
          if (*(ushort *)((int)ctx + 6) < 2) {
            *(undefined2 *)((int)ctx + 6) = 0;
            unaff_r8[0x2f] = 0;
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0xe;
            puVar6[2] = 0xc;
            *(void **)(puVar6 + 4) = ctx;
            func_0x037d1464();
          }
          else {
            *(ushort *)((int)ctx + 6) = *(ushort *)((int)ctx + 6) - 2;
            unaff_r8[0x2f] = (ushort)((*(ushort *)((int)ctx + 0x30) & 0x8000) != 0);
            puVar6 = (undefined2 *)func_0x037d14bc();
            *puVar6 = 0xe;
            puVar6[1] = 0;
            puVar6[2] = 0xc;
            *(void **)(puVar6 + 4) = ctx;
            func_0x037d1464();
            in_r3 = (ushort *)(uint)*(ushort *)((int)ctx + 6);
            if (in_r3 != (ushort *)0x0) {
              FUN_022d5a64(0,(uint)*(ushort *)((int)ctx + 0x30),(ushort *)((int)ctx + 0x32),
                           (uint)in_r3,ctx);
            }
          }
          if (*(int *)(unaff_r8 + 0x3de) != 0 || *(int *)(unaff_r8 + 0x3dc) != 0) {
            uVar24 = func_0x037caa3c();
            *(uint *)(unaff_r8 + 0x39c) = (uint)uVar24 | 1;
            *(int *)(unaff_r8 + 0x39e) = (int)((ulonglong)uVar24 >> 0x20);
          }
        }
        else if (1 < *(ushort *)((int)ctx + 6)) {
          unaff_r8[0x2f] = (ushort)((*(ushort *)((int)ctx + 0x30) & 0x8000) != 0);
        }
      }
    }
switchD_022ce940_default:
    FUN_022cfa44(msg);
  } while( true );
}

