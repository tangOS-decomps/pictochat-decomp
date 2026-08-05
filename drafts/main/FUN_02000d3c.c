// decomp: module=main addr=0x02000d3c name=FUN_02000d3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02000d3c --addr 0x02000d3c --size 0x14 --module main --version 2.0/sp1


void FUN_02000d3c(undefined4 param_1,undefined4 *param_2,int param_3)

{
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

