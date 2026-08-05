// decomp: module=arm7 addr=0x022e2d50 name=FUN_022e2d50
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=33
// verify:  python tools/match.py --c <file> --func FUN_022e2d50 --addr 0x022e2d50 --size 0xa4 --module arm7 --version 2.0/sp1


undefined4 FUN_022e2d50(uint *param_1)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = (uint)*(ushort *)(*(int *)(*DAT_022e2dec + 0x318) + 2);
  if ((uVar5 < 0xa4) || (DAT_022e2df0 < uVar5)) {
    uVar3 = 2;
  }
  else {
    iVar6 = *(int *)(*DAT_022e2dec + 0x318) + 2;
    uVar4 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar2 = FUN_022d8d6c(iVar6);
      iVar6 = iVar6 + 1;
      uVar4 = FUN_022d8e04(uVar2,uVar4 & 0xffff);
    }
    uVar1 = **(ushort **)(*DAT_022e2dec + 0x318);
    if (param_1 != (uint *)0x0) {
      *param_1 = (uint)uVar1 | uVar4 << 0x10;
    }
    if (uVar4 == uVar1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

