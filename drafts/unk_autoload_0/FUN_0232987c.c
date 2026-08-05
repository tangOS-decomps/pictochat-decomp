// decomp: module=unk_autoload_0 addr=0x0232987c name=FUN_0232987c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232987c --addr 0x0232987c --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232987c(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_02329898 + 8) = 0xb;
    FUN_02329b2c(DAT_0232989c,1);
  }
  return;
}

