// decomp: module=arm7 addr=0x022c3768 name=FUN_022c3768
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x320 (Ghidra's cache says 0x2d0 - it excludes this function's trailing literal pool), arm
// triage: noise=59 statements=151
// verify:  python tools/match.py --c <file> --func FUN_022c3768 --addr 0x022c3768 --size 0x320 --module arm7 --version 2.0/sp1


void FUN_022c3768(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined4 in_r3;
  int iVar11;
  
  iVar11 = *DAT_022c3a38;
  FUN_022c6fc8(0,iVar11 + 0x42c,0xb0,in_r3,in_r3);
  *(undefined2 *)(iVar11 + 0x42c) = 0;
  *(undefined4 *)(iVar11 + 0x438) = 0;
  *(undefined2 *)(iVar11 + 0x440) = 0;
  *(undefined4 *)(iVar11 + 0x44c) = 0;
  *(undefined2 *)(iVar11 + 0x454) = 0;
  uVar3 = DAT_022c3a3c;
  *(undefined4 *)(iVar11 + 0x460) = 0;
  *(short *)(iVar11 + 0x4ce) = (short)uVar3;
  *(short *)(iVar11 + 0x4d0) = (short)uVar3;
  puVar10 = DAT_022c3a7c;
  iVar9 = DAT_022c3a78;
  iVar8 = DAT_022c3a68;
  iVar7 = DAT_022c3a64;
  puVar5 = DAT_022c3a44;
  iVar4 = DAT_022c3a40;
  switch(*(undefined2 *)(iVar11 + 0x350)) {
  case 0:
    *(int *)(iVar11 + 0x434) = DAT_022c3a40;
    *(int *)(iVar11 + 0x448) = iVar4 + -0x148;
    uVar3 = DAT_022c3a48;
    *(int *)(iVar11 + 0x45c) = iVar4 + -0x170;
    uVar6 = DAT_022c3a4c;
    *(undefined4 *)(iVar11 + 0x43c) = uVar3;
    uVar3 = DAT_022c3a50;
    *(undefined4 *)(iVar11 + 0x450) = uVar6;
    uVar6 = DAT_022c3a54;
    *(undefined4 *)(iVar11 + 0x464) = uVar3;
    uVar3 = DAT_022c3a58;
    uVar1 = (undefined2)uVar6;
    *(undefined2 *)(iVar4 + -0x14c) = uVar1;
    uVar2 = (undefined2)uVar3;
    *puVar5 = uVar2;
    *(undefined2 *)(iVar4 + -4) = uVar1;
    puVar5[0xa4] = uVar2;
    puVar5 = DAT_022c3a5c;
    *(undefined2 *)(iVar4 + 0x620) = uVar1;
    *puVar5 = uVar2;
    puVar5 = DAT_022c3a60;
    *(undefined2 *)(iVar11 + 0x3ce) = 8;
    *puVar5 = 1;
    break;
  case 1:
    *(int *)(iVar11 + 0x434) = DAT_022c3a64;
    *(int *)(iVar11 + 0x448) = iVar7 + -0x148;
    uVar3 = DAT_022c3a48;
    *(int *)(iVar11 + 0x45c) = iVar8;
    uVar6 = DAT_022c3a4c;
    *(undefined4 *)(iVar11 + 0x43c) = uVar3;
    uVar3 = DAT_022c3a6c;
    *(undefined4 *)(iVar11 + 0x450) = uVar6;
    puVar5 = DAT_022c3a70;
    *(undefined4 *)(iVar11 + 0x464) = uVar3;
    *(int *)(iVar11 + 0x4ac) = iVar8 + -0xfc;
    uVar3 = DAT_022c3a54;
    *(int *)(iVar11 + 0x470) = iVar8 + -0x334;
    uVar6 = DAT_022c3a58;
    uVar1 = (undefined2)uVar3;
    *(undefined2 *)(iVar8 + -0x100) = uVar1;
    uVar2 = (undefined2)uVar6;
    *(undefined2 *)(iVar8 + -0xfe) = uVar2;
    *(undefined2 *)(iVar8 + -4) = uVar1;
    *(undefined2 *)(iVar8 + -2) = uVar2;
    *(undefined2 *)(iVar8 + 0x620) = uVar1;
    *puVar5 = uVar2;
    *(undefined2 *)(iVar7 + -4) = uVar1;
    puVar5[0xa4] = uVar2;
    puVar5 = DAT_022c3a74;
    *(undefined2 *)(iVar7 + 0x620) = uVar1;
    *puVar5 = uVar2;
    *(undefined2 *)(iVar11 + 0x3ce) = 0x208;
    *(int *)(iVar11 + 0x4ac) = iVar8 + -0xfc;
    func_0x00ddaa40();
    break;
  case 2:
    *(int *)(iVar11 + 0x434) = DAT_022c3a78;
    *(int *)(iVar11 + 0x448) = iVar9 + -0x148;
    iVar4 = DAT_022c3a80;
    uVar3 = DAT_022c3a48;
    *(int *)(iVar11 + 0x45c) = iVar9 + -0x170;
    uVar6 = DAT_022c3a4c;
    *(undefined4 *)(iVar11 + 0x43c) = uVar3;
    uVar3 = DAT_022c3a50;
    *(undefined4 *)(iVar11 + 0x450) = uVar6;
    *(undefined4 *)(iVar11 + 0x464) = uVar3;
    *(int *)(iVar11 + 0x484) = iVar4;
    uVar3 = DAT_022c3a54;
    *(int *)(iVar11 + 0x498) = iVar4 + 0x234;
    uVar6 = DAT_022c3a58;
    uVar1 = (undefined2)uVar3;
    *(undefined2 *)(iVar4 + 0x230) = uVar1;
    uVar2 = (undefined2)uVar6;
    *puVar10 = uVar2;
    *(undefined2 *)(iVar9 + -0x174) = uVar1;
    puVar10[0x11a] = uVar2;
    *(undefined2 *)(iVar9 + -0x14c) = uVar1;
    puVar10[0x12e] = uVar2;
    *(undefined2 *)(iVar9 + -4) = uVar1;
    puVar10[0x1d2] = uVar2;
    puVar5 = DAT_022c3a84;
    *(undefined2 *)(iVar9 + 0x620) = uVar1;
    *puVar5 = uVar2;
    puVar5 = DAT_022c3a60;
    *(undefined2 *)(iVar11 + 0x3ce) = 0x108;
    *puVar5 = 0xd;
    break;
  case 3:
    *(int *)(iVar11 + 0x434) = DAT_022c3a40;
    *(int *)(iVar11 + 0x448) = iVar4 + -0x148;
    uVar3 = DAT_022c3a48;
    *(int *)(iVar11 + 0x45c) = iVar4 + -0x170;
    uVar6 = DAT_022c3a4c;
    *(undefined4 *)(iVar11 + 0x43c) = uVar3;
    uVar3 = DAT_022c3a50;
    *(undefined4 *)(iVar11 + 0x450) = uVar6;
    uVar6 = DAT_022c3a54;
    *(undefined4 *)(iVar11 + 0x464) = uVar3;
    uVar3 = DAT_022c3a58;
    uVar1 = (undefined2)uVar6;
    *(undefined2 *)(iVar4 + -0x14c) = uVar1;
    uVar2 = (undefined2)uVar3;
    *puVar5 = uVar2;
    *(undefined2 *)(iVar4 + -4) = uVar1;
    puVar5[0xa4] = uVar2;
    puVar5 = DAT_022c3a5c;
    *(undefined2 *)(iVar4 + 0x620) = uVar1;
    *puVar5 = uVar2;
    puVar5 = DAT_022c3a60;
    *(undefined2 *)(iVar11 + 0x3ce) = 0x108;
    *puVar5 = 0xd;
  }
  if (*(short *)(iVar11 + 0x334) != 0) {
    *(ushort *)(iVar11 + 0x3ce) = *(ushort *)(iVar11 + 0x3ce) | 0x4000;
  }
  return;
}

