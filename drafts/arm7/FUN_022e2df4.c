// decomp: module=arm7 addr=0x022e2df4 name=FUN_022e2df4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, arm
// triage: noise=4 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022e2df4 --addr 0x022e2df4 --size 0x40 --module arm7 --version 2.0/sp1


void FUN_022e2df4(void)

{
  undefined4 in_r3;
  uint local_10;
  undefined4 local_c;
  
  local_c = in_r3;
  do {
    while( true ) {
      thunk_EXT_FUN_03802a20(&local_10);
      if ((local_10 & 0x20) == 0) break;
      thunk_EXT_FUN_03802f00();
    }
  } while ((local_10 & 1) != 0);
  return;
}

