// decomp: module=unk_autoload_0 addr=0x02322800 name=FUN_02322800
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=2 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02322800 --addr 0x02322800 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322800(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_02339250(0x14,param_2 & 0xff | (param_1 & 0xff) << 8,0,param_3,param_4);
  return;
}

