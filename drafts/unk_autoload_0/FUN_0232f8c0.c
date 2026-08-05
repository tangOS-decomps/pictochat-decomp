// decomp: module=unk_autoload_0 addr=0x0232f8c0 name=FUN_0232f8c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x26, thumb
// triage: noise=5 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232f8c0 --addr 0x0232f8c0 --size 0x26 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232f8c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int a;
  
  a = FUN_0232e710(*param_1,0x14,4,param_4,param_4);
  if (a == 0) {
    return 0;
  }
  FUN_0232f890(a);
  FUN_0232e0ac(param_1 + 1,a);
  return 1;
}

