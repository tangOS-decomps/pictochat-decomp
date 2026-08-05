// decomp: module=arm7 addr=0x022e2e4c name=FUN_022e2e4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022e2e4c --addr 0x022e2e4c --size 0x60 --module arm7 --version 2.0/sp1


void FUN_022e2e4c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(*DAT_022e2ea8 + 0x318) != 0) {
    iVar2 = *(int *)(*DAT_022e2ea8 + 0x318) + param_1 + -0x2a;
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar1 = FUN_022d8d6c(iVar2);
      iVar2 = iVar2 + 1;
      FUN_022d8d40(param_3,uVar1);
      param_3 = param_3 + 1;
    }
  }
  return;
}

