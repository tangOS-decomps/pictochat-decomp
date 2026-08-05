// decomp: module=arm7 addr=0x022d5e4c name=FUN_022d5e4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022d5e4c --addr 0x022d5e4c --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022d5e4c(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_022d5e98;
  puVar4 = *(undefined4 **)(param_1 + 4);
  *(undefined4 **)(DAT_022d5e98 + 0x54c) = puVar4;
  uVar3 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(iVar1 + 0x550) = uVar3;
  *puVar4 = uVar3;
  puVar4[2] = *(undefined4 *)(param_1 + 0xc);
  FUN_022d5e9c(*(undefined4 *)(param_1 + 0x10));
  puVar2 = (undefined2 *)func_0x037d14bc();
  *puVar2 = 3;
  puVar2[1] = 0;
  func_0x037d1464();
  return;
}

