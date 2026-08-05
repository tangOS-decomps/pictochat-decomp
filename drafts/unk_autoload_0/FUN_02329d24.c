// decomp: module=unk_autoload_0 addr=0x02329d24 name=FUN_02329d24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02329d24 --addr 0x02329d24 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329d24(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 == 0) || (iVar1 = FUN_0232996c(), iVar1 == 1)) {
    *(undefined2 *)(DAT_02329d40 + 4) = param_1;
  }
  return;
}

