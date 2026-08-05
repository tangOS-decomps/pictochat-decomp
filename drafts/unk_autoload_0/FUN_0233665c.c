// decomp: module=unk_autoload_0 addr=0x0233665c name=FUN_0233665c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=23  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233665c --addr 0x0233665c --size 0x64 --module unk_autoload_0 --version 2.0/sp1


int FUN_0233665c(void)

{
  uint uVar1;
  
  uVar1 = (*(ushort *)((int)DAT_023366bc + 0xe) & 0x1f00) >> 8;
  switch(*DAT_023366bc & 7) {
  case 0:
  case 1:
  case 2:
    return uVar1 * 0x800 + 0x6200000;
  case 3:
  case 4:
  case 5:
    break;
  case 6:
    return 0;
  default:
    return 0;
  }
  if ((*(ushort *)((int)DAT_023366bc + 0xe) & 0x80) == 0) {
    return uVar1 * 0x800 + 0x6200000;
  }
  return uVar1 * 0x4000 + 0x6200000;
}

