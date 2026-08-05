// decomp: module=unk_autoload_0 addr=0x02325910 name=FUN_02325910
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02325910 --addr 0x02325910 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325910(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_0233746c(0,param_1 + 0x56,DAT_02325958);
  FUN_0233746c(0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x44));
  *(undefined2 *)(param_1 + 0x158) = param_2;
  iVar1 = 1;
  do {
    iVar2 = iVar1 * 0x104;
    iVar1 = iVar1 + 1;
    *(undefined2 *)(param_1 + iVar2 + 0x158) = 3;
    iVar2 = DAT_0232595c;
  } while (iVar1 < 5);
  *(undefined2 *)(param_1 + DAT_0232595c) = 0;
  *(undefined2 *)(param_1 + iVar2 + 2) = param_3;
  return;
}

