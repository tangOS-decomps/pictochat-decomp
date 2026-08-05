// decomp: module=arm7 addr=0x022d7e6c name=FUN_022d7e6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022d7e6c --addr 0x022d7e6c --size 0x64 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7e6c(int param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *DAT_022d7ec8;
  uVar1 = (undefined2)DAT_022d7ecc;
  if (param_1 == DAT_022d7ecc) {
    *(undefined2 *)(iVar3 + 0x338) = uVar1;
    *(undefined2 *)(iVar3 + 0x3d0) = uVar1;
  }
  else {
    uVar2 = func_0x037c8a00(param_1 * (uint)*(ushort *)(iVar3 + 0x3b2),100);
    if (0x10000 < uVar2) {
      return 5;
    }
    *(short *)(iVar3 + 0x338) = (short)param_1;
    *(short *)(iVar3 + 0x3d0) = (short)uVar2;
  }
  return 0;
}

