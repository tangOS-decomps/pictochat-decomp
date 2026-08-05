// decomp: module=arm7 addr=0x022c638c name=FUN_022c638c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c638c --addr 0x022c638c --size 0x44 --module arm7 --version 2.0/sp1


void FUN_022c638c(void)

{
  short *psVar1;
  
  if (*DAT_022c63cc == 0) {
    *DAT_022c63cc = 1;
    FUN_022c614c();
    psVar1 = DAT_022c63cc;
    psVar1[2] = 0;
    psVar1[3] = 0;
    psVar1[4] = 0;
    psVar1[5] = 0;
    FUN_022c48a4(0x10);
  }
  return;
}

