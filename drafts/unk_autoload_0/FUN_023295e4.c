// decomp: module=unk_autoload_0 addr=0x023295e4 name=FUN_023295e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023295e4 --addr 0x023295e4 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_023295e4(void)

{
  byte bVar1;
  
  bVar1 = DAT_023295fc[1];
  if (bVar1 < *DAT_023295fc) {
    bVar1 = bVar1 + 6;
  }
  DAT_023295fc[2] = bVar1 - *DAT_023295fc;
  return;
}

