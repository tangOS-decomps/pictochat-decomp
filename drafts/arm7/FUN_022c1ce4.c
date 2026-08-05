// decomp: module=arm7 addr=0x022c1ce4 name=FUN_022c1ce4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a4 (Ghidra's cache says 0x284 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=104
// verify:  python tools/match.py --c <file> --func FUN_022c1ce4 --addr 0x022c1ce4 --size 0x2a4 --module arm7 --version 2.0/sp1


void FUN_022c1ce4(void)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  puVar4 = DAT_022c1f6c;
  piVar3 = DAT_022c1f68;
  iVar8 = *DAT_022c1f68;
  *DAT_022c1f6c = 0x4000;
  sVar1 = *(short *)(iVar8 + 0x350);
  if (sVar1 == 1) {
    uVar2 = *(ushort *)(piVar3 + -1);
    iVar10 = *(int *)(iVar8 + 0x4ac) + 0x24 + (uint)*(ushort *)(iVar8 + 0x3da);
    func_0x00dd4560(iVar10 + 8,uVar2 & 0xff);
    func_0x00dd4560(iVar10 + 9,uVar2 >> 8);
    if (*(short *)(iVar8 + 0x352) == 1) {
      *DAT_022c1f70 = *(short *)(iVar8 + 0x33c) + *DAT_022c1f70 + 1;
    }
    puVar5 = DAT_022c1f74;
    iVar10 = *DAT_022c1f68;
    *(ushort *)(iVar10 + 0x530) = ~*(ushort *)(iVar10 + 0x52e) | *(ushort *)(iVar10 + 0x532);
    if (((*puVar5 & 0x18) == 0) && ((*puVar5 & 6) != 2)) {
      *(uint *)(iVar8 + 0x4b8) = *(uint *)(iVar8 + 0x4b8) | 2;
      return;
    }
    *(uint *)(iVar8 + 0x4b8) = *(uint *)(iVar8 + 0x4b8) & 0xfffffffd;
    FUN_022c2e40();
    return;
  }
  if (sVar1 == 2) {
    if (*(short *)(iVar8 + 0x356) == 0) {
      puVar4[0x92] = (short)DAT_022c1f78;
    }
    else {
      psVar7 = puVar4 + 0x92;
      *psVar7 = *(short *)(iVar8 + 0x33c) + *psVar7 + 1;
    }
    if (*(short *)(iVar8 + 0x35e) == 2) {
      func_0x00dd3510(2);
    }
  }
  else if (sVar1 != 3) {
    return;
  }
  if (*(short *)(iVar8 + 0x34c) == 0x40) {
    bVar11 = *(short *)(iVar8 + 0x3b6) == 1;
    if (*(short *)(iVar8 + 0x358) != 0) {
      sVar1 = *(short *)(iVar8 + 0x3ba);
      if (sVar1 != 1) {
        bVar12 = sVar1 != 0;
        if (!bVar12) {
          sVar1 = *(short *)(iVar8 + 0x3b8);
        }
        if (bVar12 || sVar1 != 1) goto LAB_022c1e70;
      }
      bVar11 = true;
    }
  }
  else {
    bVar11 = true;
  }
LAB_022c1e70:
  if (bVar11) {
    *DAT_022c1f7c = *DAT_022c1f7c | 1;
  }
  else {
    *DAT_022c1f7c = *DAT_022c1f7c & 0xfffe;
  }
  uVar9 = 0;
  if (10 < *DAT_022c1f80) {
    DAT_022c1f80[-0x68] = 0;
  }
  *(short *)(iVar8 + 0x3b6) = *(short *)(iVar8 + 0x3b6) + -1;
  if (*(short *)(iVar8 + 0x3b6) == 0) {
    *(undefined2 *)(iVar8 + 0x3b6) = *(undefined2 *)(iVar8 + 0x3b4);
  }
  sVar1 = *(short *)(iVar8 + 0x3ba);
  *(short *)(iVar8 + 0x3ba) = sVar1 + -1;
  if (sVar1 == 0) {
    *(short *)(iVar8 + 0x3ba) = *(short *)(iVar8 + 0x3b8) + -1;
  }
  do {
    iVar10 = iVar8 + 0x42c + uVar9 * 0x14;
    if (((*(short *)(iVar8 + 0x42c + uVar9 * 0x14) != 0) &&
        (*(short *)(*(int *)(iVar10 + 0xc) + 8) == 0)) && (iVar6 = func_0x00dd9ab8(), iVar6 != 0)) {
      func_0x00dda510(uVar9);
      **(undefined2 **)(iVar10 + 8) = 2;
      FUN_022c0e48(0,0xe);
      *(short *)(iVar8 + 0x4da) = *(short *)(iVar8 + 0x4da) + 1;
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 2);
  *DAT_022c1f84 = 0xd;
  return;
}

