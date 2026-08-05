// decomp: module=arm7 addr=0x022ce57c name=FUN_022ce57c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022ce57c --addr 0x022ce57c --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022ce57c(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_022ce5ac;
  iVar3 = 0;
  do {
    iVar2 = iVar1 + iVar3;
    iVar3 = iVar3 + 1;
    *(undefined1 *)(iVar2 + 0x1554) = param_1;
  } while (iVar3 < 0x20);
  *(undefined4 *)(DAT_022ce5b0 + 0x574) = 0;
  return;
}

