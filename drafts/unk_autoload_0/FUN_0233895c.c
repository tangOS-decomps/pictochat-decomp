// decomp: module=unk_autoload_0 addr=0x0233895c name=FUN_0233895c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc4 (Ghidra's cache says 0xc0 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=57
// verify:  python tools/match.py --c <file> --func FUN_0233895c --addr 0x0233895c --size 0xc4 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0233895c(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  iVar5 = param_1[2];
  if ((param_1[3] & 1) != 0) {
    FUN_02332274();
  }
  if (iVar5 == 0) {
    param_1[5] = 6;
    return 0;
  }
  param_1[5] = 2;
  param_1[3] = param_2 << 8 | DAT_02338a1c & param_1[3] | 1;
  *param_1 = 0;
  if (param_3 != 0) {
    param_1[3] = param_1[3] | 4;
  }
  uVar4 = FUN_02332080();
  if ((*(uint *)(iVar5 + 0x14) & 0x80) == 0) {
    puVar3 = *(undefined4 **)(iVar5 + 8);
    puVar2 = (undefined4 *)(iVar5 + 8);
    while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
      puVar2 = puVar1;
      puVar3 = (undefined4 *)*puVar1;
    }
    *puVar2 = param_1;
  }
  else {
    FUN_0233846c(param_1,3);
  }
  FUN_02332094(uVar4);
  if (param_1[5] != 3) {
    iVar5 = FUN_0233879c(iVar5,0);
    if (param_3 == 0) {
      if (iVar5 != 0) {
        FUN_023388b4();
      }
      uVar6 = 1;
    }
    else {
      FUN_02338908(param_1);
      if (param_1[5] == 0) {
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
    }
  }
  return uVar6;
}

