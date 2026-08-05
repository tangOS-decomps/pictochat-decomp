// decomp: module=arm7 addr=0x022d5e9c name=FUN_022d5e9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1ac (Ghidra's cache says 0x1a0 - it excludes this function's trailing literal pool), arm
// triage: noise=14 statements=75
// verify:  python tools/match.py --c <file> --func FUN_022d5e9c --addr 0x022d5e9c --size 0x1ac --module arm7 --version 2.0/sp1


void FUN_022d5e9c(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  
  puVar6 = *(undefined2 **)(DAT_022d603c + 0x550);
  iVar5 = *(int *)(DAT_022d603c + 0x54c);
  uVar3 = func_0x037cb520();
  iVar4 = *(int *)(puVar6 + 6);
  if (iVar4 == 1) {
    *(undefined4 *)(puVar6 + 6) = 0;
    FUN_022d3bd4();
    FUN_022ce658();
  }
  puVar6[0xc1] = 0;
  puVar6[0x43] = 0;
  *(undefined4 *)(puVar6 + 10) = 0;
  *(undefined4 *)(puVar6 + 8) = 0;
  *(undefined4 *)(puVar6 + 0xe) = 0;
  puVar6[0x67] = 0;
  puVar6[0x61] = 0;
  puVar6[0x2c] = 1;
  puVar6[0x2d] = 1;
  puVar6[0x2e] = 6;
  puVar6[0x4c] = 0;
  puVar6[0x49] = 0;
  puVar6[0x4a] = 0;
  puVar6[0x4d] = 0;
  puVar6[0x4e] = 0;
  puVar6[0x3e0] = puVar6[0x2c];
  puVar6[0x3e1] = puVar6[0x2d];
  puVar6[0x3e2] = puVar6[0x2e];
  puVar6[0x3e5] = puVar6[0x4c];
  puVar6[0x3e3] = puVar6[0x49];
  puVar6[0x3e4] = puVar6[0x4a];
  puVar6[0x3e6] = puVar6[0x4d];
  *(undefined4 *)(puVar6 + 0xcc) = 0;
  puVar6[0xcb] = 0;
  func_0x037cb820(puVar6 + 0xce,0,0x50);
  FUN_022ce784();
  puVar6[0x20] = 0x104;
  puVar6[0x21] = 0xf0;
  puVar6[0x22] = 1000;
  uVar2 = DAT_022d6040;
  puVar6[0x23] = 0;
  *(undefined4 *)(puVar6 + 0x24) = uVar2;
  *(undefined4 *)(puVar6 + 0x26) = 0;
  *(undefined4 *)(puVar6 + 0x28) = 0;
  *(undefined4 *)(puVar6 + 0x2a) = 0;
  puVar6[99] = 0;
  puVar6[0xf7] = 1;
  *(uint *)(puVar6 + 100) = param_1;
  func_0x037cb534(uVar3);
  if (iVar4 == 1) {
    FUN_022d5870(DAT_022d6044);
  }
  iVar4 = 0;
  do {
    iVar1 = iVar4 * 0x10;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar5 + iVar1 + 0xd0) = 0x8000;
  } while (iVar4 < 0x20);
  func_0x037cb774(1,puVar6 + 0xfc,0x100);
  FUN_022cfcd8();
  func_0x037ca02c(puVar6 + 0x38e);
  FUN_022d3bc0();
  if ((param_1 & 2) == 0) {
    thunk_EXT_FUN_03802630(0xf);
  }
  *puVar6 = 1;
  return;
}

