// decomp: module=arm7 addr=0x022d02e8 name=FUN_022d02e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022d02e8 --addr 0x022d02e8 --size 0x68 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d02e8(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = DAT_022d034c;
  param_1[5] = 0;
  param_1[6] = (short)uVar2;
  param_1[7] = 4;
  param_1[8] = param_2;
  param_1[9] = param_3;
  *(undefined4 *)(param_1 + 10) = param_4;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8();
  return param_1 + uVar1 + 8;
}

