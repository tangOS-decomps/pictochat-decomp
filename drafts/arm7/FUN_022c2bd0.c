// decomp: module=arm7 addr=0x022c2bd0 name=FUN_022c2bd0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x270 (Ghidra's cache says 0x254 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=101
// verify:  python tools/match.py --c <file> --func FUN_022c2bd0 --addr 0x022c2bd0 --size 0x270 --module arm7 --version 2.0/sp1


void FUN_022c2bd0(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  undefined2 *puVar5;
  int iVar6;
  ushort *puVar7;
  short *psVar8;
  short *psVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  
  puVar5 = DAT_022c2e28;
  piVar4 = DAT_022c2e24;
  iVar12 = *DAT_022c2e24;
  *DAT_022c2e28 = 0x40;
  if ((*(ushort *)(*piVar4 + 0x690) & 0x20) == 0) {
    return;
  }
  uVar11 = (uint)*(ushort *)(iVar12 + 0x4d0);
  bVar14 = uVar11 == DAT_022c2e2c;
  if (bVar14) {
    uVar11 = (ushort)puVar5[0xc6] & 3;
  }
  if (!bVar14 || uVar11 != 3) {
    return;
  }
  if ((uint)(ushort)puVar5[300] < (DAT_022c2e2c - 0xf000 & (uint)((ushort)puVar5[0x20] >> 1))) {
    return;
  }
  uVar11 = (uint)(ushort)puVar5[0x22];
  iVar6 = FUN_022c2f70(uVar11 * 2 + 0x4804008);
  puVar7 = (ushort *)FUN_022c2f70(iVar6 + 4);
  if ((*puVar7 & DAT_022c2e30) != 0x228) {
    return;
  }
  iVar6 = FUN_022c2f70(puVar7 + 1);
  sVar1 = *DAT_022c2e34;
  while( true ) {
    uVar13 = (ushort)DAT_022c2e34[0xb8] - uVar11 & 0xffff;
    if (((ushort)DAT_022c2e34[0xb8] - uVar11 & 0x8000) != 0) {
      uVar13 = uVar13 + (*(ushort *)(iVar12 + 0x3de) >> 1) & 0xffff;
    }
    if (0xe < uVar13) break;
    if (0x40 < (ushort)(*DAT_022c2e34 - sVar1)) {
      return;
    }
  }
  psVar8 = (short *)(iVar6 + 8);
  for (uVar13 = 0; uVar13 < 3; uVar13 = uVar13 + 1) {
    psVar9 = (short *)FUN_022c2f70(psVar8);
    psVar8 = psVar9 + 1;
    if (*psVar9 != *(short *)(iVar12 + uVar13 * 2 + 0x3a8)) {
      return;
    }
  }
  puVar10 = (ushort *)FUN_022c2f70(psVar8 + 5);
  puVar7 = DAT_022c2e38;
  while( true ) {
    uVar13 = (ushort)DAT_022c2e34[0xb8] - uVar11 & 0xffff;
    if (((ushort)DAT_022c2e34[0xb8] - uVar11 & 0x8000) != 0) {
      uVar13 = uVar13 + (*(ushort *)(iVar12 + 0x3de) >> 1) & 0xffff;
    }
    if (0x14 < uVar13) break;
    if (0x70 < (ushort)(*DAT_022c2e34 - sVar1)) {
      return;
    }
  }
  if (((uint)*puVar10 & 1 << (*DAT_022c2e38 & 0xff)) != 0) {
    return;
  }
  *(ushort *)(iVar12 + 0x4d0) = DAT_022c2e38[0x38];
  puVar7[0x46] = 0x40;
  *(short *)(iVar12 + 0x402) = *(short *)(iVar12 + 0x402) + 1;
  puVar10 = DAT_022c2e3c;
  do {
  } while ((puVar7[0xba] & 3) == 3);
  puVar7 = DAT_022c2e3c + -0xe;
  *DAT_022c2e3c = *DAT_022c2e3c | 0x40;
  piVar4 = DAT_022c2e24;
  *puVar10 = *puVar10 & 0xffbf;
  *puVar7 = 8;
  *puVar7 = 0;
  uVar11 = DAT_022c2e2c;
  iVar12 = *piVar4;
  uVar2 = *(ushort *)(iVar12 + 0x4d0);
  if (uVar2 == DAT_022c2e2c) {
    return;
  }
  puVar7 = puVar10 + -0xd8;
  uVar3 = *puVar7;
  *puVar7 = uVar2;
  puVar10[-0x10a] = puVar10[-0x10a] | 0x80;
  *puVar7 = uVar3;
  *(short *)(iVar12 + 0x4d0) = (short)uVar11;
  return;
}

