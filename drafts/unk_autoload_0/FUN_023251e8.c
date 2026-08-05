// decomp: module=unk_autoload_0 addr=0x023251e8 name=FUN_023251e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=9
// verify:  python tools/match.py --c <file> --func FUN_023251e8 --addr 0x023251e8 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_023251e8(undefined2 param_1)

{
  int iVar1;
  
  FUN_0232517c(DAT_023251fc);
  iVar1 = DAT_02325200;
  *(undefined2 *)(DAT_02325200 + 8) = param_1;
  *(undefined2 *)(iVar1 + 10) = 0;
  return;
}

