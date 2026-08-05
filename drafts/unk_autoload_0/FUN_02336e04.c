// decomp: module=unk_autoload_0 addr=0x02336e04 name=FUN_02336e04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x154 (Ghidra's cache says 0xfe - it excludes this function's trailing literal pool), thumb
// triage: noise=15 statements=99
// verify:  python tools/match.py --c <file> --func FUN_02336e04 --addr 0x02336e04 --size 0x154 --module unk_autoload_0 --version 2.0/sp1


void FUN_02336e04(int param_1)

{
  ushort *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar1 = DAT_02336f44;
  *DAT_02336f44 = (DAT_02336f44[1] | *DAT_02336f44) & ~(ushort)param_1;
  puVar1[1] = (ushort)param_1;
  puVar4 = DAT_02336f58;
  puVar3 = DAT_02336f54;
  puVar2 = DAT_02336f50;
  if (param_1 < 0x41) {
    if (0x3f < param_1) {
      *DAT_02336f58 = 0x81;
      goto switchD_02336e2c_caseD_0;
    }
    if (0x20 < param_1) {
      if (param_1 != 0x30) goto switchD_02336e2c_caseD_0;
      goto LAB_02336f0c;
    }
    switch(param_1) {
    case 8:
      *DAT_02336f48 = 0x81;
      break;
    case 9:
      *DAT_02336f54 = 0x81;
      puVar3[3] = 0x89;
      break;
    case 10:
      *DAT_02336f50 = 0x81;
      puVar2[2] = 0x89;
      break;
    case 0xb:
      *DAT_02336f54 = 0x81;
      puVar3[1] = 0x89;
      puVar3[3] = 0x91;
      break;
    case 0xc:
      *DAT_02336f48 = 0x89;
    case 4:
      *DAT_02336f4c = 0x81;
      break;
    case 0xd:
      *DAT_02336f48 = 0x91;
    case 5:
      puVar2 = DAT_02336f54;
      *DAT_02336f54 = 0x81;
      puVar2[2] = 0x89;
      break;
    case 0xe:
      *DAT_02336f48 = 0x91;
    case 6:
      *DAT_02336f4c = 0x89;
    case 2:
      *DAT_02336f50 = 0x81;
      break;
    case 0xf:
      *DAT_02336f48 = 0x99;
    case 7:
      *DAT_02336f4c = 0x91;
    case 3:
      *DAT_02336f50 = 0x89;
    case 1:
      *DAT_02336f54 = 0x81;
      break;
    case 0x10:
      goto switchD_02336e2c_caseD_10;
    case 0x20:
      goto switchD_02336e2c_caseD_20;
    }
  }
  else {
    if (param_1 < 0x61) {
      if (param_1 < 0x60) {
        if (param_1 == 0x50) {
          *DAT_02336f58 = 0x91;
          puVar4[-2] = 0x81;
        }
        goto switchD_02336e2c_caseD_0;
      }
      *DAT_02336f58 = 0x89;
switchD_02336e2c_caseD_20:
      *DAT_02336f5c = 0x81;
      goto switchD_02336e2c_caseD_0;
    }
    if (param_1 != 0x70) goto switchD_02336e2c_caseD_0;
    *DAT_02336f58 = 0x99;
LAB_02336f0c:
    *DAT_02336f5c = 0x91;
switchD_02336e2c_caseD_10:
    *DAT_02336f60 = 0x81;
  }
switchD_02336e2c_caseD_0:
                    /* WARNING: Could not recover jumptable at 0x02336f42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_02336f64)(*DAT_02336f44);
  return;
}

