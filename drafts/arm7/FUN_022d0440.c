// decomp: module=arm7 addr=0x022d0440 name=FUN_022d0440
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54, arm
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022d0440 --addr 0x022d0440 --size 0x54 --module arm7 --version 2.0/sp1


undefined2 * FUN_022d0440(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x200;
  param_1[7] = 0x48;
  param_1[0x50] = param_1[6];
  param_1[0x51] = 1;
  FUN_022ce1d8();
  return param_1 + 0x50;
}

