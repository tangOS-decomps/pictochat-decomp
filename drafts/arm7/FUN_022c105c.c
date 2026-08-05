// decomp: module=arm7 addr=0x022c105c name=FUN_022c105c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xbc - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=42
// verify:  python tools/match.py --c <file> --func FUN_022c105c --addr 0x022c105c --size 0xc0 --module arm7 --version 2.0/sp1


undefined4 FUN_022c105c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(ushort *)((int)param_2 + 10) == DAT_022c1118) {
    if ((short)param_2[2] == *(short *)((int)param_1 + 10)) {
      FUN_022c48a4(0x1000000);
      *(short *)(param_1 + 2) = (short)param_1[2] + -1;
      if ((short)param_1[2] == 0) {
        *param_1 = -1;
        param_1[1] = -1;
      }
      else if (param_2 == (int *)*param_1) {
        puVar2 = (undefined4 *)param_2[1];
        *param_1 = (int)puVar2;
        *puVar2 = 0xffffffff;
      }
      else {
        iVar3 = *param_2;
        if (param_2 == (int *)param_1[1]) {
          param_1[1] = iVar3;
          *(undefined4 *)(iVar3 + 4) = 0xffffffff;
        }
        else {
          *(int *)param_2[1] = iVar3;
          *(int *)(*param_2 + 4) = param_2[1];
        }
      }
      *(undefined2 *)(param_2 + 2) = 0;
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

