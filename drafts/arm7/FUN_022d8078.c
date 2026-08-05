// decomp: module=arm7 addr=0x022d8078 name=FUN_022d8078
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d8078 --addr 0x022d8078 --size 0x5c --module arm7 --version 2.0/sp1


void FUN_022d8078(void)

{
  int iVar1;
  
  iVar1 = *DAT_022d80cc;
  *(undefined2 *)(iVar1 + 0x3ae) = 0;
  func_0x037c8430();
  *DAT_022d80d0 = 0;
  if (*(short *)(iVar1 + 0x3cc) != 0) {
    FUN_022ded7c();
    FUN_022d9c60(*(undefined2 *)(iVar1 + 0x3cc),0x20);
    *(undefined2 *)(iVar1 + 0x3cc) = 0;
  }
  return;
}

