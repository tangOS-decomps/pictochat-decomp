// decomp: module=unk_autoload_0 addr=0x0232acb8 name=FUN_0232acb8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_0232acb8 --addr 0x0232acb8 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232acb8(int param_1)

{
  FUN_02329bd8(8);
  *(undefined2 *)(DAT_0232acd0 + 0xc) = *(undefined2 *)(param_1 + 10);
  FUN_0232b0d0();
  return;
}

