// decomp: module=unk_autoload_0 addr=0x0232e5e8 name=FUN_0232e5e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=4 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232e5e8 --addr 0x0232e5e8 --size 0x2a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e5e8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  FUN_0232e260(auStack_18,param_2 + -0x10);
  FUN_0232e27c(param_1 + 0x2c,param_2 + -0x10);
  FUN_0232e514(param_1 + 0x24,auStack_18);
  return;
}

