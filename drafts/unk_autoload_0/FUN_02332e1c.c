// decomp: module=unk_autoload_0 addr=0x02332e1c name=FUN_02332e1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02332e1c --addr 0x02332e1c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


char * FUN_02332e1c(char *param_1,char param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return (char *)0x0;
    }
    if (*param_1 == param_2) break;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
  }
  return param_1;
}

