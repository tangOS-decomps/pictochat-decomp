// decomp: module=unk_autoload_0 addr=0x02338a3c name=FUN_02338a3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=7 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02338a3c --addr 0x02338a3c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338a3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  *(undefined4 **)(param_1 + 0x10) = &local_10;
  local_10 = param_2;
  local_c = param_3;
  uStack_8 = param_4;
  FUN_0233895c(param_1,0xe,1);
  return;
}

