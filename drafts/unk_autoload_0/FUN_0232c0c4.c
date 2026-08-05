// decomp: module=unk_autoload_0 addr=0x0232c0c4 name=FUN_0232c0c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0xc - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232c0c4 --addr 0x0232c0c4 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c0c4(void)

{
  *DAT_0232c0d0 = 0;
                    /* WARNING: Could not recover jumptable at 0x0232c0ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0232c0d4)(DAT_0232c0d8);
  return;
}

