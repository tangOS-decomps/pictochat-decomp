// decomp: module=arm7 addr=0x022c69f8 name=FUN_022c69f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c69f8 --addr 0x022c69f8 --size 0x5c --module arm7 --version 2.0/sp1


void FUN_022c69f8(int param_1)

{
  ushort *puVar1;
  
  FUN_022c4738(4,DAT_022c6a4c);
  puVar1 = DAT_022c6a50;
  *DAT_022c6a50 =
       *DAT_022c6a50 & 0x3f | (ushort)((uint)((int)*(short *)(param_1 + 0x10) << 0x18) >> 0x10) |
       (ushort)((int)((int)*(short *)(param_1 + 0x10) & 0x100U) >> 1);
  *puVar1 = *puVar1 | 0x20;
  FUN_022c486c(4);
  return;
}

