// decomp: module=arm7 addr=0x022d69ac name=FUN_022d69ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, arm
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d69ac --addr 0x022d69ac --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022d69ac(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x2a;
  puVar1[1] = 4;
  func_0x037d1464();
  return;
}

