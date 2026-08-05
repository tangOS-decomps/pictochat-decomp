// decomp: module=arm7 addr=0x022c2e40 name=FUN_022c2e40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xc4 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=34
// verify:  python tools/match.py --c <file> --func FUN_022c2e40 --addr 0x022c2e40 --size 0xc8 --module arm7 --version 2.0/sp1


void FUN_022c2e40(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *DAT_022c2f04;
  bVar2 = false;
  func_0x00dda510(2);
  func_0x00dda510(1);
  func_0x00dda510(0);
  if ((*(short *)(iVar1 + 0x454) != 0) && (bVar2 = **(short **)(iVar1 + 0x45c) != 0, !bVar2)) {
    *(undefined2 *)(iVar1 + 0x454) = 0;
  }
  if (*(short *)(iVar1 + 0x440) != 0) {
    if (**(short **)(iVar1 + 0x448) == 0) {
      *(undefined2 *)(iVar1 + 0x440) = 0;
    }
    else {
      bVar2 = true;
    }
  }
  if (*(short *)(iVar1 + 0x42c) != 0) {
    if (**(short **)(iVar1 + 0x434) == 0) {
      *(short *)(iVar1 + 0x42c) = 0;
    }
    else {
      bVar2 = true;
    }
  }
  if (bVar2) {
    FUN_022c0e48(0,0xe);
  }
  FUN_022c0e48(0,0x14);
  return;
}

