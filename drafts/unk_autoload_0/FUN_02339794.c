// decomp: module=unk_autoload_0 addr=0x02339794 name=FUN_02339794
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0xe - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=4  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02339794 --addr 0x02339794 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


bool FUN_02339794(void)

{
  return (*DAT_023397a4 & 1) != 0;
}

