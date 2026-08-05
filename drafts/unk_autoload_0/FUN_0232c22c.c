// decomp: module=unk_autoload_0 addr=0x0232c22c name=FUN_0232c22c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x148 (Ghidra's cache says 0x134 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=58
// verify:  python tools/match.py --c <file> --func FUN_0232c22c --addr 0x0232c22c --size 0x148 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232c22c(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_02332080();
  if (*DAT_0232c360 != 0) {
    FUN_02332094();
    return 3;
  }
  if (param_1 == (int *)0x0) {
    FUN_02332094();
    return 6;
  }
  if (3 < param_2) {
    FUN_02332094();
    return 6;
  }
  if (((uint)param_1 & 0x1f) != 0) {
    FUN_02332094();
    return 6;
  }
  FUN_023381f8();
  iVar3 = FUN_023382f8(10,1);
  if (iVar3 == 0) {
    FUN_02332094(uVar2);
    return 4;
  }
  FUN_023314cc(param_1,param_3);
  FUN_023371e4(param_2,param_1,0,param_3,1,uVar2,param_4);
  psVar1 = DAT_0232c360;
  *(int **)(DAT_0232c360 + 2) = param_1;
  *param_1 = (int)(param_1 + 0x80);
  (*(int **)(psVar1 + 2))[1] = **(int **)(psVar1 + 2) + 0x300;
  *(int *)(*(int *)(psVar1 + 2) + 0xc) = *(int *)(*(int *)(psVar1 + 2) + 4) + 0x800;
  *(int *)(*(int *)(psVar1 + 2) + 0x10) = *(int *)(*(int *)(psVar1 + 2) + 0xc) + 0x100;
  FUN_0232c820();
  psVar1 = DAT_0232c360;
  *(short *)(*(int *)(DAT_0232c360 + 2) + 0x14) = (short)param_2;
  *(undefined4 *)(*(int *)(psVar1 + 2) + 0x14c) = 0;
  *(undefined2 *)(*(int *)(psVar1 + 2) + 0x150) = 0;
  for (iVar3 = 0; iVar3 < 0x10; iVar3 = iVar3 + 1) {
    *(undefined4 *)(*(int *)(psVar1 + 2) + iVar3 * 4 + 0xcc) = 0;
    *(undefined4 *)(*(int *)(psVar1 + 2) + iVar3 * 4 + 0x10c) = 0;
  }
  FUN_02331230(DAT_0232c364,DAT_0232c368,10);
  iVar3 = DAT_0232c36c;
  for (iVar4 = 0; iVar4 < 10; iVar4 = iVar4 + 1) {
    *(undefined2 *)(iVar3 + iVar4 * 0x100) = 0x8000;
    FUN_023314e8(iVar3 + iVar4 * 0x100,2);
    FUN_02331244(DAT_0232c364,iVar3 + iVar4 * 0x100,1);
  }
  FUN_023382ac(10,DAT_0232c370);
  *DAT_0232c360 = 1;
  FUN_02332094(uVar2);
  return 0;
}

