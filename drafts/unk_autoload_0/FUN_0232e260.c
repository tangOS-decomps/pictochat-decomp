// decomp: module=unk_autoload_0 addr=0x0232e260 name=FUN_0232e260
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a, thumb
// triage: noise=0 statements=6  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e260 --addr 0x0232e260 --size 0x1a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e260(int *param_1,int param_2)

{
  *param_1 = param_2 - ((int)(uint)*(ushort *)(param_2 + 2) >> 8 & 0x7fU);
  param_1[1] = *(int *)(param_2 + 4) + param_2 + 0x10;
  return;
}

