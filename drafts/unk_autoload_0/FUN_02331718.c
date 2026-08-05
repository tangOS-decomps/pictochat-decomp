// decomp: module=unk_autoload_0 addr=0x02331718 name=FUN_02331718
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x4a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=28
// verify:  python tools/match.py --c <file> --func FUN_02331718 --addr 0x02331718 --size 0x6c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02331718(undefined4 param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case 0:
    return DAT_02331770;
  default:
    return 0;
  case 2:
    break;
  case 3:
    return DAT_0233177c;
  case 4:
    return DAT_02331780;
  case 5:
    return DAT_02331784;
  case 6:
    return DAT_02331788;
  }
  if (*(int *)(DAT_02331774 + 4) == 0) {
    return 0;
  }
  uVar1 = FUN_023311d8();
  if ((uVar1 & 0xf) == 1) {
    return 0;
  }
  return DAT_02331778;
}

