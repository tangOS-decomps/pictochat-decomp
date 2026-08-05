// decomp: module=unk_autoload_0 addr=0x02321634 name=FUN_02321634
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=3 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02321634 --addr 0x02321634 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321634(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_4;
  iVar1 = FUN_02321d14(param_4);
  FUN_02321a6c(param_1,param_2,param_3,iVar1,param_4,0,1,0xffffffff,iVar2);
  return;
}

