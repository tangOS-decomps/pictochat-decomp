// decomp: module=unk_autoload_0 addr=0x023393e0 name=FUN_023393e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe, thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_023393e0 --addr 0x023393e0 --size 0xe --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023393e0(void)

{
  int iVar1;
  
  do {
    iVar1 = FUN_023393b0();
  } while (iVar1 != 0);
  return 0;
}

