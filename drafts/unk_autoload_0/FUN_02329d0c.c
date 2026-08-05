// decomp: module=unk_autoload_0 addr=0x02329d0c name=FUN_02329d0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02329d0c --addr 0x02329d0c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329d0c(undefined4 param_1)

{
  FUN_02332080();
  *(undefined4 *)(DAT_02329d20 + 0x20) = param_1;
  FUN_02332094();
  return;
}

