// decomp: module=arm7 addr=0x022c5c80 name=FUN_022c5c80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x110 (Ghidra's cache says 0x10c - it excludes this function's trailing literal pool), arm
// triage: noise=19 statements=66
// verify:  python tools/match.py --c <file> --func FUN_022c5c80 --addr 0x022c5c80 --size 0x110 --module arm7 --version 2.0/sp1


undefined4 * FUN_022c5c80(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  
  uVar1 = FUN_022c6d40();
  piVar4 = *(int **)(DAT_022c5d8c + param_1 * 4);
  if (piVar4 == (int *)0x0) {
    FUN_022c6d54();
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (param_2 < 0) {
      param_2 = *piVar4;
    }
    iVar7 = param_2 * 0xc + piVar4[4];
    uVar8 = param_3 + 0x3fU & 0xffffffe0;
    for (puVar2 = *(undefined4 **)(iVar7 + 4);
        (puVar2 != (undefined4 *)0x0 && ((int)puVar2[2] < (int)uVar8));
        puVar2 = (undefined4 *)puVar2[1]) {
    }
    if (puVar2 == (undefined4 *)0x0) {
      FUN_022c6d54(uVar1);
      puVar2 = (undefined4 *)0x0;
    }
    else {
      iVar5 = puVar2[2];
      if (iVar5 - uVar8 < 0x40) {
        uVar3 = FUN_022c5bb0(*(undefined4 **)(iVar7 + 4),puVar2);
        *(undefined4 *)(iVar7 + 4) = uVar3;
      }
      else {
        puVar2[2] = uVar8;
        piVar4 = (int *)((int)puVar2 + uVar8);
        piVar4[2] = iVar5 - uVar8;
        *(undefined4 *)((int)puVar2 + uVar8) = *puVar2;
        puVar6 = (undefined4 *)puVar2[1];
        piVar4[1] = (int)puVar6;
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = piVar4;
        }
        if (*piVar4 == 0) {
          *(int **)(iVar7 + 4) = piVar4;
        }
        else {
          *(int **)(*piVar4 + 4) = piVar4;
        }
      }
      puVar6 = *(undefined4 **)(iVar7 + 8);
      *puVar2 = 0;
      puVar2[1] = puVar6;
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = puVar2;
      }
      *(undefined4 **)(iVar7 + 8) = puVar2;
      FUN_022c6d54(uVar1);
      puVar2 = puVar2 + 8;
    }
  }
  return puVar2;
}

