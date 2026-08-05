// decomp: module=arm7 addr=0x022d9b60 name=FUN_022d9b60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022d9b60 --addr 0x022d9b60 --size 0x90 --module arm7 --version 2.0/sp1


void FUN_022d9b60(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar3 = (uint)*(ushort *)(param_1 + 2);
  iVar4 = uVar3 * 0x1c + *(int *)(*DAT_022d9bec + 0x31c);
  uVar2 = func_0x037c9084(0x1000000);
  sVar1 = *(short *)(*DAT_022d9bec + 0x350);
  bVar5 = sVar1 == 1;
  if (bVar5) {
    sVar1 = *(short *)(iVar4 + 0x16);
  }
  if (bVar5 && sVar1 == 0) {
    FUN_022da128(uVar3);
  }
  *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + 1;
  func_0x037c904c(uVar2);
  if (((uint)*(ushort *)(*DAT_022d9bec + 0x534) & 1 << (uVar3 & 0xff)) == 0) {
    *(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)(iVar4 + 0x1a);
  }
  return;
}

