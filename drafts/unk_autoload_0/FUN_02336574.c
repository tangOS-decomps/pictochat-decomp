// decomp: module=unk_autoload_0 addr=0x02336574 name=FUN_02336574
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=23  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02336574 --addr 0x02336574 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


int FUN_02336574(void)

{
  uint uVar1;
  
  uVar1 = ((ushort)DAT_023365d4[3] & 0x1f00) >> 8;
  switch(*DAT_023365d4 & 7) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    return uVar1 * 0x800 + 0x6200000;
  case 5:
    break;
  case 6:
    return 0;
  default:
    return 0;
  }
  if (((ushort)DAT_023365d4[3] & 0x80) == 0) {
    return uVar1 * 0x800 + 0x6200000;
  }
  return uVar1 * 0x4000 + 0x6200000;
}

