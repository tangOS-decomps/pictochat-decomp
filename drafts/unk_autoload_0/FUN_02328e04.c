// decomp: module=unk_autoload_0 addr=0x02328e04 name=FUN_02328e04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0xe - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02328e04 --addr 0x02328e04 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02328e04(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02328e10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_02336880_1_02328e18)(PTR_DAT_02328e14 + param_1 * 2,0xb8,2);
  return;
}

