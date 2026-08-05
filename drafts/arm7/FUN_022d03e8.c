// decomp: module=arm7 addr=0x022d03e8 name=FUN_022d03e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, arm
// triage: noise=3 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022d03e8 --addr 0x022d03e8 --size 0x58 --module arm7 --version 2.0/sp1


undefined2 * FUN_022d03e8(undefined2 *param_1,undefined2 param_2)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x104;
  param_1[7] = 1;
  param_1[8] = param_2;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8();
  return param_1 + uVar1 + 8;
}

