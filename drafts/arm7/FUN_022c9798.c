// decomp: module=arm7 addr=0x022c9798 name=FUN_022c9798
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=16  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c9798 --addr 0x022c9798 --size 0x34 --module arm7 --version 2.0/sp1


int FUN_022c9798(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x1f < iVar2) {
      return -1;
    }
    bVar1 = *(byte *)(DAT_022c97c8 + iVar2 * 0x40);
    if (-1 < (int)((uint)bVar1 << 0x1f)) break;
    iVar2 = iVar2 + 1;
  }
  *(byte *)(DAT_022c97c8 + iVar2 * 0x40) = bVar1 & 0xfe | 1;
  return iVar2;
}

