// decomp: module=main addr=0x02000d50 name=FUN_02000d50
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac, arm
// triage: noise=6 statements=57
// verify:  python tools/match.py --c <file> --func FUN_02000d50 --addr 0x02000d50 --size 0xac --module main --version 2.0/sp1


undefined4 FUN_02000d50(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  ushort *puVar7;
  byte *pbVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  
  if (param_1 != 0) {
    puVar5 = (undefined1 *)(param_1 + *(int *)(param_1 + -4));
    puVar7 = (ushort *)(param_1 - (*(uint *)(param_1 + -8) >> 0x18));
    uVar4 = param_1 - (*(uint *)(param_1 + -8) & 0xffffff);
    puVar6 = puVar5;
    while ((int)uVar4 < (int)puVar7) {
      puVar7 = (ushort *)((int)puVar7 + -1);
      bVar9 = *(byte *)puVar7;
      iVar10 = 8;
      while (0 < iVar10) {
        if ((bVar9 & 0x80) == 0) {
          puVar7 = (ushort *)((int)puVar7 + -1);
          puVar6 = puVar6 + -1;
          *puVar6 = *(undefined1 *)puVar7;
        }
        else {
          pbVar8 = (byte *)((int)puVar7 + -1);
          puVar7 = puVar7 + -1;
          uVar3 = *puVar7;
          iVar11 = *pbVar8 + 0x20;
          do {
            puVar2 = puVar6 + (uVar3 & 0xffff0fff) + 2;
            puVar6 = puVar6 + -1;
            *puVar6 = *puVar2;
            bVar1 = 0xf < iVar11;
            iVar11 = iVar11 + -0x10;
          } while (bVar1);
        }
        bVar9 = bVar9 << 1;
        iVar10 = iVar10 + -1;
        if ((int)puVar7 <= (int)uVar4) goto LAB_02000dd4;
      }
    }
LAB_02000dd4:
    uVar4 = uVar4 & 0xffffffe0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar4);
      coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar4);
      uVar4 = uVar4 + 0x20;
    } while ((int)uVar4 < (int)puVar5);
  }
  return 0;
}

