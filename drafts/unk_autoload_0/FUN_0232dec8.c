// decomp: module=unk_autoload_0 addr=0x0232dec8 name=FUN_0232dec8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=2 statements=14
// verify:  python tools/match.py --c <file> --func FUN_0232dec8 --addr 0x0232dec8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232dec8(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_18;
  
  local_18 = 0;
  iVar1 = 0;
  while (param_2 != 0) {
    param_2 = FUN_0232de74(param_1,param_2,&local_18,param_3);
    if (iVar1 < local_18) {
      iVar1 = local_18;
    }
  }
  return iVar1;
}

