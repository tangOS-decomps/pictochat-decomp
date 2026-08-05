// decomp: module=arm7 addr=0x022d01bc name=FUN_022d01bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80, arm
// triage: noise=6 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022d01bc --addr 0x022d01bc --size 0x80 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d01bc(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
            undefined4 param_5)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 10;
  param_1[7] = 0xc;
  param_1[8] = 0;
  param_1[9] = param_2;
  param_1[10] = param_3;
  param_1[0xb] = (short)param_4;
  func_0x037cb78c(param_5,param_1 + 0xc,0x10,param_4,param_4);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 0x12;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

