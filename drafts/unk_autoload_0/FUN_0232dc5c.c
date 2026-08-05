// decomp: module=unk_autoload_0 addr=0x0232dc5c name=FUN_0232dc5c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e, thumb
// triage: noise=8 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232dc5c --addr 0x0232dc5c --size 0x2e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232dc5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5,undefined4 param_6)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  uVar1 = FUN_0232db60(param_1,param_5);
  FUN_0232dc8c(param_1,param_2,param_3,param_4,uVar1,param_6,uVar2);
  return;
}

