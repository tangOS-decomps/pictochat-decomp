// decomp: module=unk_autoload_0 addr=0x0232e710 name=FUN_0232e710
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x22, thumb
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232e710 --addr 0x0232e710 --size 0x22 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e710(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (-1 < param_3) {
    FUN_0232e640();
    return;
  }
  FUN_0232e680(param_1 + 0x24,param_2 + 3U & 0xfffffffc,-param_3,3,param_4);
  return;
}

