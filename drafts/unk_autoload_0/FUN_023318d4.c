// decomp: module=unk_autoload_0 addr=0x023318d4 name=FUN_023318d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, arm
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_023318d4 --addr 0x023318d4 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_023318d4(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = param_3 - 0x16 >> 1;
  FUN_02331838(param_1,param_3 | param_2 & -0x1000 << (uVar1 & 0xff) | 1,param_3,uVar1,param_4);
  return;
}

