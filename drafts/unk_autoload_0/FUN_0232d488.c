// decomp: module=unk_autoload_0 addr=0x0232d488 name=FUN_0232d488
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232d488 --addr 0x0232d488 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d488(void)

{
  int iVar1;
  
  iVar1 = FUN_0232d4a0();
  while (iVar1 != 0) {
    FUN_0232d3fc();
    iVar1 = FUN_0232d4a0();
  }
  return;
}

