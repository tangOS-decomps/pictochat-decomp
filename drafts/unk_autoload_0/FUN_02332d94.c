// decomp: module=unk_autoload_0 addr=0x02332d94 name=FUN_02332d94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10 (Ghidra's cache says 0xc - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02332d94 --addr 0x02332d94 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332d94(void)

{
  (**(code **)(*(int *)(DAT_02332da0 + 8) + 4))();
  return;
}

