// decomp: module=unk_autoload_0 addr=0x0233702c name=FUN_0233702c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0xc - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0233702c --addr 0x0233702c --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233702c(ushort param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = DAT_0233703c;
  *DAT_02337038 = *DAT_02337038 | param_1;
                    /* WARNING: Could not recover jumptable at 0x02337036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

