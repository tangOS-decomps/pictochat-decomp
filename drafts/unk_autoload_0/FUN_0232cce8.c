// decomp: module=unk_autoload_0 addr=0x0232cce8 name=FUN_0232cce8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, thumb
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232cce8 --addr 0x0232cce8 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cce8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232c520(1,5);
  if (iVar1 == 0) {
    FUN_0232c3bc(0xb,param_1);
    iVar1 = FUN_0232c408(0xb,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

