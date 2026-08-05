// decomp: module=arm7 addr=0x022c1338 name=FUN_022c1338
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2d0 (Ghidra's cache says 0x2b0 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=151
// verify:  python tools/match.py --c <file> --func FUN_022c1338 --addr 0x022c1338 --size 0x2d0 --module arm7 --version 2.0/sp1


void FUN_022c1338(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  ushort uVar8;
  int iVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  piVar1 = DAT_022c15e8;
  uVar8 = 0;
  iVar4 = *DAT_022c15e8;
  uVar10 = 0;
  if (*(short *)(iVar4 + 0x428) != 0) {
    return;
  }
  iVar3 = *(int *)(iVar4 + 0x200);
  *(int *)(iVar4 + 0x424) = iVar3;
  if (iVar3 == -1) {
    return;
  }
  iVar5 = *piVar1;
  iVar9 = iVar3 + (uint)*(ushort *)(iVar3 + 0xe) * 2;
  if (*(short *)(iVar5 + 0x33e) == 0) {
    uVar11 = (uint)*(ushort *)(iVar3 + 0xc);
    if (uVar11 == *(ushort *)(iVar9 + 0x10)) {
      uVar6 = uVar11 & 0xff00;
      if (uVar6 < 0x101) {
        if (uVar6 < 0x100) {
          if ((*(ushort *)(iVar3 + 0xc) & 0xff00) != 0) goto LAB_022c1500;
          uVar11 = uVar11 & 0xff;
          uVar10 = 1;
          uVar6 = 0xb;
          param_2 = DAT_022c15ec;
          if ((*(ushort *)(iVar4 + 0x428) & 1) == 0) {
            uVar8 = (ushort)(*(ushort *)(iVar5 + 0x34c) < 0x20);
          }
          else {
            uVar8 = 2;
          }
        }
        else {
          uVar11 = uVar11 & 0xff;
          uVar10 = 2;
          uVar6 = 5;
          uVar8 = (ushort)(*(short *)(iVar5 + 0x34c) != 0x40);
          param_2 = DAT_022c15f0;
        }
      }
      else if (uVar6 < 0x201) {
        if (uVar6 == 0x200) {
          uVar11 = uVar11 & 0xff;
          if (uVar11 < 0x40) {
            uVar10 = 4;
            uVar8 = (ushort)(*(ushort *)(iVar5 + 0x34c) < 0x10);
            uVar6 = 0x17;
            param_2 = DAT_022c15f4;
          }
          else if (uVar11 < 0x80) {
            uVar10 = 8;
            uVar8 = (ushort)(*(short *)(iVar5 + 0x34c) != 0x40);
            uVar11 = uVar11 - 0x40 & 0xffff;
            uVar6 = 6;
            param_2 = DAT_022c15f8;
          }
          else if (uVar11 < 0xc0) {
            uVar8 = (ushort)(*(ushort *)(iVar5 + 0x34c) < 0x10);
            uVar11 = uVar11 - 0x80 & 0xffff;
            uVar10 = 0x10;
            uVar6 = 0x17;
            param_2 = DAT_022c15fc;
          }
          else {
            uVar8 = (ushort)(*(ushort *)(iVar5 + 0x34c) < 0x10);
            uVar11 = uVar11 - 0xc0 & 0xffff;
            uVar10 = 0x20;
            uVar6 = 6;
            param_2 = DAT_022c1600;
          }
        }
        else {
LAB_022c1500:
          uVar11 = 1;
          uVar6 = 0;
          uVar10 = 0;
        }
      }
      else {
        if (uVar6 != 0x300) goto LAB_022c1500;
        uVar11 = uVar11 & 0xff;
        uVar10 = 0x40;
        uVar6 = 0xb;
        param_2 = DAT_022c1604;
      }
      if (uVar6 < uVar11) {
        uVar8 = 3;
      }
      else {
        uVar6 = uVar11 * 8;
        uVar12 = (uint)*(ushort *)(param_2 + uVar6);
        bVar13 = uVar12 <= *(ushort *)(iVar3 + 0xe);
        if (bVar13) {
          iVar5 = param_2 + uVar6;
          uVar6 = (uint)*(ushort *)(iVar9 + 0x12);
          uVar12 = (uint)*(ushort *)(iVar5 + 2);
        }
        if (!bVar13 || uVar6 < uVar12) {
          uVar8 = 4;
        }
      }
      if (uVar8 == 0) {
        uVar8 = *(ushort *)(iVar4 + 0x428);
        *(ushort *)(iVar4 + 0x428) = uVar8 | uVar10;
        pcVar7 = *(code **)(param_2 + uVar11 * 8 + 4);
        uVar2 = (*pcVar7)(iVar3,iVar9 + 0x10,pcVar7,uVar8,param_4);
        *(undefined2 *)(iVar9 + 0x14) = uVar2;
        if (*(short *)(iVar9 + 0x14) == 0x80) {
          return;
        }
        if (*(short *)(iVar9 + 0x14) == 0x81) {
          *(ushort *)(iVar4 + 0x428) = *(ushort *)(iVar4 + 0x428) & ~uVar10;
          goto LAB_022c15bc;
        }
      }
      else {
        *(undefined2 *)(iVar9 + 0x12) = 1;
        *(ushort *)(iVar9 + 0x14) = uVar8;
      }
    }
    else {
      *(undefined2 *)(iVar9 + 0x14) = 0xd;
    }
  }
  else {
    *(undefined2 *)(iVar9 + 0x12) = 1;
    *(undefined2 *)(iVar9 + 0x14) = 6;
  }
  *(ushort *)(iVar4 + 0x428) = *(ushort *)(iVar4 + 0x428) & ~uVar10;
  FUN_022c1608(*DAT_022c15e8 + 0x200,*(int *)(iVar4 + 0x424));
LAB_022c15bc:
  if (*(short *)(*DAT_022c15e8 + 0x208) != 0) {
    FUN_022c0e48(2,0xb);
  }
  return;
}

