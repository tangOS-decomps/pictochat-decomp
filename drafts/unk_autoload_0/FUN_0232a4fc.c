// decomp: module=unk_autoload_0 addr=0x0232a4fc name=FUN_0232a4fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232a4fc --addr 0x0232a4fc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a4fc(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 == 0) || (iVar1 = FUN_0232996c(), iVar1 == 1)) {
    *DAT_0232a518 = param_1;
  }
  return;
}

