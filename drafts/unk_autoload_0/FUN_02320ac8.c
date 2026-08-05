// decomp: module=unk_autoload_0 addr=0x02320ac8 name=FUN_02320ac8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02320ac8 --addr 0x02320ac8 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320ac8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_02320af4;
  iVar4 = 0;
  iVar2 = DAT_02320af4 + 4;
  do {
    iVar3 = param_1 + iVar4 * 8;
    *(undefined4 *)(iVar3 + iVar1) = 0;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar3 + iVar2) = 0;
    iVar3 = DAT_02320af8;
  } while (iVar4 < 4);
  *(undefined4 *)(param_1 + DAT_02320af8) = 0;
  *(undefined4 *)(param_1 + iVar3 + 4) = 0;
  *(undefined4 *)(param_1 + iVar3 + -0x28) = 0;
  *(undefined4 *)(param_1 + iVar3 + -0x24) = 0;
  return;
}

