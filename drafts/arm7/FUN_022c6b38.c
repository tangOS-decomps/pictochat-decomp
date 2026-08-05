// decomp: module=arm7 addr=0x022c6b38 name=FUN_022c6b38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1b0 (Ghidra's cache says 0x1a0 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=78
// verify:  python tools/match.py --c <file> --func FUN_022c6b38 --addr 0x022c6b38 --size 0x1b0 --module arm7 --version 2.0/sp1


void FUN_022c6b38(void)

{
  ushort *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  uint uVar8;
  code *pcVar9;
  bool bVar10;
  
  FUN_022c48a4(4);
  puVar2 = DAT_022c6cdc;
  puVar1 = DAT_022c6cd8;
  *DAT_022c6cd8 = *DAT_022c6cd8 & 0xffdf;
  *puVar2 = *puVar2 | 4;
  FUN_022c6ce8(((int)(uint)*puVar1 >> 8 | (*puVar1 & 0x80) << 1) - 1);
  iVar3 = DAT_022c6ce4;
  puVar1 = DAT_022c6ce0;
  puVar7 = DAT_022c6ce0 + -1;
  do {
    while( true ) {
      puVar6 = *(undefined4 **)(iVar3 + 0xc);
      if (puVar6 == (undefined4 *)0x0) {
        return;
      }
      uVar8 = (uint)*puVar1;
      uVar4 = FUN_022c6ce8(uVar8);
      iVar5 = uVar8 - (int)*(short *)(puVar6 + 4);
      if (((int)(uVar4 - puVar6[3]) < 0) || ((uVar4 == puVar6[3] && (iVar5 < 0)))) {
        iVar5 = 0;
      }
      else {
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0x107;
        }
        if (*(short *)((int)puVar6 + 0x12) < iVar5) {
          iVar5 = 2;
        }
        else {
          iVar5 = 1;
        }
      }
      if (iVar5 != 0) break;
      FUN_022c69f8(puVar6);
      uVar8 = (uint)*(short *)(puVar6 + 4);
      bVar10 = uVar8 != *puVar1;
      if (!bVar10) {
        uVar8 = puVar6[3];
      }
      if (bVar10 || uVar8 != uVar4) {
        return;
      }
      FUN_022c48a4(4);
      *puVar7 = *puVar7 & 0xffdf;
      FUN_022c48e0(4);
LAB_022c6c50:
      pcVar9 = (code *)*puVar6;
      FUN_022c688c(puVar6);
      *puVar6 = 0;
      if (pcVar9 != (code *)0x0) {
        (*pcVar9)(puVar6[1]);
      }
      if ((puVar6[7] != 0) && (puVar6[9] == 0)) {
        *puVar6 = pcVar9;
        puVar6[3] = *(int *)(iVar3 + 8) + 1;
        FUN_022c67e8(puVar6);
      }
    }
    if (iVar5 == 1) goto LAB_022c6c50;
    if (iVar5 == 2) {
      FUN_022c688c(puVar6);
      puVar6[3] = *(int *)(iVar3 + 8) + 1;
      FUN_022c67e8(puVar6);
    }
  } while( true );
}

