// decomp: module=unk_autoload_0 addr=0x02326780 name=FUN_02326780
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02326780 --addr 0x02326780 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_02326780(int param_1)

{
  param_1 = *(int *)(DAT_02326798 + 0x20) - param_1;
  if (param_1 < 0) {
    param_1 = param_1 + 0x400;
  }
  return *(int *)(DAT_02326798 + 4) - param_1;
}

