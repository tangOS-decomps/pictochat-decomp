// decomp: module=arm7 addr=0x022c6698 name=FUN_022c6698
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf4 (Ghidra's cache says 0xe8 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=51
// verify:  python tools/match.py --c <file> --func FUN_022c6698 --addr 0x022c6698 --size 0xf4 --module arm7 --version 2.0/sp1


void FUN_022c6698(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  bool bVar6;
  undefined8 uVar7;
  
  *DAT_022c6780 = 0;
  FUN_022c48a4(0x10);
  *DAT_022c6784 = *DAT_022c6784 | 0x10;
  uVar7 = FUN_022c625c();
  iVar1 = DAT_022c6788;
  uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
  puVar4 = *(undefined4 **)(DAT_022c6788 + 4);
  if (puVar4 != (undefined4 *)0x0) {
    bVar6 = (uint)puVar4[4] <= uVar2;
    if (uVar2 == puVar4[4]) {
      bVar6 = (uint)puVar4[3] <= (uint)uVar7;
    }
    if (bVar6) {
      iVar3 = puVar4[6];
      *(int *)(DAT_022c6788 + 4) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 0x14) = 0;
      }
      pcVar5 = (code *)*puVar4;
      if (puVar4[8] == 0 && puVar4[7] == 0) {
        *puVar4 = 0;
      }
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(puVar4[1]);
      }
      if (puVar4[8] != 0 || puVar4[7] != 0) {
        *puVar4 = pcVar5;
        FUN_022c63f0(puVar4,0,0);
      }
      if (*(int *)(DAT_022c6788 + 4) != 0) {
        FUN_022c6300();
      }
    }
    else {
      FUN_022c6300(puVar4);
    }
  }
  return;
}

