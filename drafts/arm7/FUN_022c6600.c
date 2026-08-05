// decomp: module=arm7 addr=0x022c6600 name=FUN_022c6600
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x84 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=32
// verify:  python tools/match.py --c <file> --func FUN_022c6600 --addr 0x022c6600 --size 0x88 --module arm7 --version 2.0/sp1


void FUN_022c6600(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_022c6d40();
  if (*param_1 == 0) {
    FUN_022c6d54();
  }
  else {
    iVar2 = param_1[6];
    if (iVar2 == 0) {
      *(int *)(DAT_022c6684 + 8) = param_1[5];
    }
    else {
      *(int *)(iVar2 + 0x14) = param_1[5];
    }
    if (param_1[5] == 0) {
      *(int *)(DAT_022c6684 + 4) = iVar2;
      if (iVar2 != 0) {
        FUN_022c6300();
      }
    }
    else {
      *(int *)(param_1[5] + 0x18) = iVar2;
    }
    *param_1 = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    FUN_022c6d54(uVar1);
  }
  return;
}

