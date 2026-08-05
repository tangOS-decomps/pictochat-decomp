// decomp: module=unk_autoload_0 addr=0x023377c4 name=FUN_023377c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_023377c4 --addr 0x023377c4 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_023377c4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7)

{
  FUN_02337930(0x11,param_3,param_4,
               param_5 << 0x1d | param_2 << 0x1e | param_1 << 0x1f | param_6 << 0x1c |
               param_7 << 0x1b,0);
  return;
}

