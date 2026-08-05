// decomp: module=arm7 addr=0x022d6c00 name=FUN_022d6c00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=34
// verify:  python tools/match.py --c <file> --func FUN_022d6c00 --addr 0x022d6c00 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022d6c00(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = DAT_022d6c84;
  uVar5 = 0;
  iVar6 = *DAT_022d6c80;
  *(undefined2 *)(iVar6 + 0x10) = 0;
  *(undefined2 *)(iVar6 + 0x12) = 0;
  do {
    iVar3 = iVar6 + uVar5 * 2;
    *(short *)(iVar3 + 8) = (short)uVar4;
    iVar1 = uVar5 * 2;
    uVar5 = uVar5 + 1;
    *(undefined2 *)(iVar6 + iVar1) = *(undefined2 *)(iVar3 + 8);
    iVar1 = DAT_022d6c88;
    uVar2 = DAT_022d6c84;
  } while (uVar5 < 4);
  uVar5 = 0;
  do {
    iVar3 = iVar6 + uVar5 * 8;
    *(short *)(iVar3 + 0xbc) = (short)uVar2;
    uVar4 = *(undefined4 *)(iVar1 + uVar5 * 4);
    *(undefined2 *)(iVar3 + 0xbe) = 0;
    uVar5 = uVar5 + 1;
    *(undefined4 *)(iVar3 + 0xc0) = uVar4;
  } while (uVar5 < 0x18);
  func_0x037c5628(3,0xc);
  return;
}

