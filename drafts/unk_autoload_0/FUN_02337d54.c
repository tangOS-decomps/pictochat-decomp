// decomp: module=unk_autoload_0 addr=0x02337d54 name=FUN_02337d54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x16, thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337d54 --addr 0x02337d54 --size 0x16 --module unk_autoload_0 --version 2.0/sp1


int FUN_02337d54(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_02337d0c();
  iVar2 = FUN_02337d30();
  return (0x100 - iVar1) - iVar2;
}

