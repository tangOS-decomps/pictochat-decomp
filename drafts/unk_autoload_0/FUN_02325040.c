// decomp: module=unk_autoload_0 addr=0x02325040 name=FUN_02325040
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x13c (Ghidra's cache says 0x122 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=52
// verify:  python tools/match.py --c <file> --func FUN_02325040 --addr 0x02325040 --size 0x13c --module unk_autoload_0 --version 2.0/sp1


void FUN_02325040(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_023272c8();
  FUN_023210c8(PTR_DAT_02325168,0,*(undefined4 *)(PTR_DAT_02325164 + 0x18),0,0);
  FUN_0232228c();
  FUN_02321e70();
  uVar2 = FUN_02320c7c();
  FUN_02320eac(uVar2,PTR_DAT_0232516c,PTR_DAT_02325170,0xc,0,
               *(int *)(PTR_DAT_02325164 + 0x10) +
               (*(int *)(PTR_DAT_02325164 + 0x34) + 0x800 >> 0xc),1);
  puVar1 = PTR_DAT_02325174;
  iVar5 = 0;
  do {
    iVar6 = iVar5 * 0x8c;
    iVar3 = FUN_023213d8((undefined4 *)PTR_DAT_02325178,*(int *)(puVar1 + iVar6 + 0x80));
    if (iVar3 == -1) {
      uVar2 = 2;
    }
    else if (iVar3 == 1) {
      uVar2 = 3;
    }
    else if (iVar3 == 2) {
      uVar2 = 4;
    }
    else {
      uVar2 = 2;
    }
    FUN_023210c8(puVar1 + iVar6,0,*(undefined4 *)(PTR_DAT_02325164 + 0x10),0,1);
    iVar3 = *(int *)(puVar1 + iVar6 + 0x88);
    if (iVar3 != 0) {
      uVar4 = FUN_02320c7c();
      FUN_02320eac(uVar4,PTR_DAT_0232516c,PTR_DAT_02325170,iVar3,0,
                   *(int *)(PTR_DAT_02325164 + 0x10) + iVar5 * 0x20,1);
    }
    FUN_023210c8(puVar1 + iVar6 + 0x40,0,*(undefined4 *)(PTR_DAT_02325164 + 0x10),0,1);
    uVar4 = FUN_02320c7c();
    FUN_02320ed4(uVar4,PTR_DAT_0232516c,PTR_DAT_02325170,*(undefined4 *)(puVar1 + iVar6 + 0x84),0,
                 *(undefined4 *)(PTR_DAT_02325164 + 0x10),uVar2,1);
    uVar4 = FUN_02320c7c();
    FUN_02320ed4(uVar4,PTR_DAT_0232516c,PTR_DAT_02325170,0,0,
                 *(int *)(PTR_DAT_02325164 + 0x10) + iVar5 * 0x20,uVar2,1);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  FUN_02326c9c();
  return;
}

