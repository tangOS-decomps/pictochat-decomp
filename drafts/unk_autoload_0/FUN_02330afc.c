// decomp: module=unk_autoload_0 addr=0x02330afc name=FUN_02330afc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10 (Ghidra's cache says 0xa - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02330afc --addr 0x02330afc --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330afc(void)

{
  *(int *)(DAT_02330b08 + 0x18) = *(int *)(DAT_02330b08 + 0x18) + 1;
  return;
}

