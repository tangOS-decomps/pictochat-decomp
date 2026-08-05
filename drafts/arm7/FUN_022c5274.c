// decomp: module=arm7 addr=0x022c5274 name=FUN_022c5274
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022c5274 --addr 0x022c5274 --size 0x54 --module arm7 --version 2.0/sp1


void FUN_022c5274(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_022c6d40();
  iVar2 = **(int **)(DAT_022c52c4 + 8);
  if (param_1 != 0) {
    *(int *)(iVar2 + 0x5c) = param_1;
    FUN_022c4c84(param_1,iVar2);
  }
  *(undefined4 *)(iVar2 + 0x48) = 0;
  FUN_022c4e28();
  FUN_022c6d54(uVar1);
  return;
}

