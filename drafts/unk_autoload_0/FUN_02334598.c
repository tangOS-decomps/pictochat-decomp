// decomp: module=unk_autoload_0 addr=0x02334598 name=FUN_02334598
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334598 --addr 0x02334598 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334598(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  
  while( true ) {
    if (param_3 == 0) {
      return;
    }
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = cVar1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    param_3 = param_3 + -1;
  }
  param_3 = param_3 + -1;
  if (param_3 == 0) {
    return;
  }
  do {
    *param_1 = '\0';
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

