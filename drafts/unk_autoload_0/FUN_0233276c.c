// decomp: module=unk_autoload_0 addr=0x0233276c name=FUN_0233276c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_0233276c --addr 0x0233276c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0233276c(void)

{
  if (*DAT_02332780 != DAT_02332784) {
    return 1;
  }
  return 0;
}

