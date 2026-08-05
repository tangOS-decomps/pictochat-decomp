// decomp: module=arm7 addr=0x022c0f78 name=FUN_022c0f78
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=10
// verify:  python tools/match.py --c <file> --func FUN_022c0f78 --addr 0x022c0f78 --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022c0f78(void)

{
  undefined4 in_r3;
  undefined4 local_8 [2];
  
  local_8[0] = in_r3;
  FUN_022c573c(*(undefined4 *)(*DAT_022c0fb0 + 0x308),local_8,1);
  FUN_022c0fb4(local_8);
  FUN_022c0e48(3,0xc);
  return;
}

