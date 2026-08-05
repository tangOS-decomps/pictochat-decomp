// decomp: module=arm7 addr=0x022c1690 name=FUN_022c1690
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3b0 (Ghidra's cache says 0x364 - it excludes this function's trailing literal pool), arm
// triage: noise=14 statements=149
// verify:  python tools/match.py --c <file> --func FUN_022c1690 --addr 0x022c1690 --size 0x3b0 --module arm7 --version 2.0/sp1


void FUN_022c1690(void)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined4 uVar7;
  short *psVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  longlong lVar12;
  undefined2 uStack_16;
  undefined2 local_14;
  undefined2 uStack_12;
  
  iVar10 = *DAT_022c19f4;
  FUN_022c1a40();
  func_0x00dd45a8((uint)*DAT_022c19f8 + (uint)*DAT_022c19f8 * 0x100,*DAT_022c19f8);
  *(undefined2 *)(iVar10 + 0x3c0) = 1;
  puVar6 = DAT_022c1a00;
  puVar5 = DAT_022c19fc;
  if ((int)((uint)*(ushort *)(iVar10 + 0x33a) << 0x1d) < 0) {
    *(ushort *)(iVar10 + 0x3c0) = *(ushort *)(iVar10 + 0x3c0) | 0x20;
  }
  if (*(short *)(iVar10 + 0x334) != 0) {
    *(ushort *)(iVar10 + 0x3c0) = *(ushort *)(iVar10 + 0x3c0) | 0x10;
  }
  *(undefined2 *)(iVar10 + 0x356) = 0;
  uVar7 = DAT_022c1a04;
  *puVar5 = 0x8000;
  *puVar6 = (short)uVar7;
  puVar5[-4] = 0;
  puVar6[-0x86] = 0;
  puVar6[-0x7e] = 0xf;
  func_0x00dd5d4c();
  func_0x00dde504();
  FUN_022c3768();
  FUN_022c3a88();
  puVar5 = DAT_022c1a08;
  *DAT_022c1a08 = 0x8000;
  psVar8 = DAT_022c1a0c;
  sVar2 = (short)DAT_022c1a04;
  puVar5[-0x10] = sVar2;
  piVar4 = DAT_022c19f4;
  *psVar8 = sVar2 + 0x2000;
  if ((*(ushort *)(*piVar4 + 0x690) & 8) == 0) {
    psVar8[-2] = 0;
  }
  else {
    psVar8[-2] = 0x400;
  }
  puVar5 = DAT_022c1a10;
  *DAT_022c1a10 = 0;
  puVar5[1] = 0;
  uVar7 = DAT_022c1a18;
  psVar8 = DAT_022c1a0c;
  piVar4 = DAT_022c19f4;
  sVar2 = (short)DAT_022c1a04;
  switch(*(undefined2 *)(iVar10 + 0x350)) {
  case 0:
    puVar5[5] = 0x3f;
    puVar5[100] = sVar2;
    puVar5[0x6c] = 8;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[0x70] = 0;
    puVar5[-2] = 1;
    break;
  case 1:
    puVar5[5] = (short)DAT_022c1a14;
    psVar8 = DAT_022c1a0c;
    *DAT_022c1a0c = (short)uVar7;
    psVar8[-0x6f] = 0x2300 - (short)uVar7;
    psVar8[-0x67] = 0xd;
    *puVar5 = 0xe000;
    puVar5[-2] = 1;
    uVar1 = *(ushort *)(iVar10 + 0x3b2);
    iVar11 = (uint)uVar1 * 0x400;
    lVar12 = FUN_022c3f7c(*(undefined4 *)(psVar8 + -0x5b),*(undefined4 *)(psVar8 + -0x59),iVar11,0);
    puVar5 = DAT_022c1a1c;
    lVar3 = (ulonglong)uVar1 * 0x400 * (lVar12 + 1U & 0xffffffff);
    iVar11 = (int)(lVar12 + 1U >> 0x20) * iVar11 + (int)((ulonglong)lVar3 >> 0x20);
    uStack_12 = (undefined2)((uint)iVar11 >> 0x10);
    *DAT_022c1a1c = uStack_12;
    local_14 = (undefined2)iVar11;
    puVar5[-1] = local_14;
    uStack_16 = (undefined2)((ulonglong)lVar3 >> 0x10);
    puVar5[-2] = uStack_16;
    puVar5[-3] = (ushort)lVar3 | 1;
    puVar5[-7] = 1;
    puVar5[-6] = 1;
    FUN_022c1ae0(0x40);
    func_0x00dda9d8();
    *DAT_022c1a20 = 2;
    break;
  case 2:
    puVar5[5] = (short)DAT_022c1a24;
    puVar9 = DAT_022c1a28;
    if ((*(ushort *)(*piVar4 + 0x690) & 0x20) != 0) {
      puVar5[5] = puVar5[5] | 0x40;
      *puVar9 = *puVar9 | 0x68;
    }
    if ((*(ushort *)(iVar10 + 0x3a8) & 1) == 0) {
      *DAT_022c1a2c = (short)DAT_022c1a34;
    }
    else {
      *DAT_022c1a2c = (short)DAT_022c1a30;
    }
    puVar5 = DAT_022c1a38;
    *DAT_022c1a38 = 0xb;
    puVar5[-0x6e] = 1;
    puVar5[4] = 1;
    puVar5[5] = 1;
    FUN_022c1ae0(0x20);
    break;
  case 3:
    puVar5[4] = sVar2;
    puVar5[5] = sVar2 + -0x3fc0;
    if ((*(ushort *)(iVar10 + 0x3a8) & 1) == 0) {
      puVar5[100] = 1;
    }
    else {
      puVar5[100] = 0x400 - sVar2;
    }
    puVar5 = DAT_022c1a38;
    *DAT_022c1a38 = 0xb;
    puVar5[-0x6e] = 1;
    puVar5[4] = 1;
    puVar5[5] = 1;
    puVar5[-0x4c] = 0;
    FUN_022c1ae0(0x20);
    break;
  case 4:
    puVar5[5] = 0;
    *psVar8 = 0;
    puVar5[-2] = 1;
    FUN_022c1ae0(0x20);
  }
  *DAT_022c1a3c = 0;
  func_0x00dd36f0();
  *DAT_022c1a20 = 2;
  if (*(short *)(iVar10 + 0x352) == 1) {
    func_0x00dd3510();
  }
  FUN_022c3ba8();
  return;
}

