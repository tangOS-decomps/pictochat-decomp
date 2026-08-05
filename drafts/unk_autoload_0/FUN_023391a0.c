// decomp: module=unk_autoload_0 addr=0x023391a0 name=FUN_023391a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=32
// verify:  python tools/match.py --c <file> --func FUN_023391a0 --addr 0x023391a0 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_023391a0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_1c;
  undefined4 uStack_18;
  
  iVar1 = DAT_023391e8;
  uStack_18 = param_4;
  do {
    do {
      iVar3 = FUN_02339034();
      iVar2 = DAT_023391f0;
    } while (iVar3 != 0);
    iVar3 = 0;
    local_1c = DAT_023391e8;
    *(undefined4 *)(DAT_023391f0 + 0x30) = DAT_023391ec;
    *(int **)(iVar2 + 0x34) = &local_1c;
    puVar4 = param_1;
    if (0 < param_2) {
      do {
        FUN_02339454(*puVar4);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < param_2);
    }
    do {
    } while (local_1c == iVar1);
  } while (local_1c != 0);
  return;
}

