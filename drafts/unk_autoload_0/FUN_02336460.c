// decomp: module=unk_autoload_0 addr=0x02336460 name=FUN_02336460
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=6
// verify:  python tools/match.py --c <file> --func FUN_02336460 --addr 0x02336460 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * FUN_02336460(void)

{
  return (void *)(((int)(*DAT_02336488 & 0x1f00) >> 8) * 0x800 +
                 ((*(uint *)(DAT_02336488 + -4) & 0x38000000) >> 0x1b) * 0x10000 + 0x6000000);
}

