// decomp: module=arm7 addr=0x022c3a88 name=FUN_022c3a88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x120 (Ghidra's cache says 0xf8 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=52
// verify:  python tools/match.py --c <file> --func FUN_022c3a88 --addr 0x022c3a88 --size 0x120 --module arm7 --version 2.0/sp1


void FUN_022c3a88(void)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  int unaff_r6;
  
  iVar7 = *DAT_022c3b80;
  FUN_022c6fc8(0,(short *)(iVar7 + 0x4dc),0x50);
  piVar3 = DAT_022c3b80;
  *DAT_022c3b84 = 0x8000;
  uVar5 = DAT_022c3b98;
  psVar4 = DAT_022c3b94;
  switch(*(undefined2 *)(*piVar3 + 0x350)) {
  case 0:
    unaff_r6 = DAT_022c3b88;
    break;
  case 1:
    unaff_r6 = DAT_022c3b8c;
    break;
  case 2:
    unaff_r6 = DAT_022c3b90;
    break;
  case 3:
    unaff_r6 = DAT_022c3b88;
  }
  *DAT_022c3b94 = (short)unaff_r6 + 0x4000;
  sVar1 = (short)((uint)(unaff_r6 << 0xf) >> 0x10);
  psVar4[3] = sVar1;
  sVar2 = (short)uVar5;
  psVar4[1] = sVar2;
  psVar4[5] = sVar1;
  uVar5 = DAT_022c3b9c;
  *(short *)(iVar7 + 0x4e0) = sVar1;
  sVar1 = (short)uVar5;
  *(short *)(iVar7 + 0x4dc) = sVar1;
  *(short *)(iVar7 + 0x3de) = (sVar2 + -0x4000) - (short)unaff_r6;
  psVar4[9] = sVar2 + -2;
  psVar4[-0x10] = -0x8000 - sVar1;
  psVar6 = DAT_022c3ba0;
  psVar4[0xfe] = sVar1;
  psVar4 = DAT_022c3ba4;
  *psVar6 = sVar1;
  *psVar4 = sVar1;
  psVar4[1] = sVar1;
  psVar4[7] = sVar1;
  psVar4[3] = sVar1;
  return;
}

