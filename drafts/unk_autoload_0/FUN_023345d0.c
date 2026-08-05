// decomp: module=unk_autoload_0 addr=0x023345d0 name=FUN_023345d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023345d0 --addr 0x023345d0 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


char * FUN_023345d0(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (param_1 = param_1 + 1, cVar1 != '\0') {
    if (cVar1 == param_2) {
      return param_1 + -1;
    }
    cVar1 = *param_1;
  }
  if (param_2 != '\0') {
    return (char *)0x0;
  }
  return param_1 + -1;
}

