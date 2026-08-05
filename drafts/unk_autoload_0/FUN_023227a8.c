// decomp: module=unk_autoload_0 addr=0x023227a8 name=FUN_023227a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=14
// verify:  python tools/match.py --c <file> --func FUN_023227a8 --addr 0x023227a8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


undefined2 *
FUN_023227a8(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int extraout_r1;
  int extraout_r1_00;
  
  uVar1 = FUN_02335e0c(param_2,10,param_3,param_4,param_4);
  FUN_02335e0c(uVar1,10);
  *param_1 = *(undefined2 *)(DAT_023227dc + extraout_r1 * 2);
  FUN_02335e0c(param_2,10);
  param_1[1] = *(undefined2 *)(DAT_023227dc + extraout_r1_00 * 2);
  param_1[2] = 0;
  return param_1 + 2;
}

