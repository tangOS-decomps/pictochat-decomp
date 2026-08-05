// decomp: module=unk_autoload_0 addr=0x0232d36c name=FUN_0232d36c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232d36c --addr 0x0232d36c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d36c(void)

{
  uint in_r3;
  uint local_8 [2];
  
  local_8[0] = (uint)*DAT_0232d384 | in_r3 & 0xffffff00;
  FUN_02339a24(local_8);
  return;
}

