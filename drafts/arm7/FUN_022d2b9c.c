// decomp: module=arm7 addr=0x022d2b9c name=FUN_022d2b9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, arm
// triage: noise=6 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022d2b9c --addr 0x022d2b9c --size 0x44 --module arm7 --version 2.0/sp1


void FUN_022d2b9c(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0xd;
  puVar1[1] = 1;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  puVar1[5] = param_4;
  func_0x037d1464();
  return;
}

