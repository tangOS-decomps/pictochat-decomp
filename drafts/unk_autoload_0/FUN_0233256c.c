// decomp: module=unk_autoload_0 addr=0x0233256c name=FUN_0233256c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=6
// verify:  python tools/match.py --c <file> --func FUN_0233256c --addr 0x0233256c --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0233256c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_023324f8(0xb7,param_1,param_3,param_4,param_4);
  *DAT_02332594 = *DAT_0233258c & DAT_02332590 | 0xa1000000;
  return;
}

