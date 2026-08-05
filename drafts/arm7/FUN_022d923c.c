// decomp: module=arm7 addr=0x022d923c name=FUN_022d923c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a4 (Ghidra's cache says 0x194 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=60  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d923c --addr 0x022d923c --size 0x1a4 --module arm7 --version 2.0/sp1


void FUN_022d923c(void)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar2 = DAT_022d93d4;
  iVar1 = DAT_022d93d0;
  uVar9 = 0;
  for (uVar7 = 0; iVar6 = DAT_022d93d0, uVar7 < 3; uVar7 = uVar7 + 1) {
    uVar4 = *(ushort *)(iVar2 + uVar7 * 2);
    for (uVar8 = 0; uVar8 < 0x1b; uVar8 = uVar8 + 1) {
      uVar3 = *(ushort *)(iVar1 + uVar8 * 4);
      uVar5 = uVar4 & *(ushort *)(iVar1 + uVar8 * 4 + 2);
      *(ushort *)(&DAT_04808000 + uVar3) = uVar5;
      uVar10 = uVar9;
      if ((*(ushort *)(&DAT_04808000 + uVar3) != uVar5) && (uVar10 = uVar9 + 1, 0x20 < uVar9))
      goto LAB_022d93a8;
      uVar9 = uVar10;
    }
  }
  uVar8 = 0;
  uVar7 = DAT_022d93d8;
  do {
    iVar1 = uVar8 * 4;
    iVar2 = uVar8 * 4;
    uVar8 = uVar8 + 1;
    *(ushort *)(&DAT_04808000 + *(ushort *)(iVar6 + iVar1)) =
         (ushort)uVar7 & *(ushort *)(iVar6 + iVar2 + 2);
    iVar1 = DAT_022d93d0;
    uVar7 = uVar7 + 0x1234 & 0xffff;
  } while (uVar8 < 0x1b);
  uVar7 = DAT_022d93d8;
  for (uVar8 = 0; uVar8 < 0x1b; uVar8 = uVar8 + 1) {
    uVar10 = uVar9;
    if (((uint)*(ushort *)(&DAT_04808000 + *(ushort *)(DAT_022d93d0 + uVar8 * 4)) !=
         (uVar7 & *(ushort *)(DAT_022d93d0 + uVar8 * 4 + 2))) && (uVar10 = uVar9 + 1, 0x20 < uVar9))
    goto LAB_022d93a8;
    uVar7 = uVar7 + 0x1234 & 0xffff;
    uVar9 = uVar10;
  }
  uVar7 = 0;
  while ((uVar10 = uVar9, uVar7 < 0x1b &&
         ((uVar4 = *(ushort *)(iVar1 + uVar7 * 4), *(short *)(&DAT_04808000 + uVar4) = 0,
          *(short *)(&DAT_04808000 + uVar4) == 0 || (uVar10 = uVar9 + 1, uVar9 < 0x21))))) {
    uVar7 = uVar7 + 1;
    uVar9 = uVar10;
  }
LAB_022d93a8:
  if (uVar10 != 0) {
    *(ushort *)(*DAT_022d93dc + 0x33e) = *(ushort *)(*DAT_022d93dc + 0x33e) | 1;
  }
  return;
}

