// decomp: module=arm7 addr=0x022d30f4 name=FUN_022d30f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x11c (Ghidra's cache says 0x110 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=52
// verify:  python tools/match.py --c <file> --func FUN_022d30f4 --addr 0x022d30f4 --size 0x11c --module arm7 --version 2.0/sp1


void FUN_022d30f4(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined1 auStack_210 [512];
  
  psVar5 = *(short **)(DAT_022d3204 + 0x550);
  if (*psVar5 == 9 || *psVar5 == 10) {
    uVar2 = func_0x037cb520();
    iVar4 = *(int *)(psVar5 + 6);
    psVar5[6] = 0;
    psVar5[7] = 0;
    FUN_022d3bd4();
    FUN_022ce658();
    if (*psVar5 == 10) {
      *psVar5 = 8;
    }
    else if (*psVar5 == 9) {
      *psVar5 = 7;
    }
    func_0x037cb534(uVar2);
    iVar3 = FUN_022d073c(auStack_210,0);
    if (*(short *)(iVar3 + 4) == 0) {
      iVar3 = FUN_022d03e8(auStack_210,7);
      if (*(short *)(iVar3 + 4) == 0) {
        psVar5[0x45] = 0;
        if (iVar4 == 1) {
          FUN_022d5870(DAT_022d320c);
        }
        puVar1 = (undefined2 *)func_0x037d14bc();
        *puVar1 = 0x10;
        puVar1[1] = 0;
        func_0x037d1464();
      }
      else {
        FUN_022d3210(0x104);
      }
    }
    else {
      FUN_022d3210(DAT_022d3208);
    }
  }
  else {
    puVar1 = (undefined2 *)func_0x037d14bc();
    *puVar1 = 0x10;
    puVar1[1] = 3;
    func_0x037d1464();
  }
  return;
}

