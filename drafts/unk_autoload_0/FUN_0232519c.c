// decomp: module=unk_autoload_0 addr=0x0232519c name=FUN_0232519c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, thumb
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232519c --addr 0x0232519c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232519c(ushort *param_1)

{
  *param_1 = *param_1 + 1;
  if ((*param_1 == param_1[1]) || (*param_1 == param_1[2])) {
    param_1[3] = 1;
  }
  if (param_1[2] < *param_1) {
    *param_1 = param_1[1] + 1;
  }
  return;
}

