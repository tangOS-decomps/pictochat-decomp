// decomp: module=arm7 addr=0x022d865c name=FUN_022d865c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022d865c --addr 0x022d865c --size 0x20 --module arm7 --version 2.0/sp1


void FUN_022d865c(undefined4 param_1)

{
  undefined2 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = DAT_022d8678;
  puVar1 = DAT_022d8674;
  *DAT_022d8674 = (short)param_1;
  puVar1[-1] = (short)((uint)param_1 >> 0x10);
                    /* WARNING: Could not recover jumptable at 0x022d8670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

