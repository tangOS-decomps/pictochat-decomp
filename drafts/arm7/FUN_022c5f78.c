// decomp: module=arm7 addr=0x022c5f78 name=FUN_022c5f78
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5f78 --addr 0x022c5f78 --size 0x54 --module arm7 --version 2.0/sp1


void FUN_022c5f78(void)

{
  uint uVar1;
  
  uVar1 = *DAT_022c5fbc;
  if ((uVar1 < 0x2600000) || (0x27fffff < uVar1)) {
    uVar1 = 0;
  }
  DAT_022c5fc0[2] = uVar1;
  if (uVar1 == 0) {
    *DAT_022c5fc8 = DAT_022c5fc4;
  }
  *DAT_022c5fc0 = 0;
  return;
}

