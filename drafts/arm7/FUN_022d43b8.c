// decomp: module=arm7 addr=0x022d43b8 name=FUN_022d43b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8 (Ghidra's cache says 0xb0 - it excludes this function's trailing literal pool), arm
// triage: noise=12 statements=35
// verify:  python tools/match.py --c <file> --func FUN_022d43b8 --addr 0x022d43b8 --size 0xb8 --module arm7 --version 2.0/sp1


void FUN_022d43b8(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(DAT_022d4468 + 0x550);
  func_0x037ca044(iVar6 + 0x71c);
  func_0x037cb774(0,iVar6 + 0x2f8,0x400);
  uVar5 = 0;
  do {
    uVar3 = uVar5 + 1;
    iVar4 = uVar5 * 0x20;
    uVar5 = uVar3 & 0xffff;
    uVar1 = (undefined2)(uVar3 * 0x10000 >> 0x10);
    *(undefined2 *)(iVar6 + iVar4 + 0x2f8) = uVar1;
  } while (uVar5 < 0x1f);
  uVar2 = (undefined2)DAT_022d446c;
  *(undefined2 *)(iVar6 + uVar5 * 0x20 + 0x2f8) = uVar2;
  uVar5 = 0;
  *(undefined2 *)(iVar6 + 0x6f8) = 0;
  *(undefined2 *)(iVar6 + 0x6fa) = uVar1;
  do {
    iVar4 = iVar6 + uVar5 * 4;
    *(undefined2 *)(iVar4 + 0x70c) = uVar2;
    *(undefined2 *)(iVar4 + 0x70e) = uVar2;
    *(undefined2 *)(iVar4 + 0x6fc) = uVar2;
    uVar5 = uVar5 + 1 & 0xffff;
    *(undefined2 *)(iVar4 + 0x6fe) = uVar2;
  } while (uVar5 < 4);
  func_0x037ca0c8(iVar6 + 0x71c);
  return;
}

