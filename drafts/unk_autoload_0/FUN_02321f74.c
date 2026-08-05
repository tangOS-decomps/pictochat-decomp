// decomp: module=unk_autoload_0 addr=0x02321f74 name=FUN_02321f74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02321f74 --addr 0x02321f74 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321f74(undefined4 param_1,int param_2)

{
  int iVar1;
  
  FUN_02322524();
  FUN_02321df4();
  iVar1 = DAT_02321f98;
  *(undefined4 *)(DAT_02321f98 + 0x14) = param_1;
  *(int *)(iVar1 + 0x18) = param_2;
  if (param_2 == 2) {
    *(undefined4 *)(iVar1 + 4) = 0xfffffff2;
    *(undefined4 *)(iVar1 + 8) = 8;
  }
  return;
}

