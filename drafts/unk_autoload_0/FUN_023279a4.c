// decomp: module=unk_autoload_0 addr=0x023279a4 name=FUN_023279a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x16, thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023279a4 --addr 0x023279a4 --size 0x16 --module unk_autoload_0 --version 2.0/sp1


int FUN_023279a4(int param_1,int param_2)

{
  if (param_1 < 0x33) {
    return 0;
  }
  return ((param_1 + -0x32) * param_2) / 2;
}

