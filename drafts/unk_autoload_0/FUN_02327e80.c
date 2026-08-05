// decomp: module=unk_autoload_0 addr=0x02327e80 name=FUN_02327e80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe60 (Ghidra's cache says 0xd3c - it excludes this function's trailing literal pool), thumb
// triage: noise=99 statements=714
// verify:  python tools/match.py --c <file> --func FUN_02327e80 --addr 0x02327e80 --size 0xe60 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327e80(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined *a;
  undefined *puVar5;
  undefined2 uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int extraout_r1;
  int extraout_r1_00;
  short *psVar16;
  undefined4 *puVar17;
  short *psVar18;
  undefined4 local_2ac;
  ushort local_298;
  ushort local_296;
  ushort local_294;
  ushort local_292;
  undefined2 local_290;
  undefined2 local_28e;
  short sStack_28c;
  short sStack_28a;
  short sStack_288;
  short sStack_286;
  short sStack_284;
  short sStack_282;
  short sStack_280;
  short sStack_27e;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 auStack_270 [3];
  short local_264 [13];
  undefined1 auStack_24a [28];
  undefined1 auStack_22e [26];
  undefined2 local_214;
  undefined1 auStack_212 [514];
  
  a = PTR_DAT_023281d0;
  if (*(int *)(PTR_DAT_023281cc + 0x10) != 2) {
    uVar6 = local_2ac._2_2_;
    switch(*(int *)(PTR_DAT_023281cc + 0x10)) {
    case 4:
      FUN_02320978(0x28);
      FUN_02328da8(*(undefined4 *)(PTR_DAT_023281cc + 0x2c));
      uVar7 = local_298 & (ushort)DAT_023281d4;
      uVar1 = local_296 & (ushort)DAT_023281d4 | uVar7 & 0xc000;
      uVar2 = (ushort)(DAT_023281d4 >> 2);
      uVar7 = uVar2 & uVar7;
      uVar3 = (uVar1 >> 0xe) << 0xc;
      FUN_0233746c(0,*(undefined4 *)(a + 0x38),*(undefined4 *)(a + 0x44));
      local_214 = 0;
      FUN_0233746c(0,local_264,0x1b);
      psVar18 = local_264;
      psVar16 = *(short **)(PTR_DAT_023281cc + 0x28);
      FUN_0233746c(0,psVar18,0x36);
      iVar8 = *(int *)(PTR_DAT_023281cc + 0x28);
      for (; (*psVar16 != 0 && (psVar16 < (short *)(iVar8 + 0x34))); psVar16 = psVar16 + 1) {
        *psVar18 = *psVar16;
        psVar18 = psVar18 + 1;
      }
      uVar1 = (uVar2 & uVar1 | uVar7 & 0x3000 | uVar3) & (ushort)DAT_023281d8;
      uVar3 = (ushort)DAT_023281d8 & (uVar7 | uVar3);
      uVar7 = uVar3 | 0x12;
      FUN_02334628(auStack_22e,local_264,0xd);
      piVar12 = FUN_02321c60();
      local_2ac = CONCAT22(local_2ac._2_2_,uVar1) | 0x1a;
      uVar10 = local_2ac;
      local_2ac = CONCAT22(uVar6,uVar3) | 0x12;
      FUN_0232dd40(piVar12,PTR_DAT_023281dc,uVar10,local_2ac,1,3,auStack_22e,1);
      uVar3 = (ushort)DAT_023281d8;
      uVar10 = (uint)DAT_023281d8 >> 0x14;
      FUN_02334628(auStack_22e,auStack_24a,0xd);
      piVar12 = FUN_02321c60();
      local_2ac = CONCAT22(uVar6,uVar1) | 0x1a;
      uVar11 = local_2ac;
      local_2ac = CONCAT22(uVar6,uVar7 & uVar3 |
                                 (ushort)uVar10 &
                                 (ushort)((uint)(((((int)(short)uVar7 << 0x14) >> 0x14) + 0x10) *
                                                0x10000) >> 0x10));
      FUN_0232dd40(piVar12,PTR_DAT_023281dc,uVar11,local_2ac,1,3,auStack_22e,1);
      FUN_023216e0(PTR_DAT_023281e0,*(undefined4 *)(PTR_DAT_023281cc + 0x24));
      *(undefined4 *)(PTR_DAT_023281cc + 0x20) = 0xffffffff;
      FUN_02328d08(1);
      *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 5;
      break;
    case 6:
      FUN_02320978(0x28);
      FUN_02322870();
      FUN_02328da8();
      uVar14 = FUN_02322820();
      FUN_023216e0(PTR_DAT_023281e0,uVar14);
      FUN_0233746c(0,*(undefined4 *)(a + 0x38),*(undefined4 *)(a + 0x44));
      *(undefined4 *)(PTR_DAT_023281cc + 0x20) = 0xffffffff;
      FUN_02328d60(0x1f,1);
      FUN_02328d80(0x1f,1);
      *DAT_023281e4 = 0;
      FUN_023260a4();
      *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 7;
      break;
    case 7:
      iVar8 = FUN_023260b0();
      if (iVar8 != 0) {
        *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 0;
      }
      break;
    case 8:
      uVar7 = local_294 & (ushort)DAT_023281d4;
      uVar1 = local_292 & (ushort)DAT_023281d4 | uVar7 & 0xc000;
      uVar2 = (ushort)(DAT_023281d4 >> 2);
      uVar7 = uVar2 & uVar7;
      uVar3 = (uVar1 >> 0xe) << 0xc;
      FUN_0233746c(0,*(undefined4 *)(PTR_DAT_023281d0 + 0x38),
                   *(undefined4 *)(PTR_DAT_023281d0 + 0x44));
      uVar4 = (ushort)DAT_023281d8;
      iVar8 = FUN_0232996c();
      if (iVar8 == 0xc) {
        iVar8 = FUN_02321d04(0x33);
        FUN_02334610(auStack_212,iVar8);
      }
      else if (iVar8 == 0xd) {
        piVar12 = FUN_023260bc();
        FUN_02329650((int)auStack_212,*piVar12);
      }
      else if (iVar8 == 0xe) {
        iVar8 = FUN_02321d04(0x35);
        FUN_02334610(auStack_212,iVar8);
      }
      else {
        iVar8 = FUN_02321d04(0x33);
        FUN_02334610(auStack_212,iVar8);
      }
      piVar12 = FUN_02321c60();
      local_2ac = CONCAT22(local_2ac._2_2_,(uVar2 & uVar1 | uVar7 & 0x3000 | uVar3) & uVar4) | 0x1a;
      uVar10 = local_2ac;
      local_2ac = CONCAT22(uVar6,uVar4 & (uVar7 | uVar3)) | 2;
      FUN_0232dd40(piVar12,PTR_DAT_023281dc,uVar10,local_2ac,1,4,auStack_212,1);
      *(undefined4 *)(PTR_DAT_023281cc + 0x20) = 0xffffffff;
      FUN_02320978(0x23);
      FUN_02328d08(1);
      *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 9;
      break;
    case 10:
      *(undefined4 *)(PTR_DAT_023281cc + 0x20) = 0xffffffff;
      FUN_0233746c(0,*(undefined4 *)(a + 0x38),*(undefined4 *)(a + 0x44));
      FUN_02328d60(0x1f,1);
      FUN_02328d80(0x1f,1);
      *DAT_023281e4 = 0;
      *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 1;
    }
  }
  iVar8 = FUN_023260c4();
  if (((iVar8 != 0) && (*(int *)(PTR_DAT_023281cc + 0x10) == 0)) &&
     (iVar8 = FUN_02329124(), iVar8 != 0)) {
    *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 8;
  }
  switch(*(undefined4 *)(PTR_DAT_023281cc + 0x10)) {
  case 0:
    FUN_02325ce0(a);
    uVar14 = FUN_023212f8();
    uVar15 = FUN_02321304();
    iVar8 = FUN_0232e004(PTR_DAT_02328520,uVar14,uVar15);
    iVar13 = FUN_023212ec();
    if (iVar13 == 1) {
      switch(iVar8) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
        *(int *)(PTR_DAT_02328524 + 0x20) = iVar8;
        break;
      case 0xf:
        iVar13 = FUN_023279a4(*(undefined2 *)(PTR_DAT_02328528 + 0xc),2);
        iVar9 = FUN_023212f8();
        if (iVar9 <= iVar13 + 0x4e) {
          *(int *)(PTR_DAT_02328524 + 0x20) = iVar8;
        }
      }
      switch(iVar8) {
      case 3:
        FUN_02327c9c();
        break;
      case 4:
        FUN_02327d24();
        break;
      case 5:
        if ((*(ushort *)(a + 0x48) & 0xff) >> 4 == 2) {
          uVar10 = (byte)a[0x570] + 1;
          if (uVar10 < 2) {
            FUN_023253ec(a);
            thunk_FUN_02328e04();
          }
          else {
            uVar10 = 0;
          }
          a[0x570] = (char)uVar10;
        }
        *(ushort *)(a + 0x48) = *(ushort *)(a + 0x48) & 0xff0f | 0x20;
        FUN_02320978(0x10);
        break;
      case 6:
        *(ushort *)(a + 0x48) = *(ushort *)(a + 0x48) & 0xff0f | 0x30;
        FUN_02320978(0x11);
        break;
      case 7:
        *(ushort *)(a + 0x48) = *(ushort *)(a + 0x48) & 0xfff0 | 1;
        FUN_02320978(0x13);
        break;
      case 8:
        *(ushort *)(a + 0x48) = *(ushort *)(a + 0x48) & 0xfff0;
        FUN_02320978(0x12);
        break;
      case 0x12:
        FUN_023212f8();
        iVar8 = FUN_023277ec();
        puVar5 = PTR_DAT_02328524;
        if (iVar8 != 0) {
          *(int *)(PTR_DAT_02328524 + 0x24) = iVar8;
          *(int *)(puVar5 + 0x28) = iVar8 + 0x16;
          *(uint *)(puVar5 + 0x2c) = (uint)*(ushort *)(iVar8 + 0x4c);
          *(undefined4 *)(puVar5 + 0x10) = 4;
        }
      }
    }
    else {
      iVar13 = FUN_023251cc(PTR_DAT_0232852c);
      if ((iVar13 == 0) || (iVar8 != *(int *)(PTR_DAT_02328524 + 0x20))) {
        iVar13 = FUN_023212e0();
        if ((iVar13 == 0) || (iVar8 == *(int *)(PTR_DAT_02328524 + 0x20))) {
          iVar13 = FUN_023212e0();
          if ((iVar13 == 0) || (iVar8 != *(int *)(PTR_DAT_02328524 + 0x20))) {
            iVar13 = FUN_023212ec();
            if ((iVar13 == 3) && (iVar8 == *(int *)(PTR_DAT_02328524 + 0x20))) {
              switch(iVar8) {
              case 0:
                FUN_02327bfc(a);
                break;
              case 1:
                FUN_02327c54((int *)a);
                break;
              case 2:
                FUN_02327c70(a);
                break;
              case 9:
                FUN_02323798(0);
                break;
              case 10:
                FUN_02323798(1);
                break;
              case 0xb:
                FUN_02323798(2);
                break;
              case 0xc:
                FUN_02323798(3);
                break;
              case 0xd:
                FUN_02323798(4);
                break;
              case 0xe:
                *(undefined4 *)(PTR_DAT_02328524 + 0x10) = 1;
                break;
              case 0xf:
                uVar14 = FUN_02322820();
                *(undefined4 *)(PTR_DAT_02328524 + 0x24) = uVar14;
                uVar14 = FUN_02322844();
                *(undefined4 *)(PTR_DAT_02328524 + 0x28) = uVar14;
                uVar14 = FUN_02322870();
                puVar5 = PTR_DAT_02328524;
                *(undefined4 *)(PTR_DAT_02328524 + 0x2c) = uVar14;
                *(undefined4 *)(puVar5 + 0x10) = 4;
              }
            }
          }
          else {
            FUN_0232519c(PTR_DAT_0232852c);
          }
        }
        else {
          FUN_023251c4(PTR_DAT_0232852c);
        }
      }
      else {
        if (iVar8 == 3) {
          FUN_02327c9c();
        }
        else if (iVar8 == 4) {
          FUN_02327d24();
        }
        FUN_0232519c(PTR_DAT_0232852c);
      }
    }
    iVar8 = FUN_023212ec();
    if (iVar8 == 3) {
      *(undefined4 *)(PTR_DAT_02328524 + 0x20) = 0xffffffff;
      FUN_023251c4(PTR_DAT_0232852c);
    }
    uVar10 = FUN_02325278();
    uVar7 = FUN_023212c8(0x300);
    if ((uVar10 & 1) == 0) {
      uVar11 = FUN_02325250();
      if (((((uVar11 & 2) == 0) && (iVar8 = FUN_023212bc(2), iVar8 != 0)) &&
          (*(short *)(a + DAT_02328530) == 0)) &&
         ((*(short *)(a + DAT_02328534) == 0 && (iVar8 = FUN_023212e0(), iVar8 == 0)))) {
        FUN_023234c0();
        FUN_023221b0();
        piVar12 = FUN_023260bc();
        FUN_0232965c((int)PTR_DAT_02328538,*piVar12);
        FUN_02321fbc(0x39,2,(int)PTR_DAT_02328538);
        FUN_02336880(PTR_DAT_0232853c,0x60,0x20);
        FUN_02336880(DAT_02328544 + (*DAT_02328540 & 0xf) * 0x20,0x1e0,0x20);
        *(undefined4 *)(PTR_DAT_02328810 + 0x10) = 2;
        FUN_02320978(0x1a);
      }
      else {
        puVar5 = PTR_DAT_02328810;
        if ((uVar10 & 0x400) == 0) {
          if ((uVar10 & 0x800) == 0) {
            if (uVar7 == 0) {
              if ((uVar10 & 8) == 0) {
                *(undefined4 *)PTR_DAT_02328810 = 0;
                *(undefined4 *)(puVar5 + 8) = 0;
              }
              else {
                FUN_02327bfc(PTR_DAT_02328814);
              }
            }
            else {
              iVar8 = *(int *)PTR_DAT_02328810;
              if (iVar8 == 0) {
                if (((uVar7 & 0x200) == 0) || ((uVar7 & 0x100) != 0)) {
                  if (((uVar7 & 0x100) != 0) && ((uVar7 & 0x200) == 0)) {
                    *(undefined4 *)PTR_DAT_02328810 = 2;
                  }
                }
                else {
                  *(undefined4 *)PTR_DAT_02328810 = 1;
                }
              }
              else if ((iVar8 == 1) || (iVar8 == 3)) {
                if ((uVar7 & 0x100) != 0) {
                  *(undefined4 *)PTR_DAT_02328810 = 3;
                  FUN_02335e0c(*(int *)(puVar5 + 8) + 1,10);
                  *(int *)(PTR_DAT_02328810 + 8) = extraout_r1;
                  if (extraout_r1 == 0) {
                    FUN_02327d68();
                  }
                }
                if ((uVar7 & 0x200) == 0) {
                  *(undefined4 *)PTR_DAT_02328810 = 0;
                }
              }
              else if ((iVar8 == 2) || (iVar8 == 4)) {
                if ((uVar7 & 0x200) != 0) {
                  *(undefined4 *)PTR_DAT_02328810 = 4;
                  FUN_02335e0c(*(int *)(puVar5 + 8) + 1,10);
                  *(int *)(PTR_DAT_02328810 + 8) = extraout_r1_00;
                  if (extraout_r1_00 == 0) {
                    FUN_02327ce0();
                  }
                }
                if ((uVar7 & 0x100) == 0) {
                  *(undefined4 *)PTR_DAT_02328810 = 0;
                }
              }
              if (*(uint *)PTR_DAT_02328810 < 3) {
                if ((uVar10 & 0x200) == 0) {
                  if ((uVar10 & 0x100) != 0) {
                    FUN_02327c9c();
                  }
                }
                else {
                  FUN_02327d24();
                }
              }
            }
          }
          else {
            FUN_023237e4();
          }
        }
        else {
          iVar8 = FUN_02323834();
          if (iVar8 == 1) {
            FUN_02325804(PTR_DAT_02328814);
          }
        }
      }
    }
    else {
      FUN_02323f74();
    }
    iVar8 = FUN_023212bc(4);
    if (iVar8 == 0) {
      iVar8 = FUN_023212c8(4);
      if (iVar8 == 0) {
        iVar8 = FUN_023212d4(4);
        if ((iVar8 != 0) && (*(int *)(PTR_DAT_02328810 + 4) < 0x1e)) {
          FUN_02327c54((int *)PTR_DAT_02328814);
        }
      }
      else if ((*(int *)(PTR_DAT_02328810 + 4) < 0x1e) &&
              (iVar8 = *(int *)(PTR_DAT_02328810 + 4) + 1, *(int *)(PTR_DAT_02328810 + 4) = iVar8,
              iVar8 == 0x1e)) {
        FUN_02327c70(PTR_DAT_02328814);
      }
    }
    else {
      *(undefined4 *)(PTR_DAT_02328810 + 4) = 0;
    }
    if (*(int *)(PTR_DAT_02328810 + 0x10) != 2) {
      FUN_02323840();
    }
    iVar8 = FUN_02323c84();
    FUN_02325a54(a,iVar8);
    break;
  case 2:
    iVar8 = FUN_02321fec();
    puVar5 = PTR_DAT_02328b6c;
    if ((iVar8 == 0) &&
       (iVar8 = *(int *)(PTR_DAT_02328b6c + 0xc), *(int *)(PTR_DAT_02328b6c + 0xc) = iVar8 + 1,
       0x16 < iVar8 + 1)) {
      *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)(puVar5 + 0x14);
      FUN_02336880(PTR_DAT_02328b70,0x60,0x20);
      FUN_02336880(PTR_DAT_02328b74,0x1e0,0x20);
    }
    else {
      iVar8 = FUN_02321fe0();
      if (iVar8 == 0) {
        iVar8 = FUN_02322104();
        if (iVar8 == 0) {
          FUN_02320978(0x20);
          *(undefined4 *)(PTR_DAT_02328b6c + 0x14) = 0;
          FUN_02321fd4();
          *(undefined4 *)(PTR_DAT_02328b6c + 0xc) = 0x16;
        }
        else if (iVar8 == 1) {
          FUN_02320978(0x1b);
          *(undefined4 *)(PTR_DAT_02328b6c + 0x14) = 3;
          FUN_02321fd4();
          *(undefined4 *)(PTR_DAT_02328b6c + 0xc) = 0;
        }
      }
    }
    break;
  case 3:
    *(undefined4 *)(PTR_DAT_023281cc + 0x10) = 1;
    break;
  case 5:
    uVar14 = FUN_023212f8();
    uVar15 = FUN_02321304();
    iVar8 = FUN_0232e004(PTR_DAT_02328818,uVar14,uVar15);
    iVar13 = FUN_023212ec();
    if (iVar13 == 1) {
      if (iVar8 == 0x10) {
        *(undefined4 *)(PTR_DAT_02328810 + 0x20) = 0x10;
      }
    }
    else if (iVar13 == 3) {
      if ((iVar8 == *(int *)(PTR_DAT_02328810 + 0x20)) && (iVar8 == 0x10)) {
        *(undefined4 *)(PTR_DAT_02328810 + 0x10) = 6;
      }
      *(undefined4 *)(PTR_DAT_02328810 + 0x20) = 0xffffffff;
    }
    iVar8 = FUN_023212bc(1);
    if (iVar8 != 0) {
      *(undefined4 *)(PTR_DAT_02328810 + 0x10) = 6;
    }
    FUN_023210c8(PTR_DAT_0232881c,0,0,0,0);
    uVar14 = FUN_02320c7c();
    uVar15 = FUN_02327e20(0x10,1);
    FUN_02320e3c(uVar14,PTR_DAT_02328820,PTR_DAT_02328824,0x1a,uVar15);
    FUN_02327dac();
    break;
  case 9:
    uVar14 = FUN_023212f8();
    uVar15 = FUN_02321304();
    iVar8 = FUN_0232e004(PTR_DAT_02328818,uVar14,uVar15);
    iVar13 = FUN_023212ec();
    if (iVar13 == 1) {
      if (iVar8 == 0x10) {
        *(undefined4 *)(PTR_DAT_02328810 + 0x20) = 0x10;
      }
    }
    else if (iVar13 == 3) {
      if ((iVar8 == *(int *)(PTR_DAT_02328810 + 0x20)) && (iVar8 == 0x10)) {
        iVar8 = FUN_02329124();
        if (iVar8 == 2) {
          FUN_023393e0();
        }
        else {
          *(undefined4 *)(PTR_DAT_02328810 + 0x10) = 10;
        }
      }
      *(undefined4 *)(PTR_DAT_02328810 + 0x20) = 0xffffffff;
    }
    iVar8 = FUN_023212bc(1);
    if (iVar8 != 0) {
      iVar8 = FUN_02329124();
      if (iVar8 == 2) {
        FUN_023393e0();
      }
      else {
        *(undefined4 *)(PTR_DAT_02328810 + 0x10) = 10;
      }
    }
    FUN_023210c8(PTR_DAT_02328828,0,0,0,0);
    uVar14 = FUN_02320c7c();
    uVar15 = FUN_02327e20(0x10,1);
    FUN_02320e3c(uVar14,PTR_DAT_02328820,PTR_DAT_02328824,0x1a,uVar15);
    if (*(int *)(PTR_DAT_02328810 + 0x10) == 10) {
      FUN_02328e74(1);
    }
  }
  iVar8 = *(int *)(PTR_DAT_02328b6c + 0x10);
  if ((((iVar8 == 0) || (iVar8 == 2)) || (iVar8 == 3)) || (iVar8 == 7)) {
    FUN_02327dac();
  }
  if (*(int *)(PTR_DAT_02328b6c + 0x10) != 2) {
    FUN_023276d8();
  }
  FUN_02323d44(&sStack_28c);
  iVar8 = FUN_023234b4();
  if (iVar8 != 0) {
    iVar8 = FUN_023234b4();
    local_290 = (undefined2)iVar8;
    local_28e = 0;
    FUN_023216e0(PTR_DAT_02328b78,&local_290);
    uVar14 = FUN_023212f8();
    uVar15 = FUN_02321304();
    FUN_023210c8(PTR_DAT_02328b78,uVar14,uVar15,0,0);
  }
  uVar14 = FUN_02320c7c();
  FUN_02320e14(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,0x1e,(int)sStack_28c,(int)sStack_28a);
  uVar14 = FUN_02320c7c();
  FUN_02320e14(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,0x1f,(int)sStack_288,(int)sStack_286);
  uVar14 = FUN_02320c7c();
  FUN_02320e14(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,0x20,(int)sStack_284,(int)sStack_282);
  uVar14 = FUN_02320c7c();
  FUN_02320e14(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,0x21,(int)sStack_280,(int)sStack_27e);
  iVar8 = FUN_02329228();
  if (iVar8 != 0) {
    uVar14 = FUN_02320c7c();
    uVar15 = FUN_02327e20(0,0);
    FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,1,uVar15);
    uVar14 = FUN_02320c7c();
    uVar15 = FUN_02327e20(0,0);
    FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,2,uVar15);
  }
  uVar14 = FUN_02320c7c();
  uVar15 = FUN_02327e20(0,0);
  FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,0,uVar15);
  uVar14 = FUN_02320c7c();
  uVar15 = FUN_02327e20(1,0);
  FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,3,uVar15);
  uVar14 = FUN_02320c7c();
  uVar15 = FUN_02327e20(2,0);
  FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,4,uVar15);
  iVar8 = FUN_02327e20(0xe,0);
  if (iVar8 == 7) {
    uVar14 = 0x12;
  }
  else {
    uVar14 = 0x11;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,uVar14,iVar8);
  uVar14 = FUN_02320c7c();
  uVar15 = FUN_02327e20(3,0);
  FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,5,uVar15);
  uVar14 = FUN_02320c7c();
  uVar15 = FUN_02327e20(4,0);
  FUN_02320e3c(uVar14,PTR_DAT_02328b80,PTR_DAT_02328b7c,6,uVar15);
  uVar14 = 0;
  if ((*(ushort *)(PTR_DAT_02328b84 + 8) & 0xff) >> 4 == 2) {
    switch(PTR_DAT_02328b88[0x10]) {
    default:
      FUN_02322d70(6);
      uVar14 = 6;
      break;
    case 1:
      uVar14 = 5;
      FUN_02322d30();
      FUN_02322cd8();
      break;
    case 3:
      uVar14 = 8;
      break;
    case 4:
      uVar14 = 9;
    }
  }
  else {
    FUN_02322d70(6);
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,7,uVar14);
  if ((*(ushort *)(PTR_DAT_02328b84 + 8) & 0xff) >> 4 == 3) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,8,uVar14);
  if ((*(ushort *)(PTR_DAT_02328b84 + 8) & 0xf) == 0) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,10,uVar14);
  if ((*(ushort *)(PTR_DAT_02328b84 + 8) & 0xf) == 1) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,9,uVar14);
  local_27c = *(undefined4 *)PTR_DAT_02328b8c;
  local_278 = *(undefined4 *)(PTR_DAT_02328b8c + 4);
  local_274 = *(undefined4 *)(PTR_DAT_02328b8c + 8);
  FUN_0233621c(auStack_270,0xc);
  if ((*DAT_02328b90 & 7) == 0) {
    puVar17 = &local_27c;
  }
  else {
    puVar17 = auStack_270;
  }
  iVar8 = FUN_02323834();
  if (iVar8 == 0) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e60(uVar15,PTR_DAT_02328b80,PTR_DAT_02328b7c,0xb,0,*puVar17,uVar14);
  iVar8 = FUN_02323834();
  if (iVar8 == 2) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e60(uVar15,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0xc,0,puVar17[1],uVar14);
  iVar8 = FUN_02323834();
  if (iVar8 == 1) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e60(uVar15,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0xd,0,puVar17[2],uVar14);
  iVar8 = FUN_02323834();
  if (iVar8 == 3) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0xe,uVar14);
  iVar8 = FUN_02323834();
  if (iVar8 == 4) {
    uVar14 = 6;
  }
  else {
    uVar14 = 0;
  }
  uVar15 = FUN_02320c7c();
  FUN_02320e3c(uVar15,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0xf,uVar14);
  uVar14 = FUN_02320c7c();
  FUN_02320f4c(uVar14,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0x10,6,3);
  uVar14 = FUN_02320c7c();
  FUN_02320e88(uVar14,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0x10,2);
  uVar14 = FUN_02320c7c();
  FUN_02320e3c(uVar14,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0x1c,0);
  uVar14 = FUN_02320c7c();
  FUN_02320e3c(uVar14,PTR_DAT_02328cdc,PTR_DAT_02328cd8,0x1d,0);
  if (((*(int *)(PTR_DAT_02328ce0 + 0x10) == 0) || (*(int *)(PTR_DAT_02328ce0 + 0x10) == 7)) &&
     ((*(int *)(PTR_DAT_02328ce0 + 0x20) == -1 && (iVar8 = FUN_02323d14(), iVar8 == 0)))) {
    FUN_02325408(a,0);
  }
  iVar8 = *(int *)(PTR_DAT_02328ce0 + 0x10);
  if ((iVar8 == 0) || (iVar8 == 7)) {
    FUN_023374b8(*(undefined4 *)(a + 0x10),*(undefined4 *)(a + 0x3c),*(undefined4 *)(a + 0x44));
    FUN_023257b4(*(undefined4 *)(a + 0x3c),*(undefined4 *)(a + 0x24),*(undefined4 *)(a + 0x44));
    FUN_023374b8(*(undefined4 *)(a + 0x3c),*(undefined4 *)(a + 0x40),*(undefined4 *)(a + 0x44));
  }
  else if (iVar8 != 2) {
    FUN_023374b8(*(undefined4 *)(a + 0x38),*(undefined4 *)(a + 0x40),*(undefined4 *)(a + 0x44));
  }
  return;
}

