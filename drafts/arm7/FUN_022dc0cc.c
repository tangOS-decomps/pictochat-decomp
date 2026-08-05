// decomp: module=arm7 addr=0x022dc0cc name=FUN_022dc0cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=7
// verify:  python tools/match.py --c <file> --func FUN_022dc0cc --addr 0x022dc0cc --size 0x28 --module arm7 --version 2.0/sp1


void FUN_022dc0cc(void)

{
                    /* WARNING: Could not recover jumptable at 0x022dc0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_022dc0f0)(0,*DAT_022dc0ec + 0x404,0x20);
  return;
}

