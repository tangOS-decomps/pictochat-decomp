// decomp: module=unk_autoload_0 addr=0x0232e9a8 name=FUN_0232e9a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe, thumb
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_0232e9a8 --addr 0x0232e9a8 --size 0xe --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e9a8(int *param_1,undefined1 param_2)

{
  if (*param_1 != 0) {
    *(undefined1 *)(*param_1 + 0x40) = param_2;
  }
  return;
}

