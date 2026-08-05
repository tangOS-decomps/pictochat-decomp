// decomp: module=arm7 addr=0x022d2c24 name=FUN_022d2c24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x394 (Ghidra's cache says 0x388 - it excludes this function's trailing literal pool), arm
// triage: noise=12 statements=208
// verify:  python tools/match.py --c <file> --func FUN_022d2c24 --addr 0x022d2c24 --size 0x394 --module arm7 --version 2.0/sp1


void FUN_022d2c24(int param_1)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  short *psVar12;
  short *psVar13;
  int iVar14;
  uint uVar15;
  undefined8 uVar16;
  undefined1 auStack_224 [512];
  
  psVar12 = *(short **)(DAT_022d2fac + 0x550);
  iVar14 = *(int *)(param_1 + 4);
  uVar9 = *(uint *)(param_1 + 8);
  uVar10 = *(undefined4 *)(param_1 + 0xc);
  uVar11 = *(uint *)(param_1 + 0x10);
  sVar4 = 0;
  if (psVar12[0x4e] == 0) {
    if (uVar11 < ((ushort)psVar12[0x1e] + 0x1f & 0xffffffe0)) {
      sVar4 = 6;
    }
    if (psVar12[0xc4] == 0) {
      uVar3 = ((ushort)psVar12[0x1f] + 0xc) * (uint)(ushort)psVar12[0x7c] + 0x29;
    }
    else {
      uVar3 = (ushort)psVar12[0x1f] + 0x51;
    }
    if (uVar9 < (uVar3 & 0xffffffe0)) {
      sVar4 = 6;
    }
  }
  if ((psVar12[0x73] == 2) &&
     (((uint)(ushort)psVar12[0xfb] &
      (1 << (*(ushort *)(*(int *)(DAT_022d2fb0 + 0x154c) + 0x46) & 0xff)) >> 1) == 0)) {
    sVar4 = 6;
  }
  if (sVar4 == 0) {
    if (*(int *)(psVar12 + 6) != 0) {
      psVar12[6] = 0;
      psVar12[7] = 0;
      FUN_022d5870(DAT_022d2fb4);
    }
    FUN_022d43b8();
    uVar2 = func_0x037cb520();
    FUN_022d6470(param_1 + 0x14,0);
    uVar3 = *(uint *)(param_1 + 0x30);
    psVar13 = *(short **)(DAT_022d2fac + 0x550);
    if (*psVar13 != 9 && *psVar13 != 10) {
      func_0x037cb520();
      if ((uVar3 & 4) == 0) {
        uVar5 = psVar13[0x2e];
      }
      else {
        uVar5 = *(ushort *)(param_1 + 0x38);
      }
      uVar6 = (uint)uVar5;
      if (uVar6 == 0) {
        uVar6 = 0x10;
      }
      if ((uVar3 & 1) == 0) {
        uVar5 = psVar13[0x2c];
      }
      else {
        uVar5 = *(ushort *)(param_1 + 0x34);
      }
      uVar7 = (uint)uVar5;
      if (uVar7 == 0) {
        uVar7 = 0x10;
      }
      if (uVar6 < uVar7) {
        uVar7 = uVar6;
      }
      if ((uVar3 & 2) == 0) {
        uVar5 = psVar13[0x2d];
      }
      else {
        uVar5 = *(ushort *)(param_1 + 0x36);
      }
      uVar15 = (uint)uVar5;
      psVar13[0x3e2] = (short)uVar6;
      if (uVar15 == 0) {
        uVar15 = 0x10;
      }
      psVar13[0x3e0] = (short)uVar7;
      if (uVar6 < uVar15) {
        uVar15 = uVar6;
      }
      psVar13[0x3e1] = (short)uVar15;
      if ((int)uVar6 < (int)psVar13[0x31]) {
        psVar13[0x31] = (short)uVar6;
      }
      if ((uVar3 & 0x200) == 0) {
        sVar4 = psVar13[0x4c];
      }
      else {
        sVar4 = *(short *)(param_1 + 0x3a);
      }
      psVar13[0x3e5] = sVar4;
      if ((uVar3 & 0x400) == 0) {
        uVar5 = psVar13[0x49];
      }
      else {
        uVar5 = (ushort)*(byte *)(param_1 + 0x3c);
      }
      psVar13[0x3e3] = uVar5;
      if ((uVar3 & 0x800) == 0) {
        uVar5 = psVar13[0x4a];
      }
      else {
        uVar5 = (ushort)*(byte *)(param_1 + 0x3d);
      }
      psVar13[0x3e4] = uVar5;
      if ((uVar3 & 0x1000) == 0) {
        uVar5 = psVar13[0x4d];
      }
      else {
        uVar5 = (ushort)*(byte *)(param_1 + 0x3e);
      }
      psVar13[0x3e6] = uVar5;
      func_0x037cb534();
    }
    if ((ushort)(*psVar12 - 7U) < 2) {
      psVar12[0x42] = 0;
      psVar12[0x2f] = 0;
      psVar12[0x30] = 1;
      psVar12[0x44] = 0;
      psVar12[0x4f] = 0;
      psVar12[0x50] = 0x3c;
      psVar12[0x39a] = 0;
      psVar12[0x39b] = 0;
      psVar12[0x45] = 0;
      psVar12[0x46] = 0;
      psVar12[0x47] = 0;
      psVar12[0x48] = 0;
      psVar12[0x33] = 0;
      *(int *)(psVar12 + 0x3a) = iVar14;
      psVar12[0x39] = (short)uVar9;
      *(uint *)(psVar12 + 0x3c) = iVar14 + uVar9;
      psVar12[0x38] = 0;
      *(undefined4 *)(psVar12 + 0x3e) = uVar10;
      psVar12[0x40] = (short)uVar11;
      psVar12[0x31] = 0;
      psVar12[0x32] = 0;
      psVar12[0x34] = 0;
      psVar12[0x35] = 0;
      psVar12[0x5f] = -1;
      psVar12[0x60] = 1;
      uVar16 = func_0x037caa3c();
      iVar14 = 0;
      do {
        *(uint *)(psVar12 + iVar14 * 4 + 0x39c) = (uint)uVar16 | 1;
        iVar8 = iVar14 + 1;
        *(int *)(psVar12 + iVar14 * 4 + 0x39e) = (int)((ulonglong)uVar16 >> 0x20);
        iVar14 = iVar8;
      } while (iVar8 < 0x10);
      FUN_022ce6b8();
      psVar12[0x67] = 0;
      FUN_022d3be8();
      if (*psVar12 == 8) {
        *psVar12 = 10;
      }
      else if (*psVar12 == 7) {
        *psVar12 = 9;
      }
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 0xe;
      puVar1[1] = 0;
      puVar1[2] = 10;
      func_0x037d1464();
      psVar12[6] = 1;
      psVar12[7] = 0;
      func_0x037cb534(uVar2);
      iVar14 = FUN_022d073c(auStack_224,1);
      if (*(short *)(iVar14 + 4) != 0) {
        puVar1 = (undefined2 *)func_0x037d14bc();
        *puVar1 = 0xe;
        puVar1[1] = 1;
        puVar1[2] = 0x216;
        puVar1[3] = *(undefined2 *)(iVar14 + 4);
        func_0x037d1464();
      }
    }
    else {
      func_0x037cb534(uVar2);
      puVar1 = (undefined2 *)func_0x037d14bc();
      *puVar1 = 0xe;
      puVar1[1] = 3;
      puVar1[2] = 10;
      func_0x037d1464();
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 0xe;
    puVar1[1] = sVar4;
    puVar1[2] = 10;
    func_0x037d1464();
  }
  return;
}

