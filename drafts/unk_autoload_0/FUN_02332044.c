// decomp: module=unk_autoload_0 addr=0x02332044 name=FUN_02332044
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=19  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02332044 --addr 0x02332044 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332044(void)

{
  short *psVar1;
  
  psVar1 = DAT_02332068;
  if (*DAT_02332068 == 0) {
    *DAT_02332068 = 1;
    psVar1[6] = 0;
    psVar1[7] = 0;
    psVar1[8] = 0;
    psVar1[9] = 0;
    FUN_023307f8(4);
    psVar1 = DAT_02332068;
    psVar1[4] = 0;
    psVar1[5] = 0;
    psVar1[2] = 0;
    psVar1[3] = 0;
  }
  return;
}

