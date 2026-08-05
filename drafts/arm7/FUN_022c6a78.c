// decomp: module=arm7 addr=0x022c6a78 name=FUN_022c6a78
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c, arm
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022c6a78 --addr 0x022c6a78 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022c6a78(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_022c6d40();
  param_1[9] = 1;
  if (*param_1 == 0) {
    FUN_022c6d54();
  }
  else {
    FUN_022c688c(param_1);
    *param_1 = 0;
    FUN_022c6d54(uVar1);
  }
  return;
}

