// decomp: module=unk_autoload_0 addr=0x023298c0 name=FUN_023298c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023298c0 --addr 0x023298c0 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_023298c0(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 != 0) {
    FUN_02329b2c(DAT_023298d4,1);
  }
  return;
}

