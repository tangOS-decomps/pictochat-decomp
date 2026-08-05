// decomp: module=unk_autoload_0 addr=0x02331d84 name=FUN_02331d84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02331d84 --addr 0x02331d84 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331d84(void)

{
  short *psVar1;
  
  if (*DAT_02331da8 == 0) {
    *DAT_02331da8 = 1;
    FUN_02331be8(1);
    psVar1 = DAT_02331da8;
    psVar1[2] = 0;
    psVar1[3] = 0;
    psVar1[4] = 0;
    psVar1[5] = 0;
    FUN_023307f8(0x10);
  }
  return;
}

