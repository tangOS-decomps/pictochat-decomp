// decomp: module=unk_autoload_0 addr=0x0232b1c0 name=FUN_0232b1c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232b1c0 --addr 0x0232b1c0 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b1c0(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if ((iVar1 == 0) && (iVar1 = FUN_0232d050(DAT_0232b1dc), iVar1 != 2)) {
    FUN_02329bd8(0xc);
  }
  return;
}

