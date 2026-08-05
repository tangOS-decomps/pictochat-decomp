// decomp: module=unk_autoload_0 addr=0x0232cae8 name=FUN_0232cae8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, thumb
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232cae8 --addr 0x0232cae8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cae8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232c4f0();
  if (iVar1 == 0) {
    FUN_0232c3bc(1,param_1);
    iVar1 = FUN_0232c408(1,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

