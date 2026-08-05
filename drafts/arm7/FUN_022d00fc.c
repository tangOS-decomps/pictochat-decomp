// decomp: module=arm7 addr=0x022d00fc name=FUN_022d00fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0, arm
// triage: noise=10 statements=29
// verify:  python tools/match.py --c <file> --func FUN_022d00fc --addr 0x022d00fc --size 0xc0 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d00fc(undefined2 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
            ushort param_9,undefined4 param_10)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 9;
  param_1[7] = (short)((param_9 + 1) / 2) + 0x17;
  param_1[8] = param_2;
  func_0x037cb78c(param_3,param_1 + 9,0x20,param_4,param_4);
  param_1[0x19] = (short)param_4;
  param_1[0x1a] = param_5;
  param_1[0x1b] = param_6;
  param_1[0x1c] = param_7;
  param_1[0x1d] = param_8;
  param_1[0x1e] = param_9;
  func_0x037cb78c(param_10,param_1 + 0x1f);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

