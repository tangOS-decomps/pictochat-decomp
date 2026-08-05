// decomp: module=arm7 addr=0x022d0008 name=FUN_022d0008
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78, arm
// triage: noise=5 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022d0008 --addr 0x022d0008 --size 0x78 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d0008(undefined2 *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 5;
  param_1[7] = 4;
  func_0x037cb78c(param_2,param_1 + 8,6,4,param_4);
  param_1[0xb] = param_3;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 4;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

