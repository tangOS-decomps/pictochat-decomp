// decomp: module=unk_autoload_0 addr=0x02336728 name=FUN_02336728
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02336728 --addr 0x02336728 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_02336728(void)

{
  if ((4 < (_DAT_04000000 & 7)) && ((_DAT_0400000c & 0x80) != 0)) {
    return 0;
  }
  return ((_DAT_04000000 & 0x7000000) >> 0x18) * 0x10000 + 0x6000000 +
         ((_DAT_0400000c & 0x3c) >> 2) * 0x4000;
}

