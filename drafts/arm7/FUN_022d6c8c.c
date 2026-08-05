// decomp: module=arm7 addr=0x022d6c8c name=FUN_022d6c8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, arm
// triage: noise=4 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022d6c8c --addr 0x022d6c8c --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022d6c8c(undefined4 *param_1,undefined2 param_2)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = param_2;
  return;
}

