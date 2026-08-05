// decomp: module=arm7 addr=0x022d1dbc name=FUN_022d1dbc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, arm
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022d1dbc --addr 0x022d1dbc --size 0x48 --module arm7 --version 2.0/sp1


void FUN_022d1dbc(undefined2 param_1,undefined2 param_2,int param_3)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  puVar1 = (undefined2 *)func_0x037d14bc();
  if (param_3 == 0) {
    uVar2 = 10;
  }
  else {
    uVar2 = 0x26;
  }
  *puVar1 = uVar2;
  puVar1[1] = 1;
  puVar1[4] = 4;
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  func_0x037d1464();
  return;
}

