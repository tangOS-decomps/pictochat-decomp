// decomp: module=unk_autoload_0 addr=0x02334f88 name=FUN_02334f88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe, thumb
// triage: noise=1 statements=4
// verify:  python tools/match.py --c <file> --func FUN_02334f88 --addr 0x02334f88 --size 0xe --module unk_autoload_0 --version 2.0/sp1


uint FUN_02334f88(undefined4 param_1,uint param_2)

{
  return param_2 & 0x80000000;
}

