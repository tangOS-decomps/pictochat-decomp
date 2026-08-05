// decomp: module=unk_autoload_0 addr=0x0232ae88 name=FUN_0232ae88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ae88 --addr 0x0232ae88 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ae88(void)

{
  int iVar1;
  
  iVar1 = FUN_0232cc3c(DAT_0232ae9c);
  if (iVar1 != 2) {
    FUN_02329bd8(0xc);
  }
  return;
}

