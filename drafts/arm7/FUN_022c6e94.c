// decomp: module=arm7 addr=0x022c6e94 name=FUN_022c6e94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c6e94 --addr 0x022c6e94 --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022c6e94(void)

{
  if (*DAT_022c6ecc == 0) {
    *DAT_022c6ecc = 1;
    thunk_EXT_FUN_0380414c(0);
    FUN_022c6d40();
  }
  else {
    FUN_022c6d40();
  }
  do {
    thunk_EXT_FUN_037fb7d2();
  } while( true );
}

