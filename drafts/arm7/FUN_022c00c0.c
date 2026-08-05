// decomp: module=arm7 addr=0x022c00c0 name=FUN_022c00c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, arm
// triage: noise=10 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022c00c0 --addr 0x022c00c0 --size 0x58 --module arm7 --version 2.0/sp1


void FUN_022c00c0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar1 = (undefined4 *)*DAT_022c0114;
  puVar3 = (undefined4 *)DAT_022c0114[1];
  puVar4 = (undefined4 *)DAT_022c0114[2];
  do {
    if (puVar1 == puVar3) {
      return;
    }
    puVar5 = (undefined4 *)*puVar1;
    piVar2 = puVar1 + 2;
    iVar6 = (int)puVar5 + puVar1[1];
    for (; (int)puVar5 - iVar6 < 0; puVar5 = puVar5 + 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
    }
    puVar1 = puVar1 + 3;
    puVar7 = (undefined4 *)((int)puVar5 + *piVar2);
    for (; puVar5 < puVar7; puVar5 = puVar5 + 1) {
      *puVar5 = 0;
    }
  } while (puVar5 == puVar7);
  return;
}

