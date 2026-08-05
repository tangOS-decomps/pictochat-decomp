// decomp: module=arm7 addr=0x022c12a4 name=FUN_022c12a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=32
// verify:  python tools/match.py --c <file> --func FUN_022c12a4 --addr 0x022c12a4 --size 0x8c --module arm7 --version 2.0/sp1


undefined4 FUN_022c12a4(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(ushort *)((int)param_2 + 10) == DAT_022c132c) {
    if ((short)param_2[2] == 0) {
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
      *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)param_1 + 10);
      param_1[1] = param_2;
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
      FUN_022c486c();
      uVar1 = 0;
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

