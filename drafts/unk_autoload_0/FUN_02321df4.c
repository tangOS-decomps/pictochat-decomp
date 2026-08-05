// decomp: module=unk_autoload_0 addr=0x02321df4 name=FUN_02321df4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=19
// verify:  python tools/match.py --c <file> --func FUN_02321df4 --addr 0x02321df4 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321df4(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02321e18;
  *DAT_02321e18 = 0x90;
  puVar1[5] = 0xffffffff;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
                    /* WARNING: Could not recover jumptable at 0x02321e14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02321e1c)(DAT_02321e20);
  return;
}

