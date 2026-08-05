// decomp: module=arm7 addr=0x022d3aa0 name=FUN_022d3aa0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34, arm
// triage: noise=4 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022d3aa0 --addr 0x022d3aa0 --size 0x34 --module arm7 --version 2.0/sp1


void FUN_022d3aa0(undefined2 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x1e;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  func_0x037d1464();
  return;
}

