// decomp: module=unk_autoload_0 addr=0x02337a28 name=FUN_02337a28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=53
// verify:  python tools/match.py --c <file> --func FUN_02337a28 --addr 0x02337a28 --size 0xa8 --module unk_autoload_0 --version 2.0/sp1


int * FUN_02337a28(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  uVar2 = FUN_02332080();
  if ((param_1 & 1) == 0) {
    iVar3 = FUN_02337eec();
    if (DAT_02337ac8[1] == iVar3) {
      FUN_02332094(uVar2);
      return (int *)0x0;
    }
  }
  else {
    iVar3 = FUN_02337eec();
    puVar1 = DAT_02337ac8;
    if (DAT_02337ac8[1] == iVar3) {
      do {
        FUN_02332094(uVar2);
        FUN_023320fc(0x32);
        uVar2 = FUN_02332080();
        iVar3 = FUN_02337eec();
      } while (puVar1[1] == iVar3);
    }
  }
  puVar1 = DAT_02337ac8;
  piVar5 = *(int **)(DAT_02337acc + DAT_02337ac8[5] * 4);
  iVar3 = DAT_02337ac8[5] + 1;
  DAT_02337ac8[5] = iVar3;
  if (8 < iVar3) {
    puVar1[5] = 0;
  }
  iVar3 = *piVar5;
  piVar4 = piVar5;
  while (iVar3 != 0) {
    piVar4 = (int *)*piVar4;
    iVar3 = *piVar4;
  }
  if ((undefined4 *)DAT_02337ac8[4] == (undefined4 *)0x0) {
    *DAT_02337ac8 = piVar5;
  }
  else {
    *(undefined4 *)DAT_02337ac8[4] = piVar5;
  }
  puVar1 = DAT_02337ac8;
  DAT_02337ac8[4] = piVar4;
  puVar1[7] = puVar1[7] + -1;
  puVar1[1] = puVar1[1] + 1;
  FUN_02332094(uVar2);
  return piVar5;
}

