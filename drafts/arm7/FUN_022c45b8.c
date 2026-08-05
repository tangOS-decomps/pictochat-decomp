// decomp: module=arm7 addr=0x022c45b8 name=FUN_022c45b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022c45b8 --addr 0x022c45b8 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022c45b8(int param_1)

{
  uint uVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 * 0xc;
  pcVar3 = *(code **)(DAT_022c4630 + iVar5);
  uVar2 = *(ushort *)(DAT_022c4638 + param_1 * 2);
  iVar4 = *(int *)(DAT_022c4634 + iVar5);
  *(undefined4 *)(DAT_022c4630 + iVar5) = 0;
  uVar1 = 1 << (uVar2 & 0xff);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(*(undefined4 *)(DAT_022c463c + iVar5));
  }
  *DAT_022c4640 = *DAT_022c4640 | uVar1;
  if (iVar4 == 0) {
    FUN_022c48a4(uVar1);
  }
  return;
}

