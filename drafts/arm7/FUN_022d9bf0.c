// decomp: module=arm7 addr=0x022d9bf0 name=FUN_022d9bf0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022d9bf0 --addr 0x022d9bf0 --size 0x70 --module arm7 --version 2.0/sp1


void FUN_022d9bf0(int param_1)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  uVar1 = *(ushort *)(param_1 + 2);
  iVar4 = (uint)uVar1 * 0x1c + *(int *)(*DAT_022d9c5c + 0x31c);
  uVar3 = func_0x037c9084(0x1000000);
  sVar2 = *(short *)(*DAT_022d9c5c + 0x350);
  bVar5 = sVar2 == 1;
  if (bVar5) {
    sVar2 = *(short *)(iVar4 + 0x16);
  }
  if (bVar5 && sVar2 == 1) {
    FUN_022da1e4((uint)uVar1);
  }
  *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + -1;
  func_0x037c904c(uVar3);
  return;
}

