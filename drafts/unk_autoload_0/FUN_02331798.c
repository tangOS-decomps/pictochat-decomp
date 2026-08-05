// decomp: module=unk_autoload_0 addr=0x02331798 name=FUN_02331798
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc (Ghidra's cache says 0x8 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02331798 --addr 0x02331798 --size 0xc --module unk_autoload_0 --version 2.0/sp1


void FUN_02331798(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 * 4 + DAT_023317a0) = param_2;
  return;
}

