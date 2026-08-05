// decomp: module=unk_autoload_0 addr=0x02337040 name=FUN_02337040
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x4a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02337040 --addr 0x02337040 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337040(int param_1)

{
  ushort *puVar1;
  
  puVar1 = DAT_0233708c;
  *DAT_0233708c = (DAT_0233708c[9] | *DAT_0233708c) & ~(ushort)param_1;
  puVar1[9] = (ushort)param_1;
  if (param_1 < 0x81) {
    if (param_1 < 0x80) {
      if ((((param_1 < 5) && (-1 < param_1)) && (param_1 != 0)) && (param_1 == 4)) {
        *DAT_02337090 = 0x84;
      }
      goto LAB_02337082;
    }
  }
  else {
    if (param_1 != 0x180) goto LAB_02337082;
    *DAT_02337094 = 0x81;
  }
  *DAT_02337098 = 0x81;
LAB_02337082:
                    /* WARNING: Could not recover jumptable at 0x02337088. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0233709c)(*DAT_0233708c);
  return;
}

