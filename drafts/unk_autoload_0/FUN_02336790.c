// decomp: module=unk_autoload_0 addr=0x02336790 name=FUN_02336790
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02336790 --addr 0x02336790 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


int FUN_02336790(void)

{
  if ((2 < (*DAT_023367bc & 7)) &&
     ((5 < (*DAT_023367bc & 7) || ((*(ushort *)((int)DAT_023367bc + 0xe) & 0x80) != 0)))) {
    return 0;
  }
  return ((*(ushort *)((int)DAT_023367bc + 0xe) & 0x3c) >> 2) * 0x4000 + 0x6200000;
}

