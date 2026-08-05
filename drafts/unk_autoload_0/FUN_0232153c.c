// decomp: module=unk_autoload_0 addr=0x0232153c name=FUN_0232153c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=5 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232153c --addr 0x0232153c --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232153c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  
  uVar1 = param_4;
  for (; param_3 < param_5; param_3 = param_3 + 1) {
    FUN_0232148c(param_1,param_2,param_3,param_4,param_3,param_6,param_2,param_4,uVar1);
  }
  return;
}

