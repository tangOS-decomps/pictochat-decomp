// decomp: module=unk_autoload_0 addr=0x02337b54 name=FUN_02337b54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x114 (Ghidra's cache says 0x106 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=65
// verify:  python tools/match.py --c <file> --func FUN_02337b54 --addr 0x02337b54 --size 0x114 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02337b54(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_02332080();
  iVar1 = DAT_02337c5c;
  if (*(int *)(DAT_02337c5c + 8) == 0) {
    FUN_02332094();
    return 1;
  }
  if (7 < *(int *)(DAT_02337c5c + 0x1c)) {
    if ((param_1 & 1) == 0) {
      FUN_02332094();
      return 0;
    }
    do {
      FUN_02337a28(1);
    } while (7 < *(int *)(iVar1 + 0x1c));
    if (*(int *)(DAT_02337c5c + 8) == 0) {
      FUN_02332094(uVar3);
      return 1;
    }
  }
  FUN_02331504(DAT_02337c60,0x1800);
  iVar4 = FUN_0233831c(7,*(undefined4 *)(DAT_02337c5c + 8),0);
  uVar2 = DAT_02337c60;
  iVar1 = DAT_02337c5c;
  if (iVar4 < 0) {
    if ((param_1 & 1) == 0) {
      FUN_02332094(uVar3);
      return 0;
    }
    while ((7 < *(int *)(iVar1 + 0x1c) ||
           (iVar4 = FUN_0233831c(7,*(undefined4 *)(iVar1 + 8),0), iVar4 < 0))) {
      FUN_02332094(uVar3);
      FUN_02337a28(0);
      uVar3 = FUN_02332080();
      FUN_02331504(uVar2,0x1800);
      if (*(int *)(iVar1 + 8) == 0) {
        FUN_02332094(uVar3);
        return 1;
      }
    }
  }
  iVar1 = DAT_02337c5c;
  iVar4 = *(int *)(DAT_02337c5c + 0x18);
  *(undefined4 *)(DAT_02337c64 + iVar4 * 4) = *(undefined4 *)(DAT_02337c5c + 8);
  iVar4 = iVar4 + 1;
  *(int *)(iVar1 + 0x18) = iVar4;
  if (8 < iVar4) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
  }
  iVar1 = DAT_02337c5c;
  *(undefined4 *)(DAT_02337c5c + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
  *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + 1;
  FUN_02332094(uVar3);
  if ((param_1 & 2) != 0) {
    FUN_02337dc0();
  }
  return 1;
}

