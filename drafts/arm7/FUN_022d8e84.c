// decomp: module=arm7 addr=0x022d8e84 name=FUN_022d8e84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022d8e84 --addr 0x022d8e84 --size 0x80 --module arm7 --version 2.0/sp1


bool FUN_022d8e84(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  uVar2 = DAT_022d8ef8;
  iVar6 = *(int *)(param_1 + 8);
  uVar5 = (uint)*(ushort *)(iVar6 + -4);
  bVar7 = uVar5 == DAT_022d8ef8;
  uVar1 = DAT_022d8ef8;
  if (bVar7) {
    uVar5 = (uint)*(ushort *)(iVar6 + -2);
    uVar1 = DAT_022d8efc;
  }
  if (!bVar7 || uVar5 != uVar1) {
    *(undefined2 *)(iVar6 + 10) = 1;
    uVar3 = DAT_022d8efc;
    *(short *)(iVar6 + -4) = (short)uVar2;
    *(short *)(iVar6 + -2) = (short)uVar3;
    piVar4 = DAT_022d8f00;
    iVar6 = *(int *)(param_1 + 8);
    *(short *)(iVar6 + 0xc) = (short)uVar2;
    *(short *)(iVar6 + 0xe) = (short)uVar3;
    *(short *)(*piVar4 + 0x3fa) = *(short *)(*piVar4 + 0x3fa) + 1;
  }
  return !bVar7 || uVar5 != uVar1;
}

