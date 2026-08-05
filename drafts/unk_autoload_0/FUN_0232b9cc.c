// decomp: module=unk_autoload_0 addr=0x0232b9cc name=FUN_0232b9cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_0232b9cc --addr 0x0232b9cc --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b9cc(undefined4 param_1)

{
  FUN_02332080();
  *(undefined4 *)(DAT_0232b9e0 + 0x3c) = param_1;
  FUN_02332094();
  return;
}

