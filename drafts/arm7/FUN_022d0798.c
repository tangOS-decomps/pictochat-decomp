// decomp: module=arm7 addr=0x022d0798 name=FUN_022d0798
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022d0798 --addr 0x022d0798 --size 0x5c --module arm7 --version 2.0/sp1


undefined2 * FUN_022d0798(undefined2 *param_1,undefined2 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = DAT_022d07f0;
  param_1[5] = 0;
  param_1[6] = (short)uVar2;
  param_1[7] = 1;
  param_1[8] = param_2;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8();
  return param_1 + uVar1 + 8;
}

