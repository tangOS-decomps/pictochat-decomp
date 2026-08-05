// decomp: module=unk_autoload_0 addr=0x02336f68 name=FUN_02336f68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0x9e - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=59
// verify:  python tools/match.py --c <file> --func FUN_02336f68 --addr 0x02336f68 --size 0xc0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02336f68(int param_1)

{
  ushort *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_02337010;
  *DAT_02337010 = (DAT_02337010[2] | *DAT_02337010) & ~(ushort)param_1;
  puVar1[2] = (ushort)param_1;
  puVar2 = DAT_0233701c;
  if (param_1 < 0x31) {
    if (0x2f < param_1) goto LAB_02336fd6;
    if (0x10 < param_1) {
      if (param_1 != 0x20) goto switchD_02336f90_caseD_0;
LAB_02336ff8:
      *DAT_02337020 = 0x82;
      goto switchD_02336f90_caseD_0;
    }
    if (param_1 < 0x10) {
      switch(param_1) {
      case 2:
        *DAT_02337014 = 0x82;
        break;
      case 3:
        *DAT_02337014 = 0x8a;
      case 1:
        *DAT_02337018 = 0x82;
      }
      goto switchD_02336f90_caseD_0;
    }
  }
  else {
    if (param_1 < 0x51) {
      if (param_1 < 0x50) {
        if (param_1 == 0x40) {
          *DAT_0233701c = 0x82;
        }
      }
      else {
        *DAT_0233701c = 0x92;
        puVar2[-2] = 0x82;
      }
      goto switchD_02336f90_caseD_0;
    }
    if (param_1 < 0x61) {
      if (param_1 != 0x60) goto switchD_02336f90_caseD_0;
      *DAT_0233701c = 0x8a;
      goto LAB_02336ff8;
    }
    if (param_1 != 0x70) goto switchD_02336f90_caseD_0;
    *DAT_0233701c = 0x9a;
LAB_02336fd6:
    *DAT_02337020 = 0x92;
  }
  *DAT_02337024 = 0x82;
switchD_02336f90_caseD_0:
                    /* WARNING: Could not recover jumptable at 0x0233700c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02337028)(*DAT_02337010);
  return;
}

