// decomp: module=arm7 addr=0x022d0350 name=FUN_022d0350
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x94 - it excludes this function's trailing literal pool), arm
// triage: noise=13 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022d0350 --addr 0x022d0350 --size 0x98 --module arm7 --version 2.0/sp1


undefined2 *
FUN_022d0350(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
            undefined2 param_9,undefined4 param_10)

{
  ushort uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = DAT_022d03e4;
  param_1[5] = 0;
  param_1[6] = (short)uVar2;
  param_1[7] = 10;
  param_1[8] = param_2;
  param_1[9] = param_3;
  param_1[10] = param_4;
  param_1[0xb] = param_5;
  param_1[0xc] = param_6;
  param_1[0xd] = param_7;
  param_1[0xe] = param_8;
  param_1[0xf] = param_9;
  *(undefined4 *)(param_1 + 0x10) = param_10;
  uVar1 = param_1[7];
  param_1[uVar1 + 8] = param_1[6];
  param_1[uVar1 + 9] = 1;
  FUN_022ce1d8();
  return param_1 + uVar1 + 8;
}

