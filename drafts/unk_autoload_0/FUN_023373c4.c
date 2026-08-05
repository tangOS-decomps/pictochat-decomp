// decomp: module=unk_autoload_0 addr=0x023373c4 name=FUN_023373c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=0 statements=18  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023373c4 --addr 0x023373c4 --size 0x46 --module unk_autoload_0 --version 2.0/sp1


void FUN_023373c4(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = param_2 & 0xff000000;
    if (param_4 == 0) {
      param_2 = param_2 + param_3;
    }
    else if (param_4 == 0x800000) {
      param_2 = param_2 - param_3;
    }
    if ((((uVar1 == 0x4000000) || (0x7ffffff < uVar1)) || ((param_2 & 0xff000000) == 0x4000000)) ||
       (0x7ffffff < (param_2 & 0xff000000))) {
      FUN_02332274();
    }
  }
  return;
}

