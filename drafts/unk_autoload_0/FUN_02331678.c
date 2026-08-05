// decomp: module=unk_autoload_0 addr=0x02331678 name=FUN_02331678
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x72 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=39
// verify:  python tools/match.py --c <file> --func FUN_02331678 --addr 0x02331678 --size 0x98 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02331678(undefined4 param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case 0:
    return DAT_023316f8;
  default:
    uVar1 = 0;
    break;
  case 2:
    if (*(int *)(DAT_023316fc + 4) == 0) {
      return 0;
    }
    uVar1 = FUN_023311d8();
    if ((uVar1 & 0xf) == 1) {
      return 0;
    }
    return 0x2700000;
  case 3:
    return 0x2000000;
  case 4:
    if (DAT_02331708 != 0) {
      if (DAT_02331708 < 0) {
        return DAT_0233170c - DAT_02331708;
      }
      return ((DAT_02331700 + 0x3f80) - DAT_02331704) - DAT_02331708;
    }
    uVar1 = DAT_02331700;
    if (DAT_02331700 < DAT_0233170c) {
      return DAT_0233170c;
    }
    break;
  case 5:
    return DAT_02331710;
  case 6:
    return DAT_02331714;
  }
  return uVar1;
}

