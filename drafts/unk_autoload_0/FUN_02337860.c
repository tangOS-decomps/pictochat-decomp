// decomp: module=unk_autoload_0 addr=0x02337860 name=FUN_02337860
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x32, thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02337860 --addr 0x02337860 --size 0x32 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337860(uint param_1,int param_2,undefined4 param_3,int param_4,uint param_5,uint param_6,
                 int param_7,int param_8,int param_9,int param_10)

{
  FUN_02337930(0xe,param_9 << 0x10 | param_1,param_3,param_6 | param_8 << 0x16 | param_7 << 0x18,
               param_10 << 0x10 | param_2 << 0x18 | param_4 << 0x1a | param_5);
  return;
}

