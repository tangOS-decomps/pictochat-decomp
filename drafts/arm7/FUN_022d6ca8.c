// decomp: module=arm7 addr=0x022d6ca8 name=FUN_022d6ca8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd8 (Ghidra's cache says 0xd4 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=27
// verify:  python tools/match.py --c <file> --func FUN_022d6ca8 --addr 0x022d6ca8 --size 0xd8 --module arm7 --version 2.0/sp1


void FUN_022d6ca8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *DAT_022d6d7c;
  *(undefined4 *)(iVar3 + 0x17c) = *param_1;
  *(undefined4 *)(iVar3 + 0x180) = param_1[1];
  uVar2 = param_1[2];
  *(undefined4 *)(iVar3 + 0x184) = uVar2;
  FUN_022d6c8c(iVar3 + 0x188,2,uVar2,param_4,param_4);
  FUN_022d6c8c(iVar3 + 0x194,3);
  FUN_022d6c8c(iVar3 + 0x1a0,4);
  FUN_022d6c8c(iVar3 + 0x1ac,5);
  FUN_022d6c8c(iVar3 + 0x1b8,6);
  FUN_022d6c8c(iVar3 + 0x1c4,7);
  FUN_022d6c8c(iVar3 + 0x1d0,8);
  FUN_022d6c8c(iVar3 + 0x1dc,9);
  FUN_022d6c8c(iVar3 + 0x1e8,10);
  FUN_022d6c8c(iVar3 + 500,0xb);
  FUN_022d6c8c(iVar3 + 0x200,0xc);
  iVar1 = func_0x037c58fc(iVar3 + 0x188,0x81);
  *(int *)(iVar3 + 0x3e0) = iVar1 + 0xc;
  *(undefined2 *)(iVar3 + 0x3e4) = 0;
  *(undefined2 *)(iVar3 + 1000) = 0;
  return;
}

