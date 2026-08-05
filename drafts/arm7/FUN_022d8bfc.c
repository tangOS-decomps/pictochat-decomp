// decomp: module=arm7 addr=0x022d8bfc name=FUN_022d8bfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_022d8bfc --addr 0x022d8bfc --size 0x20 --module arm7 --version 2.0/sp1


void FUN_022d8bfc(void)

{
                    /* WARNING: Could not recover jumptable at 0x022d8c10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_022d8c18)(*DAT_022d8c14 + 0x634);
  return;
}

