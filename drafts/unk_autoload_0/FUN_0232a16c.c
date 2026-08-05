// decomp: module=unk_autoload_0 addr=0x0232a16c name=FUN_0232a16c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232a16c --addr 0x0232a16c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a16c(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if ((iVar1 == 0) && (iVar1 = FUN_0232cce8(DAT_0232a188), iVar1 != 2)) {
    FUN_02329bd8(0xc);
  }
  return;
}

