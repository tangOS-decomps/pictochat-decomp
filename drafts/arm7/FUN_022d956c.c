// decomp: module=arm7 addr=0x022d956c name=FUN_022d956c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e0 (Ghidra's cache says 0x2d4 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=120  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d956c --addr 0x022d956c --size 0x2e0 --module arm7 --version 2.0/sp1


void FUN_022d956c(void)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar8 = 0;
  iVar10 = DAT_022d9844;
  if (*(short *)(*DAT_022d9840 + 0x5f8) != 5) {
    iVar10 = DAT_022d9848;
  }
  for (; uVar8 < 0x69; uVar8 = uVar8 + 1) {
    iVar5 = FUN_022d862c(uVar8,0xff);
    if (iVar5 == -1) {
      uVar8 = 1;
      goto LAB_022d9818;
    }
  }
  iVar5 = 0;
  uVar9 = 0;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar10 + iVar5 * 2)) {
      iVar5 = iVar5 + 1;
    }
    else {
      sVar1 = FUN_022d8600(uVar6);
      if ((sVar1 != 0xff) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_022d9818;
    }
    uVar9 = uVar8;
  }
  uVar8 = 0;
  do {
    FUN_022d862c(uVar8,0);
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x69);
  iVar5 = 0;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar10 + iVar5 * 2)) {
      iVar5 = iVar5 + 1;
    }
    else {
      sVar1 = FUN_022d8600(uVar6);
      if ((sVar1 != 0) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_022d9818;
    }
    uVar9 = uVar8;
  }
  uVar2 = 0x55;
  uVar8 = 0;
  do {
    FUN_022d862c(uVar8,uVar2);
    uVar2 = ~uVar2;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x69);
  iVar5 = 0;
  uVar2 = 0x55;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar10 + iVar5 * 2)) {
      iVar5 = iVar5 + 1;
    }
    else {
      uVar4 = FUN_022d8600(uVar6);
      if ((uVar4 != uVar2) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_022d9818;
    }
    uVar2 = ~uVar2 & 0xff;
    uVar9 = uVar8;
  }
  sVar1 = 0xff;
  uVar8 = 0;
  do {
    FUN_022d862c(uVar8,sVar1);
    sVar1 = sVar1 + -1;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x69);
  iVar5 = 0;
  sVar1 = 0xff;
  for (uVar6 = 0; uVar8 = uVar9, uVar6 < 0x69; uVar6 = uVar6 + 1) {
    if (uVar6 == *(ushort *)(iVar10 + iVar5 * 2)) {
      iVar5 = iVar5 + 1;
    }
    else {
      sVar3 = FUN_022d8600(uVar6);
      if ((sVar3 != sVar1) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_022d9818;
    }
    sVar1 = sVar1 + -1;
    uVar9 = uVar8;
  }
  iVar5 = 0;
  for (uVar9 = 0; uVar9 < 0x69; uVar9 = uVar9 + 1) {
    uVar6 = uVar8;
    if (uVar9 == *(ushort *)(iVar10 + iVar5 * 2)) {
      iVar5 = iVar5 + 1;
    }
    else {
      uVar2 = 1;
      for (uVar7 = 0; uVar7 < 9; uVar7 = uVar7 + 1) {
        FUN_022d862c(uVar9,uVar2);
        uVar4 = FUN_022d8600(uVar9);
        uVar8 = uVar6;
        if ((uVar4 != uVar2) && (uVar8 = uVar6 + 1, 0x20 < uVar6)) goto LAB_022d9818;
        uVar2 = (uVar2 & 0x7f) << 1;
        uVar6 = uVar8;
      }
    }
    uVar8 = uVar6;
  }
LAB_022d9818:
  if (uVar8 != 0) {
    *(ushort *)(*DAT_022d9840 + 0x33e) = *(ushort *)(*DAT_022d9840 + 0x33e) | 8;
  }
  return;
}

