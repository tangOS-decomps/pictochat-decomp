// decomp: module=arm7 addr=0x022c0fec name=FUN_022c0fec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022c0fec --addr 0x022c0fec --size 0x70 --module arm7 --version 2.0/sp1


undefined4 FUN_022c0fec(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_022c48a4(0x1000000);
  if (*(short *)(param_1 + 2) == 0) {
    *param_2 = -1;
    *param_1 = param_2;
  }
  else {
    iVar2 = param_1[1];
    *param_2 = iVar2;
    *(int **)(iVar2 + 4) = param_2;
  }
  param_2[1] = -1;
  uVar1 = DAT_022c1058;
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)param_1 + 10);
  *(short *)((int)param_2 + 10) = (short)uVar1;
  param_1[1] = param_2;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  FUN_022c486c();
  return 0;
}

