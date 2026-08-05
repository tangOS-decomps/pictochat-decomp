// decomp: module=unk_autoload_0 addr=0x023309a4 name=FUN_023309a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4a, thumb
// triage: noise=4 statements=25
// verify:  python tools/match.py --c <file> --func FUN_023309a4 --addr 0x023309a4 --size 0x4a --module unk_autoload_0 --version 2.0/sp1


int FUN_023309a4(undefined4 param_1,int param_2,code *param_3,int param_4)

{
  int iVar1;
  undefined4 local_20;
  
  if (param_4 == 0) {
    local_20 = FUN_02332080();
  }
  else {
    local_20 = FUN_023320ac();
  }
  iVar1 = FUN_023376b4(param_1,param_2);
  if (iVar1 == 0) {
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *(short *)(param_2 + 4) = (short)param_1;
  }
  if (param_4 == 0) {
    FUN_02332094(local_20);
  }
  else {
    FUN_023320c0(local_20);
  }
  return iVar1;
}

