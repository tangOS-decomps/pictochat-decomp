// decomp: module=unk_autoload_0 addr=0x02337440 name=FUN_02337440
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02337440 --addr 0x02337440 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337440(undefined4 param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

