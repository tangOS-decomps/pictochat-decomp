// decomp: module=unk_autoload_0 addr=0x0233014c name=FUN_0233014c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0233014c --addr 0x0233014c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233014c(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02332080();
  FUN_0232e0ac(DAT_02330168,param_1);
  FUN_02332094(uVar1);
  return;
}

