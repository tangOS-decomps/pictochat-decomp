// decomp: module=unk_autoload_0 addr=0x023221b0 name=FUN_023221b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=7
// verify:  python tools/match.py --c <file> --func FUN_023221b0 --addr 0x023221b0 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_023221b0(void)

{
  undefined4 in_r3;
  
  FUN_02321684(PTR_DAT_023221c8,PTR_DAT_023221cc,0x2d,in_r3,in_r3);
  FUN_02321684(PTR_DAT_023221d0,PTR_DAT_023221cc,0x2e);
  return;
}

