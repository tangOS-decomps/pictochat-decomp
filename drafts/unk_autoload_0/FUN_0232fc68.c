// decomp: module=unk_autoload_0 addr=0x0232fc68 name=FUN_0232fc68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=2 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232fc68 --addr 0x0232fc68 --size 0x2a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232fc68(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_023381cc(param_3,param_4,param_3,param_4,param_4);
  if (param_1 == iVar1) {
    FUN_023381ac(param_3,param_4,0);
  }
  FUN_023378ac(param_1,param_1 + param_2);
  return;
}

