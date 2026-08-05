// decomp: module=arm7 addr=0x022c2024 name=FUN_022c2024
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x110 (Ghidra's cache says 0x104 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=44
// verify:  python tools/match.py --c <file> --func FUN_022c2024 --addr 0x022c2024 --size 0x110 --module arm7 --version 2.0/sp1


void FUN_022c2024(void)

{
  short sVar1;
  undefined2 *puVar2;
  int *piVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  bool bVar9;
  
  piVar3 = DAT_022c212c;
  puVar2 = DAT_022c2128;
  *DAT_022c2128 = 8;
  if (((int)((uint)*(ushort *)(*piVar3 + 0x33a) << 0x1b) < 0) && ((puVar2[0xc6] & 1) == 0)) {
    puVar5 = puVar2 + 0x140;
    *puVar5 = *puVar5 ^ 1;
  }
  puVar2 = DAT_022c2130;
  iVar6 = *DAT_022c212c;
  if ((*(ushort *)(iVar6 + 0x690) & 8) != 0) {
    uVar7 = 0;
    do {
      if (((*(short *)(iVar6 + 0x42c + uVar7 * 0x14) != 0) &&
          (iVar4 = *(int *)(iVar6 + 0x42c + uVar7 * 0x14 + 8),
          (*(ushort *)(iVar4 + 0xc) & 0x4000) != 0)) && ((*(ushort *)(iVar4 + 4) & 0xff) != 0)) {
        psVar8 = (short *)(iVar4 + (uint)*(ushort *)(iVar4 + 10) + 5 & 0xfffffffe);
        sVar1 = *psVar8;
        bVar9 = sVar1 == 0;
        if (bVar9) {
          sVar1 = psVar8[1];
        }
        if (bVar9 && sVar1 == 0) {
          *(undefined2 *)(iVar4 + 4) = 0;
          *puVar2 = 0;
          *puVar2 = 0x8000;
          *(short *)(iVar6 + 0x3fe) = *(short *)(iVar6 + 0x3fe) + 1;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 3);
  }
  return;
}

