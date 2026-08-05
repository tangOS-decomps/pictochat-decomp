// decomp: module=unk_autoload_0 addr=0x0232d238 name=FUN_0232d238
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232d238 --addr 0x0232d238 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d238(void)

{
  if ((*DAT_0232d24c & 8) == 0) {
    FUN_0232d260(0x8000000);
  }
  return;
}

