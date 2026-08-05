// decomp: module=arm7 addr=0x022c4a9c name=FUN_022c4a9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, arm
// triage: noise=4 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022c4a9c --addr 0x022c4a9c --size 0x74 --module arm7 --version 2.0/sp1


int FUN_022c4a9c(undefined4 param_1,int param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_4 == 0) {
    uVar1 = FUN_022c6d40();
  }
  else {
    uVar1 = FUN_022c6d6c();
  }
  iVar2 = FUN_022c7204(param_1,param_2);
  if (iVar2 == 0) {
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *(short *)(param_2 + 4) = (short)param_1;
  }
  if (param_4 == 0) {
    FUN_022c6d54(uVar1);
  }
  else {
    FUN_022c6d80();
  }
  return iVar2;
}

