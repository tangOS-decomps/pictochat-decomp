// decomp: module=unk_autoload_0 addr=0x0232aa0c name=FUN_0232aa0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232aa0c --addr 0x0232aa0c --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232aa0c(void)

{
  undefined4 in_r3;
  
  if (*(int *)(DAT_0232aa30 + 0x14) != 0) {
    FUN_0233740c(0,DAT_0232aa34,0x60,in_r3,in_r3);
    return;
  }
  FUN_0233740c(0,DAT_0232aa38,0x60,in_r3,in_r3);
  return;
}

