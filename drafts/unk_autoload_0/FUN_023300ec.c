// decomp: module=unk_autoload_0 addr=0x023300ec name=FUN_023300ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023300ec --addr 0x023300ec --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_023300ec(int *param_1)

{
  if ((param_1[0x4a] != 0) && (param_1[0x4a] = param_1[0x4a] + -1, param_1[0x4a] == 0)) {
    FUN_0232eed8(param_1);
  }
  return;
}

