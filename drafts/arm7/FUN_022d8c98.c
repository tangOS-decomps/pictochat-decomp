// decomp: module=arm7 addr=0x022d8c98 name=FUN_022d8c98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=7
// verify:  python tools/match.py --c <file> --func FUN_022d8c98 --addr 0x022d8c98 --size 0x20 --module arm7 --version 2.0/sp1


void FUN_022d8c98(undefined4 param_1,undefined4 param_2,int param_3)

{
                    /* WARNING: Could not recover jumptable at 0x022d8cb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_022d8cb4)(param_2,param_1,param_3 + 1U & 0xfffffffe);
  return;
}

