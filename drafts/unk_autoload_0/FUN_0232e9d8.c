// decomp: module=unk_autoload_0 addr=0x0232e9d8 name=FUN_0232e9d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e9d8 --addr 0x0232e9d8 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e9d8(int *param_1,int param_2)

{
  if (*param_1 != 0) {
    FUN_02337720((uint)*(byte *)(*param_1 + 0x3c),param_2);
  }
  return;
}

