// decomp: module=arm7 addr=0x022c1c58 name=FUN_022c1c58
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x84 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022c1c58 --addr 0x022c1c58 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022c1c58(void)

{
  int iVar1;
  
  iVar1 = *DAT_022c1cdc;
  *DAT_022c1ce0 = 0x8000;
  if ((((*(short *)(iVar1 + 0x34c) == 0x40) && (*(short *)(iVar1 + 0x3c2) != 0)) &&
      (*(short *)(iVar1 + 0x3b6) == *(short *)(iVar1 + 0x3b4))) &&
     (*(short *)(iVar1 + 0x3c4) = *(short *)(iVar1 + 0x3c4) + 1,
     *(ushort *)(iVar1 + 0x3c2) < *(ushort *)(iVar1 + 0x3c4))) {
    *(undefined2 *)(iVar1 + 0x3c4) = 0;
    FUN_022c0e48(1,0xd);
  }
  *(undefined2 *)(iVar1 + 0x354) = 1;
  return;
}

