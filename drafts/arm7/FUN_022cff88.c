// decomp: module=arm7 addr=0x022cff88 name=FUN_022cff88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80, arm
// triage: noise=5 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022cff88 --addr 0x022cff88 --size 0x80 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022cff88(undefined2 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 4;
  param_1[7] = 5;
  func_0x037cb78c(param_2,param_1 + 8,6);
  param_1[0xb] = param_3;
  param_1[0xc] = param_4;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 6;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

