// decomp: module=arm7 addr=0x022cdb44 name=FUN_022cdb44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb4 (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=40  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022cdb44 --addr 0x022cdb44 --size 0xb4 --module arm7 --version 2.0/sp1


void FUN_022cdb44(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  switch((uVar1 & 0x3fff) >> 8) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0x10:
  case 0x11:
    *param_1 = uVar1 & DAT_022cdbf4;
    return;
  default:
    *param_1 = DAT_022cdbf8 & *param_1 & DAT_022cdbf4;
    return;
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x22:
  case 0x23:
    *param_1 = (((uVar1 & 0x3fff) >> 8) - 0x12 & 0x3f) << 8 | (uVar1 | 0x4000) & DAT_022cdbf8;
    return;
  case 0x20:
  case 0x21:
    *param_1 = (((uVar1 & 0x3fff) >> 8) - 0x18 & 0x3f) << 8 | (uVar1 | 0x4000) & DAT_022cdbf8;
    return;
  }
}

