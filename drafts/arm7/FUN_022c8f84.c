// decomp: module=arm7 addr=0x022c8f84 name=FUN_022c8f84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7e0 (Ghidra's cache says 0x774 - it excludes this function's trailing literal pool), thumb
// triage: noise=42 statements=463
// verify:  python tools/match.py --c <file> --func FUN_022c8f84 --addr 0x022c8f84 --size 0x7e0 --module arm7 --version 2.0/sp1


bool FUN_022c8f84(int param_1,int param_2)

{
  bool bVar1;
  byte bVar2;
  undefined2 uVar3;
  short sVar4;
  byte *p;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  byte *o;
  undefined4 uVar11;
  short *psVar12;
  undefined4 *p_00;
  int iVar13;
  bool bVar14;
  bool bVar15;
  undefined4 local_68;
  uint local_64;
  int local_58;
  undefined1 local_22 [14];
  
  bVar1 = false;
  local_58 = 0;
LAB_022c8f92:
  p = (byte *)FUN_022c8dec(param_1,local_58);
  if ((p != (byte *)0x0) && (*(int *)(p + 0x28) != 0)) {
    for (iVar5 = *(int *)(p + 0x3c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x50)) {
      if (0 < *(int *)(iVar5 + 0x34)) {
        *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + -1;
      }
      if ((-1 < (int)((uint)*(byte *)(iVar5 + 3) << 0x1d)) &&
         (*(int *)(iVar5 + 0x14) < *(int *)(iVar5 + 0x18))) {
        *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + 1;
      }
    }
    if ((int)((uint)*p << 0x1b) < 0) {
      if (*(int *)(p + 0x3c) == 0) {
        *p = *p & 0xef;
        goto LAB_022c8fe6;
      }
      iVar5 = 0;
    }
    else {
LAB_022c8fe6:
      if ((*(int *)(p + 0x20) < 1) ||
         (iVar5 = *(int *)(p + 0x20) + -1, *(int *)(p + 0x20) = iVar5, iVar5 < 1)) {
        FUN_022c8bf0(*(undefined4 *)(p + 0x28));
        pbVar6 = p + 0x3b;
switchD_022c9536_caseD_b7:
        do {
          while( true ) {
            if ((*(int *)(p + 0x20) != 0) || ((int)((uint)*p << 0x1b) < 0)) {
              iVar5 = 0;
              goto LAB_022c972e;
            }
            local_64 = 1;
            uVar7 = FUN_022c88bc(p);
            if (uVar7 == 0xa2) {
              uVar7 = FUN_022c88bc(p);
              local_64 = (*p & 0x7f) >> 6;
            }
            bVar14 = uVar7 != 0xa0;
            if (!bVar14) {
              uVar7 = FUN_022c88bc(p);
              local_68 = 3;
            }
            bVar15 = uVar7 != 0xa1;
            if (!bVar15) {
              uVar7 = FUN_022c88bc(p);
              local_68 = 4;
            }
            if ((uVar7 & 0x80) != 0) break;
            uVar11 = FUN_022c88bc(p);
            uVar10 = local_68;
            if (bVar15 && bVar14) {
              uVar10 = 2;
            }
            iVar5 = FUN_022c8c38(p,param_1,uVar10);
            iVar13 = uVar7 + (int)(char)p[0x13];
            if (local_64 != 0) {
              if (iVar13 < 0) {
                iVar13 = 0;
              }
              else if (0x7f < iVar13) {
                iVar13 = 0x7f;
              }
              if (((int)((uint)*p << 0x1d) < 0) || (param_2 == 0)) goto switchD_022c90fa_caseD_0;
              p_00 = (undefined4 *)0x0;
              if (((int)((uint)*p << 0x1c) < 0) &&
                 (p_00 = *(undefined4 **)(p + 0x3c), p_00 != (undefined4 *)0x0)) {
                *(byte *)(p_00 + 2) = (byte)iVar13;
                *(char *)((int)p_00 + 9) = (char)uVar11;
              }
              if (p_00 == (undefined4 *)0x0) {
                iVar8 = FUN_022c9828(*(undefined4 *)(param_1 + 0x20),*(undefined2 *)(p + 2),iVar13,
                                     local_22);
                if (iVar8 != 0) {
                  switch(local_22[0]) {
                  default:
                    goto switchD_022c90fa_caseD_0;
                  case 1:
                  case 4:
                    uVar7 = DAT_022c93cc;
                    break;
                  case 2:
                    uVar7 = 0x3f00;
                    break;
                  case 3:
                    uVar7 = 0xc000;
                  }
                  p_00 = (undefined4 *)
                         FUN_022c8290(*(ushort *)(p + 0x1e) & uVar7,
                                      (uint)*(byte *)(param_1 + 4) + (uint)p[0x12],*p >> 7,
                                      DAT_022c93d0,p);
                  if (p_00 != (undefined4 *)0x0) {
                    if ((int)((uint)*p << 0x1c) < 0) {
                      iVar8 = -1;
                    }
                    else {
                      iVar8 = iVar5;
                      if (iVar5 < 1) {
                        iVar8 = -1;
                      }
                    }
                    iVar8 = FUN_022c9948(p_00,iVar13,uVar11,iVar8,*(undefined4 *)(param_1 + 0x20),
                                         local_22);
                    if (iVar8 != 0) {
                      p_00[0x14] = *(undefined4 *)(p + 0x3c);
                      *(undefined4 **)(p + 0x3c) = p_00;
                      goto LAB_022c917c;
                    }
                    *(undefined1 *)((int)p_00 + 0x22) = 0;
                    FUN_022c83d0(p_00);
                  }
                }
              }
              else {
LAB_022c917c:
                if (p[0xe] != 0xff) {
                  FUN_022c8238(p_00);
                }
                if (p[0xf] != 0xff) {
                  FUN_022c8254(p_00);
                }
                if (p[0x10] != 0xff) {
                  FUN_022c8268((int)p_00,p[0x10]);
                }
                if (p[0x11] != 0xff) {
                  FUN_022c826c(p_00);
                }
                *(undefined2 *)((int)p_00 + 0x32) = *(undefined2 *)(p + 0x16);
                if ((int)((uint)*p << 0x1a) < 0) {
                  *(short *)((int)p_00 + 0x32) =
                       *(short *)((int)p_00 + 0x32) +
                       (short)(((uint)p[0x14] - iVar13) * 0x400000 >> 0x10);
                }
                uVar7 = (uint)p[0x15];
                if (uVar7 == 0) {
                  iVar8 = iVar5;
                  if (iVar5 < 1) {
                    iVar8 = -1;
                  }
                  p_00[6] = iVar8;
                  *(byte *)((int)p_00 + 3) = *(byte *)((int)p_00 + 3) & 0xfb;
                }
                else {
                  iVar8 = (int)*(short *)((int)p_00 + 0x32);
                  if (iVar8 < 0) {
                    iVar8 = -iVar8;
                  }
                  p_00[6] = (int)(uVar7 * uVar7 * iVar8) >> 0xb;
                }
                p_00[5] = 0;
              }
switchD_022c90fa_caseD_0:
              p[0x14] = (byte)iVar13;
              if (((int)((uint)*p << 0x1e) < 0) && (*(int *)(p + 0x20) = iVar5, iVar5 == 0)) {
                *p = *p | 0x10;
              }
            }
          }
          uVar9 = uVar7 & 0xf0;
          if (uVar9 < 0xc1) {
            if (uVar9 < 0xc0) {
              if (uVar9 < 0x91) {
                if (uVar9 < 0x90) {
                  if (uVar9 == 0x80) {
                    uVar10 = local_68;
                    if (bVar15 && bVar14) {
                      uVar10 = 2;
                    }
                    iVar5 = FUN_022c8c38(p,param_1,uVar10);
                    if (local_64 != 0) {
                      if (uVar7 == 0x80) {
                        *(int *)(p + 0x20) = iVar5;
                      }
                      else if ((uVar7 == 0x81) && (iVar5 < 0x10000)) {
                        *(short *)(p + 2) = (short)iVar5;
                      }
                    }
                  }
                }
                else if (uVar7 == 0x93) {
                  uVar10 = FUN_022c88bc(p);
                  iVar5 = FUN_022c8c14(p);
                  if (((local_64 != 0) &&
                      (o = (byte *)FUN_022c8dec(param_1,uVar10), o != (byte *)0x0)) && (o != p)) {
                    FUN_022c8d88(o,param_1,0xffffffff);
                    FUN_022c8dcc(o);
                    FUN_022c8d80((undefined4 *)o,*(int *)(p + 0x24),iVar5);
                  }
                }
                else if (uVar7 == 0x94) {
                  iVar5 = FUN_022c8c14(p);
                  if (local_64 != 0) {
                    *(int *)(p + 0x28) = *(int *)(p + 0x24) + iVar5;
                  }
                }
                else if (((uVar7 == 0x95) && (iVar5 = FUN_022c8c14(p), local_64 != 0)) &&
                        (p[0x3b] < 3)) {
                  *(undefined4 *)(p + (uint)p[0x3b] * 4 + 0x2c) = *(undefined4 *)(p + 0x28);
                  *pbVar6 = *pbVar6 + 1;
                  *(int *)(p + 0x28) = *(int *)(p + 0x24) + iVar5;
                }
              }
              else if (uVar9 == 0xb0) {
                uVar11 = FUN_022c88bc(p);
                uVar10 = local_68;
                if (bVar15 && bVar14) {
                  uVar10 = 1;
                }
                sVar4 = FUN_022c8c38(p,param_1,uVar10);
                uVar9 = (uint)sVar4;
                psVar12 = (short *)FUN_022c9764(param_1,uVar11);
                if ((local_64 != 0) && (psVar12 != (short *)0x0)) {
                  switch(uVar7) {
                  case 0xb0:
                    *psVar12 = sVar4;
                    break;
                  case 0xb1:
                    *psVar12 = *psVar12 + sVar4;
                    break;
                  case 0xb2:
                    *psVar12 = *psVar12 - sVar4;
                    break;
                  case 0xb3:
                    *psVar12 = sVar4 * *psVar12;
                    break;
                  case 0xb4:
                    if (uVar9 != 0) {
                      sVar4 = thunk_EXT_FUN_037fbaa4((int)*psVar12,uVar9);
                      *psVar12 = sVar4;
                    }
                    break;
                  case 0xb5:
                    if ((int)uVar9 < 0) {
                      *psVar12 = (short)((int)*psVar12 >> (-uVar9 & 0xff));
                    }
                    else {
                      *psVar12 = (short)((int)*psVar12 << (uVar9 & 0xff));
                    }
                    break;
                  case 0xb6:
                    bVar14 = (int)uVar9 < 0;
                    if (bVar14) {
                      uVar9 = (int)(uVar9 * -0x10000) >> 0x10;
                    }
                    iVar5 = FUN_022c7af4();
                    sVar4 = (short)(iVar5 * (uVar9 + 1) >> 0x10);
                    if (bVar14) {
                      sVar4 = -sVar4;
                    }
                    *psVar12 = sVar4;
                    break;
                  case 0xb8:
                    *p = *p & 0xbf | ((int)*psVar12 == uVar9) << 6;
                    break;
                  case 0xb9:
                    *p = *p & 0xbf | ((int)uVar9 <= (int)*psVar12) << 6;
                    break;
                  case 0xba:
                    *p = *p & 0xbf | ((int)uVar9 < (int)*psVar12) << 6;
                    break;
                  case 0xbb:
                    *p = *p & 0xbf | ((int)*psVar12 <= (int)uVar9) << 6;
                    break;
                  case 0xbc:
                    *p = *p & 0xbf | ((int)*psVar12 < (int)uVar9) << 6;
                    break;
                  case 0xbd:
                    *p = *p & 0xbf | ((int)*psVar12 != uVar9) << 6;
                  }
                }
              }
            }
            else {
LAB_022c9314:
              uVar10 = local_68;
              if (bVar15 && bVar14) {
                uVar10 = 0;
              }
              bVar2 = FUN_022c8c38(p,param_1,uVar10);
              if (local_64 != 0) {
                switch(uVar7) {
                case 0xc0:
                  p[8] = bVar2 - 0x40;
                  break;
                case 0xc1:
                  p[4] = bVar2;
                  break;
                case 0xc2:
                  *(byte *)(param_1 + 5) = bVar2;
                  break;
                case 0xc3:
                  p[0x13] = bVar2;
                  break;
                case 0xc4:
                  p[6] = bVar2;
                  break;
                case 0xc5:
                  p[7] = bVar2;
                  break;
                case 0xc6:
                  p[0x12] = bVar2;
                  break;
                case 199:
                  *p = *p & 0xfd | (bVar2 & 1) << 1;
                  break;
                case 200:
                  *p = *p & 0xf7 | (bVar2 & 1) << 3;
                  FUN_022c8d88(p,param_1,0xffffffff);
                  FUN_022c8dcc(p);
                  break;
                case 0xc9:
                  p[0x14] = bVar2 + p[0x13];
                  *p = *p | 0x20;
                  break;
                case 0xca:
                  p[0x1a] = bVar2;
                  break;
                case 0xcb:
                  p[0x19] = bVar2;
                  break;
                case 0xcc:
                  p[0x18] = bVar2;
                  break;
                case 0xcd:
                  p[0x1b] = bVar2;
                  break;
                case 0xce:
                  *p = *p & 0xdf | (bVar2 & 1) << 5;
                  break;
                case 0xcf:
                  p[0x15] = bVar2;
                  break;
                case 0xd0:
                  p[0xe] = bVar2;
                  break;
                case 0xd1:
                  p[0xf] = bVar2;
                  break;
                case 0xd2:
                  p[0x10] = bVar2;
                  break;
                case 0xd3:
                  p[0x11] = bVar2;
                  break;
                case 0xd4:
                  if (p[0x3b] < 3) {
                    *(undefined4 *)(p + (uint)p[0x3b] * 4 + 0x2c) = *(undefined4 *)(p + 0x28);
                    p[p[0x3b] + 0x38] = bVar2;
                    *pbVar6 = *pbVar6 + 1;
                  }
                  break;
                case 0xd5:
                  p[5] = bVar2;
                  break;
                case 0xd6:
                  if (*DAT_022c9760 != 0) {
                    FUN_022c9764(param_1,bVar2);
                  }
                  break;
                case 0xd7:
                  FUN_022c97cc(p,param_1,bVar2);
                }
              }
            }
            goto switchD_022c9536_caseD_b7;
          }
          if (uVar9 < 0xe1) {
            if (uVar9 < 0xe0) {
              if (uVar9 == 0xd0) goto LAB_022c9314;
            }
            else {
              uVar10 = local_68;
              if (bVar15 && bVar14) {
                uVar10 = 1;
              }
              uVar3 = FUN_022c8c38(p,param_1,uVar10);
              if (local_64 != 0) {
                if (uVar7 == 0xe0) {
                  *(undefined2 *)(p + 0x1c) = uVar3;
                }
                else if (uVar7 == 0xe1) {
                  *(undefined2 *)(param_1 + 0x18) = uVar3;
                }
                else if (uVar7 == 0xe3) {
                  *(undefined2 *)(p + 0x16) = uVar3;
                }
              }
            }
            goto switchD_022c9536_caseD_b7;
          }
          if ((uVar9 != 0xf0) || (local_64 == 0)) goto switchD_022c9536_caseD_b7;
          switch(uVar7) {
          case 0xfc:
            uVar7 = (uint)p[0x3b];
            if (uVar7 != 0) {
              bVar2 = p[uVar7 + 0x37];
              if ((bVar2 == 0) || (bVar2 = bVar2 - 1, bVar2 != 0)) {
                p[uVar7 + 0x37] = bVar2;
                *(undefined4 *)(p + 0x28) = *(undefined4 *)(p + (uint)p[0x3b] * 4 + 0x28);
              }
              else {
                *pbVar6 = *pbVar6 - 1;
              }
            }
            break;
          case 0xfd:
            if (p[0x3b] != 0) {
              *pbVar6 = *pbVar6 - 1;
              *(undefined4 *)(p + 0x28) = *(undefined4 *)(p + (uint)p[0x3b] * 4 + 0x2c);
            }
            break;
          case 0xff:
            goto switchD_022c96aa_caseD_ff;
          }
        } while( true );
      }
      iVar5 = 0;
    }
    goto LAB_022c972e;
  }
  goto LAB_022c9740;
switchD_022c96aa_caseD_ff:
  iVar5 = -1;
LAB_022c972e:
  if (iVar5 == 0) {
    bVar1 = true;
  }
  else {
    FUN_022c8e0c(param_1,local_58);
  }
LAB_022c9740:
  local_58 = local_58 + 1;
  if (0xf < local_58) {
    return !bVar1;
  }
  goto LAB_022c8f92;
}

