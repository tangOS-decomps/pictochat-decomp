// decomp: module=arm7 addr=0x022c678c name=FUN_022c678c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=19  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c678c --addr 0x022c678c --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022c678c(void)

{
  short *psVar1;
  
  psVar1 = DAT_022c67d4;
  if (*DAT_022c67d4 == 0) {
    *DAT_022c67d4 = 1;
    psVar1[6] = 0;
    psVar1[7] = 0;
    psVar1[8] = 0;
    psVar1[9] = 0;
    FUN_022c48a4(4);
    psVar1 = DAT_022c67d4;
    psVar1[4] = 0;
    psVar1[5] = 0;
    psVar1[2] = 0;
    psVar1[3] = 0;
  }
  return;
}

