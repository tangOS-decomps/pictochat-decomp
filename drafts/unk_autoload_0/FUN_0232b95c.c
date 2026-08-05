// decomp: module=unk_autoload_0 addr=0x0232b95c name=FUN_0232b95c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232b95c --addr 0x0232b95c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232b95c(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (((iVar1 == 6) || (iVar1 = FUN_0232996c(), iVar1 == 7)) && (*(int *)(DAT_0232b980 + 0x14) == 0)
     ) {
    return 1;
  }
  return 0;
}

