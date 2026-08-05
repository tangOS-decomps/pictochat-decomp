// decomp: module=unk_autoload_0 addr=0x02329804 name=FUN_02329804
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02329804 --addr 0x02329804 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329804(void)

{
  *(undefined4 *)(DAT_02329818 + 8) = 1;
  FUN_02329a5c();
  FUN_023298d8(0);
  return;
}

