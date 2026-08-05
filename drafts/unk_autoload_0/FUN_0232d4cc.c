// decomp: module=unk_autoload_0 addr=0x0232d4cc name=FUN_0232d4cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232d4cc --addr 0x0232d4cc --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d4cc(void)

{
  undefined4 in_r3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_10 = 0;
  local_c = 0xb8000000;
  uStack_8 = in_r3;
  FUN_0232d4fc(&local_10);
  *DAT_0232d4f8 = *(uint *)(DAT_0232d4f4 + 4) | 0xa7000000;
  return;
}

