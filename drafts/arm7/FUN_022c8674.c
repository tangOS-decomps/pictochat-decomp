// decomp: module=arm7 addr=0x022c8674 name=FUN_022c8674
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c8674 --addr 0x022c8674 --size 0x40 --module arm7 --version 2.0/sp1


void FUN_022c8674(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_022c86ac;
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 0x24;
    *(byte *)(iVar2 + iVar1) = *(byte *)(iVar2 + iVar1) & 0xfe;
    *(char *)(iVar2 + iVar1 + 1) = (char)iVar3;
    iVar1 = DAT_022c86b0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  iVar2 = 0;
  do {
    iVar3 = iVar2 * 0x40;
    iVar2 = iVar2 + 1;
    *(byte *)(iVar1 + iVar3) = *(byte *)(iVar1 + iVar3) & 0xfe;
  } while (iVar2 < 0x20);
  return;
}

