// decomp: module=unk_autoload_0 addr=0x0232ea00 name=FUN_0232ea00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ea00 --addr 0x0232ea00 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ea00(int *param_1,int param_2,int param_3)

{
  if (*param_1 != 0) {
    FUN_02337740((uint)*(byte *)(*param_1 + 0x3c),param_2,param_3);
  }
  return;
}

