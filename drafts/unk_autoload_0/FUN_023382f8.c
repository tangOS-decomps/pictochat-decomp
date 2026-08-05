// decomp: module=unk_autoload_0 addr=0x023382f8 name=FUN_023382f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=4  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023382f8 --addr 0x023382f8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


bool FUN_023382f8(uint param_1,int param_2)

{
  return (*(uint *)(DAT_02338318 + param_2 * 4 + 0x388) & 1 << (param_1 & 0xff)) != 0;
}

