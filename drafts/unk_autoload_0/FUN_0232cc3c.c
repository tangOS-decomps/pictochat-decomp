// decomp: module=unk_autoload_0 addr=0x0232cc3c name=FUN_0232cc3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, thumb
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232cc3c --addr 0x0232cc3c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cc3c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232c520(1,7);
  if (iVar1 == 0) {
    FUN_0232c3bc(9,param_1);
    iVar1 = FUN_0232c408(9,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

