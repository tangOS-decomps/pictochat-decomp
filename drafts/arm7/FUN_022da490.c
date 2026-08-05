// decomp: module=arm7 addr=0x022da490 name=FUN_022da490
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022da490 --addr 0x022da490 --size 0x9c --module arm7 --version 2.0/sp1


void FUN_022da490(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 in_r3;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *DAT_022da520;
  uVar1 = *(ushort *)(iVar3 + 0x322);
  iVar5 = *(int *)(iVar3 + 0x31c);
  func_0x037cb774(0,iVar5,(uint)uVar1 * 0x1c,iVar3,in_r3);
  func_0x037cb774(0,*DAT_022da520 + 0x52c,0x10);
  uVar2 = (undefined2)DAT_022da524;
  *(undefined2 *)(iVar5 + 0x1a) = uVar2;
  for (uVar4 = 1; uVar4 < uVar1; uVar4 = uVar4 + 1) {
    *(undefined2 *)(uVar4 * 0x1c + iVar5 + 0x1a) = uVar2;
  }
  FUN_022da5b4(0,DAT_022da528);
  FUN_022d9c60(0,0x40);
  return;
}

