// decomp: module=unk_autoload_0 addr=0x02330e78 name=FUN_02330e78
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=6
// verify:  python tools/match.py --c <file> --func FUN_02330e78 --addr 0x02330e78 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330e78(void)

{
  FUN_02332080();
  FUN_02330e90(*(undefined4 *)(DAT_02330e8c + 0x20),0);
  return;
}

