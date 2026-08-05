// decomp: module=unk_autoload_0 addr=0x0232e8c8 name=FUN_0232e8c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0xe - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e8c8 --addr 0x0232e8c8 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e8c8(int param_1,uint param_2)

{
  *(uint *)(DAT_0232e8d8 + param_1 * 0x24) = param_2 & 0xffff;
  return;
}

