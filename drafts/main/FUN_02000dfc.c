// decomp: module=main addr=0x02000dfc name=FUN_02000dfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78, arm
// triage: noise=11 statements=37
// verify:  python tools/match.py --c <file> --func FUN_02000dfc --addr 0x02000dfc --size 0x78 --module main --version 2.0/sp1


void FUN_02000dfc(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  puVar1 = (undefined4 *)*DAT_02000e70;
  puVar3 = (undefined4 *)DAT_02000e70[1];
  puVar4 = (undefined4 *)DAT_02000e70[2];
  while (puVar1 != puVar3) {
    puVar7 = (undefined4 *)*puVar1;
    piVar2 = puVar1 + 2;
    iVar9 = puVar1[1];
    for (puVar5 = puVar7; (int)puVar5 - ((int)puVar7 + iVar9) < 0; puVar5 = puVar5 + 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    puVar1 = puVar1 + 3;
    puVar8 = (undefined4 *)((int)puVar5 + *piVar2);
    for (; puVar5 < puVar8; puVar5 = puVar5 + 1) {
      *puVar5 = 0;
    }
    uVar6 = (uint)puVar7 & 0xffffffe0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar6);
      coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar6);
      uVar6 = uVar6 + 0x20;
    } while ((int)uVar6 < (int)puVar8);
  }
  return;
}

