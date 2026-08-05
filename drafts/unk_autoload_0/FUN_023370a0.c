// decomp: module=unk_autoload_0 addr=0x023370a0 name=FUN_023370a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=19
// verify:  python tools/match.py --c <file> --func FUN_023370a0 --addr 0x023370a0 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_023370a0(int param_1)

{
  ushort *puVar1;
  
  puVar1 = DAT_023370d8;
  *DAT_023370d8 = (DAT_023370d8[10] | *DAT_023370d8) & ~(ushort)param_1;
  puVar1[10] = (ushort)param_1;
  if (param_1 != 0) {
    if (param_1 == 8) {
      *DAT_023370dc = 0x84;
    }
    else if (param_1 == 0x100) {
      *DAT_023370e0 = 0x82;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x023370d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_023370e4)(*DAT_023370d8);
  return;
}

