// decomp: module=unk_autoload_0 addr=0x0232ca20 name=FUN_0232ca20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232ca20 --addr 0x0232ca20 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232ca20(void)

{
  int iVar1;
  
  iVar1 = FUN_0232c4dc();
  if (iVar1 != 0) {
    return 0x8000;
  }
  return *DAT_0232ca38;
}

