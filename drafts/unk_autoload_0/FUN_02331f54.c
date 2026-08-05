// decomp: module=unk_autoload_0 addr=0x02331f54 name=FUN_02331f54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x92 - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=50
// verify:  python tools/match.py --c <file> --func FUN_02331f54 --addr 0x02331f54 --size 0xa4 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331f54(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_r3;
  uint uVar4;
  code *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined8 uVar8;
  
  *DAT_02331fe8 = 0;
  FUN_023307f8(0x10);
  *(uint *)(DAT_02331fec + DAT_02331ff0) = *(uint *)(DAT_02331fec + DAT_02331ff0) | 0x10;
  uVar8 = FUN_02331ca8();
  iVar1 = DAT_02331ff4;
  uVar2 = (uint)((ulonglong)uVar8 >> 0x20);
  puVar6 = *(undefined4 **)(DAT_02331ff4 + 4);
  if (puVar6 != (undefined4 *)0x0) {
    uVar4 = puVar6[4];
    bVar7 = (uint)puVar6[3] <= (uint)uVar8;
    if (uVar2 <= uVar4 && (uint)bVar7 <= uVar2 - uVar4) {
      FUN_02331d1c(puVar6,(uVar2 - uVar4) - (uint)!bVar7);
      return;
    }
    iVar3 = puVar6[6];
    *(int *)(DAT_02331ff4 + 4) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + 8) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 0x14) = 0;
    }
    pcVar5 = (code *)*puVar6;
    if (puVar6[7] == 0 && puVar6[8] == 0) {
      *puVar6 = 0;
    }
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(puVar6[1]);
    }
    if (puVar6[7] != 0 || puVar6[8] != 0) {
      *puVar6 = pcVar5;
      FUN_02331ddc(puVar6,0,0,puVar6[7],in_r3);
    }
    if (*(int *)(DAT_02331ff4 + 4) != 0) {
      FUN_02331d1c();
    }
  }
  return;
}

