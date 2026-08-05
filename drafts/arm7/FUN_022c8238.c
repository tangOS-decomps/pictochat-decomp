// decomp: module=arm7 addr=0x022c8238 name=FUN_022c8238
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c8238 --addr 0x022c8238 --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022c8238(int param_1,int param_2)

{
  char cVar1;
  
  if (param_2 < 0x6d) {
    cVar1 = -1 - (char)param_2;
  }
  else {
    cVar1 = *(char *)(DAT_022c8250 + (0x7f - param_2));
  }
  *(char *)(param_1 + 0x1c) = cVar1;
  return;
}

