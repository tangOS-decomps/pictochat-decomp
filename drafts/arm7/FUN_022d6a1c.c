// decomp: module=arm7 addr=0x022d6a1c name=FUN_022d6a1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1d0 (Ghidra's cache says 0x1c0 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=61
// verify:  python tools/match.py --c <file> --func FUN_022d6a1c --addr 0x022d6a1c --size 0x1d0 --module arm7 --version 2.0/sp1


undefined2 FUN_022d6a1c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  uVar3 = DAT_022d6be0;
  iVar4 = *param_1;
  *DAT_022d6bdc = iVar4;
  local_c = param_4;
  func_0x037cb7d4(0,iVar4,uVar3);
  uVar3 = func_0x037c939c();
  piVar1 = DAT_022d6bdc;
  *(undefined4 *)(*DAT_022d6bdc + 0x314) = uVar3;
  *(int *)(*piVar1 + 0x30c) = param_1[6];
  *(uint *)(*piVar1 + 0x310) = (uint)param_1[7] >> 1;
  if (*(int *)(*piVar1 + 0x310) == 0) {
    *(undefined4 *)(*piVar1 + 0x310) = 0xffffffff;
  }
  FUN_022d6ca8(param_1 + 8);
  FUN_022e2f20();
  puVar2 = DAT_022d6be4;
  piVar1 = DAT_022d6bdc;
  *DAT_022d6be4 = *DAT_022d6be4 | 2;
  puVar2[-0x7f] = 0x30;
  *(undefined4 *)(*piVar1 + 0x68c) = 3;
  FUN_022e2e4c(0x3c,2,*piVar1 + 0x692);
  FUN_022e2e4c(0x3e,2,*DAT_022d6bdc + 0x690);
  piVar1 = DAT_022d6bdc;
  *(int *)(*DAT_022d6bdc + 0x308) = param_1[4];
  *(int *)(*piVar1 + 0x304) = param_1[5];
  uVar3 = func_0x037c8a00(param_1[0xc],0x1c);
  FUN_022d6e18(param_1[0xb],uVar3);
  FUN_022d6c00();
  FUN_022da700();
  FUN_022dc0cc();
  FUN_022da490();
  FUN_022d8984();
  iVar4 = FUN_022e2d50(auStack_10);
  if (iVar4 == 0) {
    FUN_022d86ec();
    FUN_022d923c();
    FUN_022d7db8();
    FUN_022d875c();
    FUN_022d87fc();
    FUN_022d93e0();
    FUN_022d956c();
    FUN_022d8794();
    FUN_022d77ec();
    FUN_022d7d30();
  }
  else {
    *(ushort *)(*DAT_022d6bdc + 0x33e) = *(ushort *)(*DAT_022d6bdc + 0x33e) | 0x80;
  }
  func_0x037c9818(*DAT_022d6bdc + 0x18,DAT_022d6be8,0,param_1[1],param_1[2],param_1[3]);
  func_0x037c9b30(*DAT_022d6bdc + 0x18);
  FUN_022d98d8();
  return *(undefined2 *)(*DAT_022d6bdc + 0x33e);
}

