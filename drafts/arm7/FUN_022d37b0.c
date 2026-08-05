// decomp: module=arm7 addr=0x022d37b0 name=FUN_022d37b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, arm
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d37b0 --addr 0x022d37b0 --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022d37b0(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x1b;
  puVar1[1] = 4;
  func_0x037d1464();
  return;
}

