// decomp: module=unk_autoload_0 addr=0x02321684 name=FUN_02321684
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02321684 --addr 0x02321684 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321684(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = FUN_02321d14(param_3);
  FUN_02321a6c(*(undefined4 *)(param_1 + 0x24),param_1,param_2,uVar1 & 0xffff,param_3,0,0,0xffffffff
              );
  return;
}

