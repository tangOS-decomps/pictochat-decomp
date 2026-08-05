// decomp: module=unk_autoload_0 addr=0x02338a54 name=FUN_02338a54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x32, thumb
// triage: noise=6 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02338a54 --addr 0x02338a54 --size 0x32 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02338a54(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined4 **)(param_1 + 0x10) = &local_10;
  local_10 = param_2;
  local_c = param_3;
  iVar1 = FUN_0233895c(param_1,0,1);
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x14) == 6)) {
    local_c = 0xffffffff;
  }
  return local_c;
}

