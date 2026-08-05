// decomp: module=arm7 addr=0x022d7020 name=FUN_022d7020
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x94 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022d7020 --addr 0x022d7020 --size 0xa0 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7020(uint param_1)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = *DAT_022d70b4;
  if (3 < param_1) {
    return 5;
  }
  *(short *)(iVar3 + 0x334) = (short)param_1;
  puVar1 = DAT_022d70b8;
  if (param_1 == 0) {
    *(ushort *)(iVar3 + 0x3c0) = *(ushort *)(iVar3 + 0x3c0) & 0xffef;
    uVar2 = *(ushort *)(iVar3 + 0x3ce) & 0xbfff;
    puVar1 = DAT_022d70b8;
  }
  else {
    *(ushort *)(iVar3 + 0x3c0) = *(ushort *)(iVar3 + 0x3c0) | 0x10;
    uVar2 = *(ushort *)(iVar3 + 0x3ce) | 0x4000;
  }
  *(ushort *)(iVar3 + 0x3ce) = uVar2;
  if (*(short *)(iVar3 + 0x34c) == 0x40 && param_1 == 1) {
    *(undefined2 *)(*(int *)(*DAT_022d70b4 + 0x4ac) + 0x2e) = *(undefined2 *)(iVar3 + 0x3c0);
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  *puVar1 = *puVar1 & (ushort)DAT_022d70bc | (ushort)(param_1 << 3);
  return 0;
}

