// decomp: module=arm7 addr=0x022d054c name=FUN_022d054c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022d054c --addr 0x022d054c --size 0x74 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d054c(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = DAT_022d05bc;
  param_1[5] = 0;
  param_1[6] = (short)uVar2;
  param_1[7] = 0x10;
  func_0x037cb78c(param_2,param_1 + 8,0x20,param_4,param_4);
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8(param_1);
  return param_1 + uVar1 + 8;
}

