// decomp: module=unk_autoload_0 addr=0x02329858 name=FUN_02329858
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02329858 --addr 0x02329858 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329858(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_02329874 + 8) = 0;
    FUN_02329b2c(DAT_02329878,1);
  }
  return;
}

