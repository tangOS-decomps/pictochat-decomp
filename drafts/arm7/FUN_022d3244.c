// decomp: module=arm7 addr=0x022d3244 name=FUN_022d3244
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=28
// verify:  python tools/match.py --c <file> --func FUN_022d3244 --addr 0x022d3244 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022d3244(int param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 8);
  puVar4 = *(undefined2 **)(DAT_022d32cc + 0x550);
  iVar5 = *(int *)(param_1 + 4);
  uVar1 = func_0x037cb520();
  *(int *)(puVar4 + 0x58) = iVar5;
  puVar4[0x5c] = (short)uVar3;
  *(uint *)(puVar4 + 0x5a) = iVar5 + (uVar3 & 0xffff);
  puVar4[0x57] = 0;
  *(undefined4 *)(puVar4 + 0x54) = 0;
  puVar4[0x56] = 0;
  *(undefined4 *)(puVar4 + 0xc) = 0;
  *puVar4 = 0xb;
  puVar2 = (undefined2 *)func_0x037d14bc();
  *puVar2 = 0x11;
  puVar2[1] = 0;
  puVar2[2] = 0xe;
  func_0x037d1464();
  *(undefined4 *)(puVar4 + 8) = 1;
  func_0x037cb534(uVar1);
  return;
}

