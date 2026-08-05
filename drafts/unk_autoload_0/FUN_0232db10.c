// decomp: module=unk_autoload_0 addr=0x0232db10 name=FUN_0232db10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, thumb
// triage: noise=9 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232db10 --addr 0x0232db10 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232db10(undefined4 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5,undefined4 param_6)

{
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = param_3;
  *(undefined2 *)((int)param_1 + 6) = param_4;
  *(undefined2 *)(param_1 + 2) = param_5;
  param_1[3] = param_6;
  return;
}

