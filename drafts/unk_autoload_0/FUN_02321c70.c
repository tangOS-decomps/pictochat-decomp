// decomp: module=unk_autoload_0 addr=0x02321c70 name=FUN_02321c70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x6e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=44
// verify:  python tools/match.py --c <file> --func FUN_02321c70 --addr 0x02321c70 --size 0x88 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321c70(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int local_30 [7];
  
  piVar5 = local_30;
  iVar3 = 3;
  puVar7 = DAT_02321ce0;
  do {
    uVar1 = *puVar7;
    uVar2 = puVar7[1];
    puVar7 = puVar7 + 2;
    *piVar5 = uVar1;
    piVar5[1] = uVar2;
    piVar5 = piVar5 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  do {
    iVar4 = local_30[iVar3];
    iVar6 = *(int *)(iVar4 + 0xc);
    puVar7 = (undefined4 *)(DAT_02321ce4 + iVar3 * 8);
    *(undefined4 *)(DAT_02321ce4 + iVar3 * 8) = 0;
    piVar5 = (int *)(iVar4 + 0x20);
    puVar7[1] = 0;
    for (iVar4 = 0; iVar4 < iVar6; iVar4 = iVar4 + 1) {
      if (*piVar5 == DAT_02321ce8) {
        *puVar7 = piVar5 + 4;
      }
      else if (*piVar5 == DAT_02321cec) {
        puVar7[1] = piVar5 + 2;
      }
      piVar5 = (int *)((int)piVar5 + piVar5[1]);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  *DAT_02321cf4 = *DAT_02321cf0 & 7;
  return;
}

