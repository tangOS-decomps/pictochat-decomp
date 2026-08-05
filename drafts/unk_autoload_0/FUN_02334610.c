// decomp: module=unk_autoload_0 addr=0x02334610 name=FUN_02334610
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334610 --addr 0x02334610 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334610(short *param_1,short *param_2)

{
  short sVar1;
  
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = sVar1;
    sVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (sVar1 != 0);
  return;
}

