// decomp: module=arm7 addr=0x022cfdf8 name=FUN_022cfdf8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60, arm
// triage: noise=5 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022cfdf8 --addr 0x022cfdf8 --size 0x60 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022cfdf8(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 1;
  param_1[7] = 3;
  param_1[8] = param_2;
  param_1[9] = param_3;
  param_1[10] = param_4;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8();
  return param_1 + uVar1 + 8;
}

