// decomp: module=arm7 addr=0x022c4efc name=FUN_022c4efc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x13c (Ghidra's cache says 0x104 - it excludes this function's trailing literal pool), arm
// triage: noise=23 statements=50
// verify:  python tools/match.py --c <file> --func FUN_022c4efc --addr 0x022c4efc --size 0x13c --module arm7 --version 2.0/sp1


void FUN_022c4efc(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 in_r3;
  int iVar6;
  
  uVar2 = DAT_022c5004;
  iVar1 = DAT_022c5000;
  if (*(int *)(DAT_022c5000 + 0xc) == 0) {
    *(undefined4 *)(DAT_022c5000 + 0xc) = 1;
    *(undefined4 *)(iVar1 + 8) = uVar2;
    *(undefined4 *)(iVar1 + 0x1ac) = 0x10;
    *(undefined4 *)(iVar1 + 0x1a8) = 0;
    *(undefined4 *)(iVar1 + 0x1a0) = 1;
    *(undefined4 *)(iVar1 + 0x1a4) = 0;
    uVar2 = DAT_022c500c;
    iVar3 = DAT_022c5008;
    *(undefined4 *)(iVar1 + 0x1b0) = 0;
    *(undefined4 *)(iVar1 + 0x24) = uVar2;
    *(undefined4 *)(iVar1 + 0x20) = uVar2;
    iVar1 = DAT_022c5000;
    iVar5 = DAT_022c5010;
    if (0 < iVar3) {
      iVar5 = DAT_022c5018 - DAT_022c5014;
    }
    iVar6 = DAT_022c5018 - DAT_022c5014;
    *(int *)(DAT_022c5000 + 0x1d0) = iVar6;
    *(int *)(iVar1 + 0x1cc) = iVar5 - iVar3;
    uVar2 = DAT_022c501c;
    *(undefined4 *)(iVar1 + 0x1d4) = 0;
    *(undefined4 *)(iVar6 + -8) = uVar2;
    uVar2 = DAT_022c5024;
    **(undefined4 **)(iVar1 + 0x1cc) = DAT_022c5020;
    *(undefined4 *)(iVar1 + 0x1dc) = 0;
    *(undefined4 *)(iVar1 + 0x1d8) = 0;
    *(undefined2 *)(iVar1 + 0x1c) = 0;
    puVar4 = DAT_022c5028;
    *(undefined2 *)(iVar1 + 0x1e) = 0;
    *puVar4 = uVar2;
    FUN_022c5504();
    FUN_022c5038(DAT_022c502c,DAT_022c5030,0,DAT_022c5034,0x88,0x1f,in_r3);
    iVar1 = DAT_022c5000;
    *(undefined4 *)(DAT_022c5000 + 0x108) = 0x20;
    *(undefined4 *)(iVar1 + 0xfc) = 1;
  }
  return;
}

