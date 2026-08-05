// decomp: module=unk_autoload_0 addr=0x02330590 name=FUN_02330590
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=4 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02330590 --addr 0x02330590 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330590(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_023305a8();
  *param_1 = uVar1;
  param_1[1] = param_2;
  param_1[3] = param_3;
  param_1[2] = 0;
  return;
}

