// decomp: module=unk_autoload_0 addr=0x0232a4c8 name=FUN_0232a4c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232a4c8 --addr 0x0232a4c8 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a4c8(void)

{
  *(int *)(DAT_0232a4dc + 0x4c) = DAT_0232a4e0 * *(int *)(DAT_0232a4dc + 0x4c) + DAT_0232a4e4;
  return;
}

