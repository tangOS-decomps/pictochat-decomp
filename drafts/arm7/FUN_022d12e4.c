// decomp: module=arm7 addr=0x022d12e4 name=FUN_022d12e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, arm
// triage: noise=4 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022d12e4 --addr 0x022d12e4 --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022d12e4(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 8;
  puVar1[1] = 1;
  puVar1[4] = 0;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  func_0x037d1464();
  return;
}

