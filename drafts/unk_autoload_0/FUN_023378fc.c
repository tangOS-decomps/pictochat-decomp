// decomp: module=unk_autoload_0 addr=0x023378fc name=FUN_023378fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=3 statements=5
// verify:  python tools/match.py --c <file> --func FUN_023378fc --addr 0x023378fc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_023378fc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  FUN_02337930(7,param_5 << 0x18 | param_1,param_2,param_3,param_4,param_4);
  return;
}

