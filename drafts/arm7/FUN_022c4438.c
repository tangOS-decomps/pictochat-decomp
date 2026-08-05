// decomp: module=arm7 addr=0x022c4438 name=FUN_022c4438
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2, thumb
// triage: noise=3 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022c4438 --addr 0x022c4438 --size 0x2 --module arm7 --version 2.0/sp1


void FUN_022c4438(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x022c4438. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

