// decomp: module=unk_autoload_0 addr=0x023376b4 name=FUN_023376b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8, arm
// triage: noise=4 statements=7
// verify:  python tools/match.py --c <file> --func FUN_023376b4 --addr 0x023376b4 --size 0x8 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023376b4(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}

