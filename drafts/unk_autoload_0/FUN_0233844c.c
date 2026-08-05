// decomp: module=unk_autoload_0 addr=0x0233844c name=FUN_0233844c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0233844c --addr 0x0233844c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0233844c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 - 9U < 0x1b) && ((DAT_02338468 & 1 << (param_1 - 9U & 0xff)) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

