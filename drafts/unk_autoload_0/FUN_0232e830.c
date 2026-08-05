// decomp: module=unk_autoload_0 addr=0x0232e830 name=FUN_0232e830
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e830 --addr 0x0232e830 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e830(uint param_1)

{
  if (param_1 != 0) {
    FUN_02337830(param_1,0);
    *(uint *)(DAT_0232e848 + 8) = ~param_1 & *(uint *)(DAT_0232e848 + 8);
  }
  return;
}

