// decomp: module=unk_autoload_0 addr=0x02329a3c name=FUN_02329a3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=7 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02329a3c --addr 0x02329a3c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined1 FUN_02329a3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_10 [5];
  undefined1 local_b;
  undefined4 uStack_8;
  
  if (param_1 != 0) {
    uStack_8 = param_4;
    FUN_02337584(param_1 + 0x70,auStack_10,8);
    return local_b;
  }
  return 0;
}

