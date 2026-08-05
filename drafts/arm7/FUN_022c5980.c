// decomp: module=arm7 addr=0x022c5980 name=FUN_022c5980
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, arm
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022c5980 --addr 0x022c5980 --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022c5980(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x70);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x6c) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x10) = param_2;
  }
  *(int *)(param_2 + 0x14) = iVar1;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(int *)(param_1 + 0x70) = param_2;
  return;
}

