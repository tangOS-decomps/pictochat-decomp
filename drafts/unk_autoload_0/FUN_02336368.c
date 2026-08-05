// decomp: module=unk_autoload_0 addr=0x02336368 name=FUN_02336368
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02336368 --addr 0x02336368 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_02336368(void)

{
  *DAT_02336398 = 1;
  if (*DAT_0233639c != 0) {
    _DAT_04000000 = (uint)*DAT_0233639c << 0x10 | _DAT_04000000 & DAT_023363a0;
    return;
  }
  _DAT_04000000 = _DAT_04000000 | 0x10000;
  return;
}

