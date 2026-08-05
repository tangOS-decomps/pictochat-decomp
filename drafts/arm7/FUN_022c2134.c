// decomp: module=arm7 addr=0x022c2134 name=FUN_022c2134
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x17c (Ghidra's cache says 0x160 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=66
// verify:  python tools/match.py --c <file> --func FUN_022c2134 --addr 0x022c2134 --size 0x17c --module arm7 --version 2.0/sp1


void FUN_022c2134(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  puVar4 = DAT_022c2298;
  piVar3 = DAT_022c2294;
  iVar7 = *DAT_022c2294;
  *DAT_022c2298 = 4;
  puVar5 = DAT_022c22a0;
  uVar8 = iVar7 + 0x2c;
  uVar1 = puVar4[0xcc];
  if (((*(ushort *)(*piVar3 + 0x690) & 8) != 0) && ((uVar1 & 0x400) != 0)) {
    uVar2 = puVar4[0x50];
    bVar9 = (uVar2 & 1) != 0;
    if (bVar9) {
      uVar8 = (uint)*(ushort *)(iVar7 + 0x42c);
    }
    if (!bVar9 || uVar8 == 0) {
      bVar9 = (uVar2 & 4) != 0;
      if (bVar9) {
        uVar8 = (uint)*(ushort *)(iVar7 + 0x440);
      }
      if (!bVar9 || uVar8 == 0) {
        bVar9 = (uVar2 & 8) != 0;
        if (bVar9) {
          uVar8 = (uint)*(ushort *)(iVar7 + 0x454);
        }
        if ((!bVar9 || uVar8 == 0) && ((*DAT_022c229c & 1) == 0)) {
          *DAT_022c22a0 = 0;
          *puVar5 = 0x8000;
          *(undefined2 *)(iVar7 + 0x4de) = 0;
          goto LAB_022c2224;
        }
      }
    }
    uVar2 = *(ushort *)(iVar7 + 0x4de);
    *(ushort *)(iVar7 + 0x4de) = uVar2 + 1;
    puVar4 = DAT_022c22a0;
    if (0xc < uVar2) {
      *(undefined2 *)(iVar7 + 0x4de) = 0;
      *puVar4 = 0;
      piVar3 = DAT_022c2294;
      *puVar4 = 0x8000;
      *(short *)(*piVar3 + 0x3fe) = *(short *)(*piVar3 + 0x3fe) + 1;
    }
  }
LAB_022c2224:
  uVar6 = DAT_022c22ac;
  puVar4 = DAT_022c22a8;
  if (((*(ushort *)(*DAT_022c2294 + 0x690) & 1) != 0) && ((uVar1 & 0x60) != 0)) {
    if (((int)(DAT_022c22a4[-1] - 0x4000) / 2 <= (int)(uint)*DAT_022c22a4) ||
       ((int)(uint)*DAT_022c22a4 < (int)(DAT_022c22a4[-2] - 0x4000) / 2)) {
      DAT_022c22a8[-2] = *DAT_022c22a8;
      puVar4[-0x15] = (short)uVar6;
    }
    func_0x00dd47ac();
  }
  return;
}

