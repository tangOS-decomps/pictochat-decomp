// decomp: module=unk_autoload_0 addr=0x0232c820 name=FUN_0232c820
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232c820 --addr 0x0232c820 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c820(void)

{
  if ((*DAT_0232c834 & 1) != 0) {
    *DAT_0232c834 = *DAT_0232c834 & 0xfffe;
  }
  return;
}

