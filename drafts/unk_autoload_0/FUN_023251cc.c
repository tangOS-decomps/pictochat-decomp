// decomp: module=unk_autoload_0 addr=0x023251cc name=FUN_023251cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x16, thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_023251cc --addr 0x023251cc --size 0x16 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023251cc(short *param_1)

{
  if ((*param_1 != param_1[1]) && (*param_1 != param_1[2])) {
    return 0;
  }
  return 1;
}

