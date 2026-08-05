// decomp: module=arm7 addr=0x022cfe58 name=FUN_022cfe58
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8, arm
// triage: noise=8 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022cfe58 --addr 0x022cfe58 --size 0xb8 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022cfe58(undefined2 *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined2 param_8)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 2;
  param_1[7] = 0x1f;
  func_0x037cb78c(param_3,param_1 + 8,6,param_4,param_4);
  param_1[0xb] = (short)param_4;
  func_0x037cb78c(param_5,param_1 + 0xc,0x20);
  param_1[0x1c] = param_6;
  func_0x037cb78c(param_7,param_1 + 0x1d,0x10);
  param_1[0x25] = param_8;
  param_1[0x26] = 0;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = (short)(param_2 >> 1) + -0x2c;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

