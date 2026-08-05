// decomp: module=arm7 addr=0x022d09e4 name=FUN_022d09e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, arm
// triage: noise=4 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022d09e4 --addr 0x022d09e4 --size 0x48 --module arm7 --version 2.0/sp1


undefined2 * FUN_022d09e4(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_2;
  param_1[7] = 0;
  param_1[8] = param_1[6];
  param_1[9] = param_3;
  FUN_022ce1d8();
  return param_1 + 8;
}

