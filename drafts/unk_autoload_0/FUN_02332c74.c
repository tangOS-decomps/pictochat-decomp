// decomp: module=unk_autoload_0 addr=0x02332c74 name=FUN_02332c74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=15 statements=46
// verify:  python tools/match.py --c <file> --func FUN_02332c74 --addr 0x02332c74 --size 0x98 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332c74(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code **ppcVar5;
  undefined4 *puVar6;
  code *local_38 [9];
  
  while( true ) {
    FUN_023374f0(local_38,0,0x24);
    uVar1 = FUN_02332080();
    iVar2 = *(int *)(param_1 + 0xc0);
    while (iVar2 == 0) {
      FUN_02330f38(0);
      iVar2 = *(int *)(param_1 + 0xc0);
    }
    puVar6 = *(undefined4 **)(param_1 + 0xc0);
    iVar2 = 4;
    ppcVar5 = local_38;
    do {
      uVar3 = *puVar6;
      uVar4 = puVar6[1];
      puVar6 = puVar6 + 2;
      *ppcVar5 = (code *)uVar3;
      ppcVar5[1] = (code *)uVar4;
      ppcVar5 = ppcVar5 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *ppcVar5 = (code *)*puVar6;
    FUN_02332094(uVar1);
    if (local_38[0] != (code *)0x0) {
      local_38[2] = (code *)(*local_38[0])(local_38);
    }
    uVar1 = FUN_02332080();
    *(undefined1 *)(DAT_02332d04 + 6) = 0;
    if (local_38[1] != (code *)0x0) {
      (*local_38[1])(local_38);
    }
    if (*DAT_02332d08 == 0) break;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    FUN_02332094(uVar1);
  }
  FUN_02330e78();
  return;
}

