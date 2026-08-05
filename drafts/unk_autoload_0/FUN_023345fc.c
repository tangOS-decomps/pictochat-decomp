// decomp: module=unk_autoload_0 addr=0x023345fc name=FUN_023345fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x12, thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023345fc --addr 0x023345fc --size 0x12 --module unk_autoload_0 --version 2.0/sp1


int FUN_023345fc(short *param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = -1;
  do {
    sVar1 = *param_1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
  } while (sVar1 != 0);
  return iVar2;
}

