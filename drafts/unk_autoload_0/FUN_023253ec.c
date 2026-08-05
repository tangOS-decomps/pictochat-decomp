// decomp: module=unk_autoload_0 addr=0x023253ec name=FUN_023253ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=8
// verify:  python tools/match.py --c <file> --func FUN_023253ec --addr 0x023253ec --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_023253ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int extraout_r1;
  
  uVar1 = FUN_02335e0c(*(undefined1 *)(param_1 + DAT_02325404),6,param_3,param_4,param_4);
  FUN_02335e0c(uVar1,0xd);
  return extraout_r1 + 3;
}

