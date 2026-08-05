// decomp: module=arm7 addr=0x022c22b0 name=FUN_022c22b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x268 (Ghidra's cache says 0x248 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=102
// verify:  python tools/match.py --c <file> --func FUN_022c22b0 --addr 0x022c22b0 --size 0x268 --module arm7 --version 2.0/sp1


void FUN_022c22b0(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 in_r3;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  bool bVar14;
  
  puVar3 = DAT_022c24fc;
  piVar2 = DAT_022c24f8;
  iVar10 = *DAT_022c24f8;
  *DAT_022c24fc = 2;
  puVar5 = DAT_022c2508;
  puVar4 = DAT_022c2504;
  uVar9 = DAT_022c2500;
  if (*(short *)(*piVar2 + 0x34c) == 0x12) {
    func_0x00dd8cfc();
  }
  else {
    uVar13 = puVar3[0x54] & 0xf00;
    if (uVar13 == 0x300) {
      if ((*(uint *)(iVar10 + 0x4b8) & 2) != 0) {
        FUN_022c2e40();
      }
      iVar11 = *DAT_022c24f8;
      iVar8 = *(int *)(iVar11 + 0x558) + 1;
      *(int *)(iVar11 + 0x558) = iVar8;
      FUN_022c0e48(0,8,iVar8,iVar11,in_r3);
    }
    else if (uVar13 == 0x800) {
      if (*(ushort *)(iVar10 + 0x4ca) <= (*(ushort *)(*(int *)(iVar10 + 0x470) + 4) & 0xff)) {
        puVar3[0x4e] = 2;
        *(short *)(iVar10 + 0x4d4) = *(short *)(iVar10 + 0x4d4) + 1;
      }
      *(short *)(*(int *)(iVar10 + 0x4bc) + 0x18) = *(short *)(*(int *)(iVar10 + 0x4bc) + 0x18) + 1;
    }
    else if (uVar13 == 0xb00) {
      uVar1 = (undefined2)DAT_022c2500;
      *DAT_022c2504 = uVar1;
      puVar4[1] = uVar1;
      puVar3[0x11e] = uVar1;
      *puVar5 = uVar1;
      if (((*(short *)(iVar10 + 0x468) != 0) &&
          (iVar8 = *(int *)(iVar10 + 0x470), *(ushort *)(iVar8 + 0x22) == uVar9)) &&
         (*(short *)(iVar8 + 4) != 0)) {
        *(undefined2 *)(iVar8 + 4) = 0;
        *(undefined2 *)(*(int *)(iVar10 + 0x470) + 2) = *(undefined2 *)(iVar10 + 0x4c4);
      }
      uVar9 = (uint)*(ushort *)(*(int *)(iVar10 + 0x470) + 2);
      uVar7 = (uint)*(ushort *)(iVar10 + 0x4c4);
      iVar8 = *(int *)(iVar10 + 0x4bc) + 0x1a;
      if (((1 < uVar9) && ((int)((uint)*(ushort *)(*DAT_022c24f8 + 0x33a) << 0x1b) < 0)) &&
         ((*DAT_022c250c & 1) == 0)) {
        DAT_022c250c[0x7a] = DAT_022c250c[0x7a] ^ 1;
      }
      uVar12 = (uint)*(ushort *)(*DAT_022c24f8 + 0x690);
      if ((*(ushort *)(*DAT_022c24f8 + 0x690) & 0x40) != 0) {
        while (1 < uVar9) {
          uVar9 = uVar9 >> 1;
          bVar14 = (uVar9 & 1) != 0;
          if (bVar14) {
            uVar12 = *(ushort *)(iVar8 + 6) + 1;
          }
          uVar7 = uVar7 >> 1;
          if (bVar14) {
            *(short *)(iVar8 + 6) = (short)uVar12;
          }
          if ((uVar7 & 1) != 0) {
            uVar12 = (uint)*(ushort *)(*(int *)(iVar10 + 0x4bc) + 0x16);
            iVar8 = iVar8 + uVar12;
          }
        }
      }
    }
    puVar6 = DAT_022c2510;
    if ((uVar13 != 0x800) && ((*DAT_022c2510 & 2) == 0)) {
      if (*(short *)(iVar10 + 0x468) != 0) {
        DAT_022c2510[2] = 2;
        puVar6[-0x34] = 0;
        if ((puVar6[-0x50] & 0x1000) == 0) {
          FUN_022c29d4();
        }
        else {
          *(short *)(iVar10 + 0x4d8) = *(short *)(iVar10 + 0x4d8) + 1;
        }
        *(short *)(iVar10 + 0x4d6) = *(short *)(iVar10 + 0x4d6) + 1;
      }
      *DAT_022c2514 = 2;
    }
    FUN_022c0e48(0,0xe);
  }
  return;
}

