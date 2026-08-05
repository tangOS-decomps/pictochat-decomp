// decomp: module=unk_autoload_0 addr=0x02334564 name=FUN_02334564
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=6 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02334564 --addr 0x02334564 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


void FUN_02334564(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_02334528(param_1,0xffffffff,param_2,&uStack_8);
  return;
}

