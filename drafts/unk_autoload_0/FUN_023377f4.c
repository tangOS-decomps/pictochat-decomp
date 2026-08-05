// decomp: module=unk_autoload_0 addr=0x023377f4 name=FUN_023377f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, thumb
// triage: noise=6 statements=8
// verify:  python tools/match.py --c <file> --func FUN_023377f4 --addr 0x023377f4 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_023377f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02337e68(param_1,param_4,param_5);
  FUN_02337930(0x12,param_1,param_2,param_3,uVar1,param_4);
  return;
}

