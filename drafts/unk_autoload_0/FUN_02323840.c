// decomp: module=unk_autoload_0 addr=0x02323840 name=FUN_02323840
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x444 (Ghidra's cache says 0x426 - it excludes this function's trailing literal pool), thumb
// triage: noise=35 statements=290
// verify:  python tools/match.py --c <file> --func FUN_02323840 --addr 0x02323840 --size 0x444 --module unk_autoload_0 --version 2.0/sp1


void FUN_02323840(void)

{
  int *piVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  undefined *puVar5;
  undefined2 uVar6;
  int iVar7;
  ushort *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  int iVar16;
  ushort *puVar17;
  int iVar18;
  
  puVar5 = PTR_DAT_02323af0;
  *(undefined2 *)(PTR_DAT_02323af0 + 0x2c) = 0;
  *(undefined2 *)(puVar5 + 0x2e) = 0;
  if (*(int *)(puVar5 + 0x3c) == 0) {
    uVar11 = FUN_02325278();
    puVar5 = PTR_DAT_02323af0;
    if ((uVar11 & 2) == 0) {
      uVar11 = FUN_02325278();
      if ((uVar11 & 0x400) == 0) {
        uVar11 = FUN_02325278();
        if ((uVar11 & 0x40) == 0) {
          uVar11 = FUN_02325278();
          if ((uVar11 & 0x80) == 0) {
            uVar11 = FUN_02325278();
            if ((uVar11 & 0x20) == 0) {
              uVar11 = FUN_02325278();
              if ((uVar11 & 0x10) == 0) {
                iVar7 = FUN_023212bc(8);
                if ((iVar7 != 0) && (*(int *)(PTR_DAT_02323af0 + 0x40) != 0)) {
                  *(undefined **)(PTR_DAT_02323af0 + 0x38) = PTR_DAT_02323af8;
                }
              }
              else {
                uVar9 = FUN_0232414c(0x10,*(undefined4 *)(PTR_DAT_02323af0 + 0x38),
                                     **(undefined4 **)(PTR_DAT_02323af0 + 0x14));
                *(undefined4 *)(PTR_DAT_02323af0 + 0x38) = uVar9;
              }
            }
            else {
              uVar9 = FUN_0232414c(0x20,*(undefined4 *)(PTR_DAT_02323af0 + 0x38),
                                   **(undefined4 **)(PTR_DAT_02323af0 + 0x14));
              *(undefined4 *)(PTR_DAT_02323af0 + 0x38) = uVar9;
            }
          }
          else {
            uVar9 = FUN_0232414c(0x80,*(undefined4 *)(PTR_DAT_02323af0 + 0x38),
                                 **(undefined4 **)(PTR_DAT_02323af0 + 0x14));
            *(undefined4 *)(PTR_DAT_02323af0 + 0x38) = uVar9;
          }
        }
        else {
          puVar17 = *(ushort **)(PTR_DAT_02323af0 + 0x38);
          FUN_02320978(0x28);
          iVar18 = *(int *)(PTR_DAT_02323af0 + 4);
          uVar11 = ((*puVar17 & 0xff) * 2 + (puVar17[1] & 0xff)) / 2;
          iVar13 = *(int *)(PTR_DAT_02323af0 + 8) + (uint)(*puVar17 >> 8);
          iVar7 = iVar13 + -0x50;
          for (; puVar8 = puVar17, iVar13 != iVar7; iVar13 = iVar13 + -8) {
            for (iVar16 = iVar18 + uVar11; iVar16 != iVar18 + uVar11 + -0x10; iVar16 = iVar16 + -8)
            {
              if (iVar16 - *(int *)(PTR_DAT_02323af0 + 4) < 0) {
                iVar12 = iVar16 + 200;
              }
              else {
                iVar12 = iVar16;
                if (200 < iVar16 - *(int *)(PTR_DAT_02323af0 + 4)) {
                  iVar12 = iVar16 + -200;
                }
              }
              if (iVar13 - *(int *)(PTR_DAT_02323af0 + 8) < 0) {
                iVar14 = iVar13 + 0x6a;
              }
              else {
                iVar14 = iVar13;
                if (0x6a < iVar13 - *(int *)(PTR_DAT_02323af0 + 8)) {
                  iVar14 = iVar13 + -0x6a;
                }
              }
              puVar8 = (ushort *)FUN_0232310c(PTR_DAT_02323af4,iVar12,iVar14);
              if ((puVar8 != (ushort *)0x0) && (puVar8 != puVar17)) goto LAB_023239b0;
            }
          }
LAB_023239b0:
          *(ushort **)(PTR_DAT_02323af0 + 0x38) = puVar8;
        }
      }
      else {
        if (*(int *)(PTR_DAT_02323af0 + 0x34) == 0) {
          sVar3 = *(short *)(PTR_DAT_02323af0 + 0x32);
          if (sVar3 == 0) {
            *(undefined2 *)(PTR_DAT_02323af0 + 0x2c) = 4;
          }
          else if (sVar3 == 4) {
            *(undefined2 *)(PTR_DAT_02323af0 + 0x2c) = 5;
          }
          else if (sVar3 == 5) {
            *(undefined2 *)(PTR_DAT_02323af0 + 0x2c) = 5;
          }
        }
        FUN_02320978(6);
      }
    }
    else {
      *(undefined2 *)(PTR_DAT_02323af0 + 0x2c) = 1;
      if ((*(int *)(puVar5 + 0x40) == 0) || (iVar7 = FUN_02322da8(), iVar7 != 0)) {
        FUN_02320978(8);
      }
    }
  }
  else {
    *(undefined4 *)(puVar5 + 0x3c) = 0;
    *(undefined2 *)(puVar5 + 0x2c) = *(undefined2 *)(*(int *)(puVar5 + 0x38) + 6);
    if (*(short *)(*(int *)(puVar5 + 0x38) + 6) != 0) {
      uVar2 = *(ushort *)(puVar5 + 0x2c);
      if (uVar2 == 1) {
        if ((*(int *)(puVar5 + 0x40) == 0) || (iVar7 = FUN_02322da8(), iVar7 != 0)) {
          FUN_02320978(8);
        }
      }
      else if (uVar2 == 2) {
        if (*(int *)(puVar5 + 0x40) == 0) {
          FUN_02320978(10);
        }
        else {
          FUN_02320978(0xf);
        }
      }
      else if ((uVar2 == 0) || (*(ushort *)(*(int *)(puVar5 + 0x14) + 0xc) < uVar2)) {
        if (uVar2 != 0) {
          FUN_02320978(6);
        }
      }
      else {
        FUN_02320978(6);
      }
    }
  }
  iVar7 = FUN_023212e0();
  if (iVar7 != 0) {
    uVar9 = FUN_023212f8();
    uVar10 = FUN_02321304();
    uVar9 = FUN_0232310c(PTR_DAT_02323af4,uVar9,uVar10);
    *(undefined4 *)(PTR_DAT_02323af0 + 0x10) = uVar9;
  }
  iVar7 = FUN_023212ec();
  if (iVar7 == 1) {
    uVar9 = FUN_023212f8();
    uVar10 = FUN_02321304();
    iVar7 = FUN_0232310c(PTR_DAT_02323af4,uVar9,uVar10);
    puVar5 = PTR_DAT_02323af0;
    *(int *)(PTR_DAT_02323af0 + 0xc) = iVar7;
    if (iVar7 != 0) {
      uVar2 = *(ushort *)(iVar7 + 6);
      if (uVar2 == 1) {
        if ((*(int *)(puVar5 + 0x40) == 0) || (iVar7 = FUN_02322da8(), iVar7 != 0)) {
          FUN_02320978(8);
        }
      }
      else if (uVar2 == 2) {
        if (*(int *)(puVar5 + 0x40) == 0) {
          FUN_02320978(10);
        }
      }
      else if ((uVar2 == 0) || (*(ushort *)(*(int *)(puVar5 + 0x14) + 0xc) < uVar2)) {
        if (uVar2 != 0) {
          FUN_02320978(6);
        }
      }
      else {
        FUN_02320978(6);
      }
    }
  }
  else {
    iVar7 = FUN_023212ec();
    if (iVar7 == 3) {
      if ((*(int *)(PTR_DAT_02323af0 + 0xc) != 0) &&
         (iVar7 = FUN_023251e4((ushort *)PTR_DAT_02323afc), iVar7 == 0)) {
        uVar9 = FUN_023212f8();
        uVar10 = FUN_02321304();
        iVar7 = FUN_0232310c(PTR_DAT_02323af4,uVar9,uVar10);
        puVar5 = PTR_DAT_02323af0;
        if (iVar7 != 0) {
          piVar1 = (int *)(PTR_DAT_02323af0 + 0xc);
          sVar3 = *(short *)(*piVar1 + 6);
          if (*(short *)(iVar7 + 6) == sVar3) {
            *(short *)(PTR_DAT_02323af0 + 0x2c) = sVar3;
            uVar2 = *(ushort *)(*piVar1 + 6);
            if (uVar2 == 1) {
              if ((*(int *)(puVar5 + 0x40) == 0) || (iVar7 = FUN_02322da8(), iVar7 != 0)) {
                FUN_02320978(9);
              }
            }
            else if (uVar2 == 2) {
              if (*(int *)(puVar5 + 0x40) == 0) {
                FUN_02320978(0xb);
              }
            }
            else if ((uVar2 == 0) || (*(ushort *)(*(int *)(puVar5 + 0x14) + 0xc) < uVar2)) {
              if (uVar2 != 0) {
                FUN_02320978(7);
              }
            }
            else {
              FUN_02320978(7);
            }
          }
        }
      }
      if ((*(int *)(PTR_DAT_02323c78 + 0x18) != 0) && (*(short *)(PTR_DAT_02323c78 + 0x30) != 0)) {
        uVar9 = FUN_023212f8();
        uVar10 = FUN_02321304();
        (**(code **)(PTR_DAT_02323c78 + 0x18))
                  (*(undefined4 *)(PTR_DAT_02323c78 + 0x1c),*(undefined2 *)(PTR_DAT_02323c78 + 0x30)
                   ,uVar9,uVar10);
      }
      puVar5 = PTR_DAT_02323c78;
      *(undefined2 *)(PTR_DAT_02323c78 + 0x30) = 0;
      *(undefined4 *)(puVar5 + 0xc) = 0;
    }
  }
  bVar4 = false;
  bVar15 = false;
  if ((*(int *)(PTR_DAT_02323c78 + 0xc) != 0) && (*(int *)(PTR_DAT_02323c78 + 0x10) != 0)) {
    bVar15 = true;
  }
  if ((bVar15) &&
     (*(short *)(*(int *)(PTR_DAT_02323c78 + 0x10) + 6) ==
      *(short *)(*(int *)(PTR_DAT_02323c78 + 0xc) + 6))) {
    bVar4 = true;
  }
  if (bVar4) {
    FUN_0232519c(PTR_DAT_02323c7c);
    iVar7 = FUN_023251cc(PTR_DAT_02323c7c);
    puVar5 = PTR_DAT_02323c78;
    if (iVar7 != 0) {
      piVar1 = (int *)(PTR_DAT_02323c78 + 0xc);
      *(undefined2 *)(PTR_DAT_02323c78 + 0x2c) = *(undefined2 *)(*piVar1 + 6);
      uVar2 = *(ushort *)(*piVar1 + 6);
      if (uVar2 == 1) {
        if ((*(int *)(puVar5 + 0x40) == 0) || (iVar7 = FUN_02322da8(), iVar7 != 0)) {
          FUN_02320978(8);
        }
      }
      else if (uVar2 == 2) {
        if (*(int *)(puVar5 + 0x40) == 0) {
          FUN_02320978(10);
        }
      }
      else if ((uVar2 == 0) || (*(ushort *)(*(int *)(puVar5 + 0x14) + 0xc) < uVar2)) {
        if (uVar2 != 0) {
          FUN_02320978(6);
        }
      }
      else {
        FUN_02320978(6);
      }
    }
  }
  else {
    FUN_023251c4(PTR_DAT_02323c7c);
  }
  uVar9 = FUN_023212f8();
  uVar10 = FUN_02321304();
  iVar7 = FUN_0232310c(PTR_DAT_02323c80,uVar9,uVar10);
  iVar13 = *(int *)(PTR_DAT_02323c78 + 0xc);
  if ((iVar13 != 0) &&
     (((iVar7 == 0 || (iVar13 != iVar7)) &&
      (uVar11 = FUN_02323c90(PTR_DAT_02323c80,*(undefined2 *)(iVar13 + 6)), 0x1f < uVar11)))) {
    *(short *)(PTR_DAT_02323c78 + 0x30) = (short)uVar11;
  }
  uVar6 = FUN_02323c90(PTR_DAT_02323c80,*(undefined2 *)(PTR_DAT_02323c78 + 0x2c));
  puVar5 = PTR_DAT_02323c78;
  *(undefined2 *)(PTR_DAT_02323c78 + 0x2e) = uVar6;
  if (*(short *)(puVar5 + 0x2c) != 0) {
    (**(code **)(*(int *)(puVar5 + 0x14) + 8))(PTR_DAT_02323c80);
  }
  FUN_023232e8(PTR_DAT_02323c80);
  return;
}

