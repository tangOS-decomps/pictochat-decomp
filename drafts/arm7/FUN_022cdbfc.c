// decomp: module=arm7 addr=0x022cdbfc name=FUN_022cdbfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5a, thumb
// triage: noise=0 statements=49  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022cdbfc --addr 0x022cdbfc --size 0x5a --module arm7 --version 2.0/sp1


void FUN_022cdbfc(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (uVar1 & 0x3fff) >> 8;
  switch(uVar2) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x10:
  case 0x11:
    if ((int)(uVar1 << 0x11) < 0) {
      *param_1 = (uVar2 + 0x12 & 0x3f) << 8 | DAT_022cdca0 & uVar1;
      return;
    }
    break;
  case 8:
  case 9:
    if ((int)(uVar1 << 0x11) < 0) {
      *param_1 = (uVar2 + 0x18 & 0x3f) << 8 | DAT_022cdca0 & uVar1;
      return;
    }
    break;
  default:
    *param_1 = DAT_022cdca0 & *param_1 & DAT_022cdca4;
    break;
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
    *param_1 = uVar1 | 0x4000;
    return;
  }
  return;
}

