// decomp: module=unk_autoload_0 addr=0x02321770 name=FUN_02321770
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x26, thumb
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02321770 --addr 0x02321770 --size 0x26 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_02321770(int *p)

{
  int b;
  
  b = 0;
  while (b = FUN_0232e178(p,b), b != 0) {
    if (*(char *)(b + 0x28) == '\0') {
      FUN_02321708(b);
    }
  }
  return;
}

