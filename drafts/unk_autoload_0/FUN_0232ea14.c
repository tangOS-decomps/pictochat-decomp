// decomp: module=unk_autoload_0 addr=0x0232ea14 name=FUN_0232ea14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a, thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232ea14 --addr 0x0232ea14 --size 0x1a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ea14(int *param_1,undefined2 param_2,undefined2 param_3)

{
  if (*param_1 != 0) {
    *(undefined2 *)(*param_1 + 0x34) = 2;
    *(undefined2 *)(*param_1 + 0x38) = param_2;
    *(undefined2 *)(*param_1 + 0x3a) = param_3;
  }
  return;
}

