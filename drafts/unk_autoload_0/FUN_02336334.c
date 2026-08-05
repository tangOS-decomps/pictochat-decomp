// decomp: module=unk_autoload_0 addr=0x02336334 name=FUN_02336334
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02336334 --addr 0x02336334 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_02336334(void)

{
  *DAT_02336358 = 0;
  *DAT_0233635c = (ushort)(_DAT_04000000 >> 0x10) & 3;
  _DAT_04000000 = _DAT_04000000 & DAT_02336360;
                    /* WARNING: Could not recover jumptable at 0x02336354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02336364)();
  return;
}

