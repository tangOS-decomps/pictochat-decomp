// decomp: module=unk_autoload_0 addr=0x0232f050 name=FUN_0232f050
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232f050 --addr 0x0232f050 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f050(void)

{
  if ((*DAT_0232f068 != 0) && (DAT_0232f068[1] == 1)) {
    FUN_0232f304();
  }
  return;
}

