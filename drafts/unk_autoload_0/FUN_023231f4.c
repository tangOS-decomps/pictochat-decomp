// decomp: module=unk_autoload_0 addr=0x023231f4 name=FUN_023231f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf4 (Ghidra's cache says 0xee - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=45
// verify:  python tools/match.py --c <file> --func FUN_023231f4 --addr 0x023231f4 --size 0xf4 --module unk_autoload_0 --version 2.0/sp1


void FUN_023231f4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined1 auStack_24 [16];
  
  piVar5 = FUN_02321c60();
  uVar1 = *(ushort *)((int)piVar5 + 0x16);
  piVar5 = *(int **)(param_1 + 8);
  FUN_023374b8(piVar5[1],DAT_023232e4,0x2280);
  piVar6 = FUN_02321c58();
  FUN_0232db10(auStack_24,DAT_023232e4,200,0x58,0,piVar6);
  piVar6 = *(int **)(param_1 + 8);
  for (uVar11 = 0; uVar11 < *(ushort *)((int)piVar6 + 0xe); uVar11 = uVar11 + 1 & 0xffff) {
    if (*(ushort *)(piVar6 + 3) + 1 == (uint)*(ushort *)(*piVar6 + uVar11 * 8 + 6))
    goto LAB_02323252;
  }
  uVar11 = 0;
LAB_02323252:
  for (iVar10 = 0; iVar10 < (int)(*(ushort *)((int)piVar5 + 0xe) - uVar11); iVar10 = iVar10 + 1) {
    iVar12 = *piVar5;
    iVar7 = (uVar11 + iVar10) * 8;
    uVar3 = *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar10 * 2);
    piVar6 = FUN_02321c60();
    iVar8 = FUN_0232de60(piVar6,uVar3);
    piVar6 = FUN_02321c60();
    iVar9 = FUN_0232df14(piVar6,uVar3);
    uVar2 = *(ushort *)(iVar12 + iVar7 + 2);
    uVar4 = *(ushort *)(iVar12 + iVar7);
    piVar6 = FUN_02321c60();
    FUN_0232dc5c(piVar6,auStack_24,(((uVar4 & 0xff) + ((uVar2 & 0xff) >> 1)) - iVar8 / 2) - iVar9,
                 ((uint)(*(ushort *)(iVar12 + iVar7) >> 8) +
                 (uint)(*(ushort *)(iVar12 + iVar7 + 2) >> 9)) - (uVar1 & 0x3ff) / 0x40,uVar3,7);
  }
  return;
}

