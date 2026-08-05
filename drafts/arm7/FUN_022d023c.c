// decomp: module=arm7 addr=0x022d023c name=FUN_022d023c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac, arm
// triage: noise=17 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022d023c --addr 0x022d023c --size 0xac --module arm7 --version 2.0/sp1


undefined2 * FUN_022d023c(undefined2 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x100;
  param_1[7] = 0x18;
  func_0x037cb78c(param_2,param_1 + 8,0x30,param_4,param_4);
  *(undefined2 *)(param_2 + 2) = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined2 *)(param_2 + 8) = 0;
  *(undefined2 *)(param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  *(undefined2 *)(param_2 + 0x10) = 0;
  *(undefined2 *)(param_2 + 0x12) = 0;
  *(undefined2 *)(param_2 + 0x14) = 0;
  *(undefined2 *)(param_2 + 0x16) = 0;
  *(undefined2 *)(param_2 + 0x24) = 0;
  *(undefined2 *)(param_2 + 0x26) = 0;
  *(undefined2 *)(param_2 + 0x28) = 0;
  *(undefined2 *)(param_2 + 0x2a) = 0;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 2;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

