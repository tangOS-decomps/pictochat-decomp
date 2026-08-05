// decomp: module=unk_autoload_0 addr=0x02334628 name=FUN_02334628
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x32, thumb
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334628 --addr 0x02334628 --size 0x32 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334628(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  
  while( true ) {
    if (param_3 == 0) {
      return;
    }
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = sVar1;
    sVar1 = *param_1;
    param_1 = param_1 + 1;
    if (sVar1 == 0) break;
    param_3 = param_3 + -1;
  }
  param_3 = param_3 + -1;
  if (param_3 == 0) {
    return;
  }
  do {
    *param_1 = 0;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

