// decomp: module=arm7 addr=0x022d07f4 name=FUN_022d07f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84 (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022d07f4 --addr 0x022d07f4 --size 0x84 --module arm7 --version 2.0/sp1


undefined2 * FUN_022d07f4(undefined2 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar3 = DAT_022d0874;
  iVar1 = (param_2 + 1) / 2;
  param_1[5] = 0;
  param_1[6] = (short)uVar3;
  param_1[7] = (short)iVar1 + 1;
  param_1[8] = (short)param_2;
  func_0x037cb78c(param_3,param_1 + 9,param_2,iVar1,param_4);
  uVar2 = param_1[7];
  param_1[uVar2 + 8] = param_1[6];
  param_1[uVar2 + 9] = 1;
  FUN_022ce1d8(param_1);
  return param_1 + uVar2 + 8;
}

