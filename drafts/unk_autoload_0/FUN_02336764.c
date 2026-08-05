// decomp: module=unk_autoload_0 addr=0x02336764 name=FUN_02336764
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02336764 --addr 0x02336764 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * FUN_02336764(void)

{
  if ((4 < (*DAT_0233678c & 7)) && (((ushort)DAT_0233678c[3] & 0x80) != 0)) {
    return (void *)0x0;
  }
  return (void *)((((ushort)DAT_0233678c[3] & 0x3c) >> 2) * 0x4000 + 0x6200000);
}

