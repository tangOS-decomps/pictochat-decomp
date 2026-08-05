// decomp: module=arm7 addr=0x022c5d90 name=FUN_022c5d90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022c5d90 --addr 0x022c5d90 --size 0x6c --module arm7 --version 2.0/sp1


void FUN_022c5d90(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = FUN_022c6d40();
  piVar2 = *(int **)(DAT_022c5df8 + param_1 * 4);
  if (param_2 < 0) {
    param_2 = *piVar2;
  }
  iVar4 = param_2 * 0xc + piVar2[4];
  uVar3 = FUN_022c5bb0(*(undefined4 *)(iVar4 + 8),param_3 + -0x20);
  *(undefined4 *)(iVar4 + 8) = uVar3;
  uVar3 = FUN_022c5bd8(*(undefined4 *)(iVar4 + 4),param_3 + -0x20);
  *(undefined4 *)(iVar4 + 4) = uVar3;
  FUN_022c6d54(uVar1);
  return;
}

