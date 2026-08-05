// decomp: module=unk_autoload_0 addr=0x02337454 name=FUN_02337454
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, arm
// triage: noise=3 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02337454 --addr 0x02337454 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337454(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  param_3 = (int)param_2 + param_3;
  for (; (int)param_2 < param_3; param_2 = param_2 + 1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
  }
  return;
}

