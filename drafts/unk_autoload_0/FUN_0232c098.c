// decomp: module=unk_autoload_0 addr=0x0232c098 name=FUN_0232c098
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232c098 --addr 0x0232c098 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c098(void)

{
  *DAT_0232c0a8 = 0;
                    /* WARNING: Could not recover jumptable at 0x0232c0a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0232c0ac)(DAT_0232c0b0,0x10,0x40);
  return;
}

