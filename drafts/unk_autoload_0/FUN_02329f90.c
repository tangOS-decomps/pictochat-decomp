// decomp: module=unk_autoload_0 addr=0x02329f90 name=FUN_02329f90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02329f90 --addr 0x02329f90 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02329f90(void)

{
  *(undefined4 *)(DAT_02329fa4 + 0x10) = 1;
  FUN_02331ef0(DAT_02329fa8);
  FUN_02329e80();
  return;
}

