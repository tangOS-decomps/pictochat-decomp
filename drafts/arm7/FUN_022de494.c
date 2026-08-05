// decomp: module=arm7 addr=0x022de494 name=FUN_022de494
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4cc (Ghidra's cache says 0x4c8 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=210
// verify:  python tools/match.py --c <file> --func FUN_022de494 --addr 0x022de494 --size 0x4cc --module arm7 --version 2.0/sp1


void FUN_022de494(short *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  short *psVar5;
  uint uVar6;
  undefined2 uVar7;
  ushort uVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  iVar9 = *DAT_022de95c;
  uVar11 = (uint)(ushort)param_1[1];
  puVar10 = (ushort *)(iVar9 + 0x404);
  if ((param_1[4] & 2U) == 0) {
    *(int *)(iVar9 + 0x53c) = *(int *)(iVar9 + 0x53c) + 1;
    if ((param_1[0xc] & 1U) == 0) {
      *(int *)(iVar9 + 0x54c) = *(int *)(iVar9 + 0x54c) + 1;
    }
    else {
      *(int *)(iVar9 + 0x550) = *(int *)(iVar9 + 0x550) + 1;
    }
    iVar2 = FUN_022da03c(uVar11);
    if ((iVar2 != 0) && ((param_1[10] & 0x2000U) == 0)) {
      FUN_022d9dc4(uVar11);
    }
  }
  else {
    *(int *)(iVar9 + 0x540) = *(int *)(iVar9 + 0x540) + 1;
  }
  if ((int)((uint)(ushort)param_1[10] << 0x11) < 0) {
    *(int *)(iVar9 + 0x554) = *(int *)(iVar9 + 0x554) + 1;
  }
  *(uint *)(iVar9 + 0x544) = *(int *)(iVar9 + 0x544) + ((ushort)param_1[6] & 0xff);
  piVar1 = DAT_022de95c;
  uVar8 = param_1[10] & 0xfc;
  if (uVar8 < 0xa1) {
    if (uVar8 < 0xa0) {
      if (uVar8 < 0x11) {
        if (uVar8 != 0x10) goto LAB_022de914;
      }
      else if (uVar8 != 0x30) goto LAB_022de914;
      if (uVar11 != 0) {
        if ((param_1[4] & 2U) == 0) {
          if ((param_1[0x17] == 0) && (iVar2 = FUN_022d9ffc(uVar11), iVar2 == 0x30)) {
            FUN_022d9c60(uVar11,0x40);
            if (uVar8 == 0x10) {
              FUN_022dbc7c(param_1 + 0xc,param_1[0x18],(int)param_1 + (ushort)param_1[9] + 0x14);
            }
            else {
              FUN_022dbd74(param_1 + 0xc,param_1[0x18],(int)param_1 + (ushort)param_1[9] + 0x14);
            }
          }
        }
        else {
          FUN_022d9f7c(uVar11);
          puVar3 = (undefined2 *)FUN_022dfed8(param_1 + 0xc,1,0);
          if (puVar3 != (undefined2 *)0x0) {
            *puVar3 = 2;
            if (param_2 == 0) {
              FUN_022df0b0();
            }
            else {
              FUN_022df0b0();
              FUN_022ddf10(1);
            }
          }
        }
      }
    }
    else {
      if (*(short *)(iVar9 + 0x350) == 1) {
        if (uVar11 == 0) {
          if ((param_1[0xc] & 1U) != 0) {
            for (uVar11 = 1; uVar11 < *(ushort *)(*piVar1 + 0x322); uVar11 = uVar11 + 1) {
              uVar4 = FUN_022d9ffc(uVar11);
              if (0x30 < uVar4) {
                FUN_022d9c60(uVar11 & 0xffff,0x30);
              }
            }
          }
        }
        else {
          uVar4 = FUN_022d9ffc(uVar11);
          if (0x30 < uVar4) {
            FUN_022d9c60(uVar11,0x30);
          }
        }
      }
      else if (0x30 < *(ushort *)(iVar9 + 0x34c)) {
        func_0x037c62c0(0x30);
        FUN_022d8078();
      }
      psVar5 = (short *)(uint)*puVar10;
      bVar13 = psVar5 == (short *)0x71;
      if (bVar13) {
        psVar5 = *(short **)(iVar9 + 0x408);
      }
      if (bVar13 && param_1 == psVar5) {
        if ((param_1[4] & 2U) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0xc;
        }
        *(undefined2 *)(*(int *)(iVar9 + 0x420) + 4) = uVar7;
        *puVar10 = 0;
        FUN_022dbb30();
      }
    }
  }
  else if (uVar8 < 0xb1) {
    if (((uVar8 == 0xb0) && (uVar11 != 0)) && (uVar8 = param_1[4], (uVar8 & 2) == 0)) {
      bVar13 = param_1[0x16] == 0;
      if (bVar13) {
        uVar8 = param_1[0x17];
      }
      bVar12 = bVar13 && uVar8 == 2;
      if (bVar13 && uVar8 == 2) {
        uVar8 = param_1[0x18];
        bVar12 = uVar8 == 0;
      }
      if (bVar12) {
        FUN_022d9c60(uVar11,0x30);
        FUN_022dbb84(param_1 + 0xc,param_1[0x16]);
      }
      else {
        bVar13 = param_1[0x16] == 1;
        if (bVar13) {
          uVar8 = param_1[0x17];
        }
        bVar12 = bVar13 && uVar8 == 4;
        if (bVar13 && uVar8 == 4) {
          bVar12 = param_1[0x18] == 0;
        }
        if (bVar12) {
          FUN_022d9c60(uVar11,0x30);
          FUN_022dbb84(param_1 + 0xc,param_1[0x16]);
        }
      }
    }
  }
  else if (uVar8 == 0xc0) {
    if (*(short *)(iVar9 + 0x350) == 1) {
      if (uVar11 == 0) {
        if ((param_1[0xc] & 1U) != 0) {
          for (uVar4 = 1; uVar4 < *(ushort *)(*piVar1 + 0x322); uVar4 = uVar4 + 1) {
            uVar6 = FUN_022d9ffc(uVar4);
            if (0x20 < uVar6) {
              FUN_022d9c60(uVar4 & 0xffff,0x20);
            }
          }
        }
      }
      else {
        uVar4 = FUN_022d9ffc(uVar11);
        if (0x20 < uVar4) {
          FUN_022d9c60(uVar11,0x20);
        }
      }
    }
    else if (0x20 < *(ushort *)(iVar9 + 0x34c)) {
      func_0x037c62c0(0x20);
      FUN_022d8078();
    }
    psVar5 = (short *)(uint)*puVar10;
    bVar13 = psVar5 == (short *)0x41;
    if (bVar13) {
      psVar5 = *(short **)(iVar9 + 0x408);
    }
    if (bVar13 && param_1 == psVar5) {
      if ((param_1[4] & 2U) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0xc;
      }
      *(undefined2 *)(*(int *)(iVar9 + 0x420) + 4) = uVar7;
      *puVar10 = 0;
      FUN_022dbb30();
    }
    if (*param_1 == 1) {
      if (uVar11 != 0) {
        *(ushort *)(*DAT_022de95c + 0x534) =
             *(ushort *)(*DAT_022de95c + 0x534) & ~(ushort)(1 << (uVar11 & 0xff));
        FUN_022da448(uVar11);
      }
      FUN_022dbc00(param_1 + 0xc,1);
    }
    else if (*param_1 == 2) {
      FUN_022dbc00(param_1 + 0xc,param_1[0x16]);
    }
  }
LAB_022de914:
  FUN_022d9bf0(param_1);
  func_0x037c5998(iVar9 + 0x1a0,param_1 + -8);
  uVar11 = *DAT_022de95c + 0x400;
  *(undefined2 *)(*DAT_022de95c + 0x440) = 0;
  if (param_2 != 0) {
    uVar11 = (uint)*(ushort *)(iVar9 + 0x1a8);
  }
  if (param_2 != 0 && uVar11 != 0) {
    FUN_022ddf10(1);
  }
  return;
}

