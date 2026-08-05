// decomp: module=arm7 addr=0x022df690 name=FUN_022df690
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=5  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022df690 --addr 0x022df690 --size 0x30 --module arm7 --version 2.0/sp1


bool FUN_022df690(void)

{
  return (int)(uint)*(ushort *)(*DAT_022df6bc + 0x1a8) <
         (int)(0x18 - (uint)*(ushort *)(*DAT_022df6bc + 0x538));
}

