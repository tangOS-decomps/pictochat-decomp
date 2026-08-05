// decomp: module=unk_autoload_0 addr=0x02335300 name=FUN_02335300
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02335300 --addr 0x02335300 --size 0x8c --module unk_autoload_0 --version 2.0/sp1


ulonglong FUN_02335300(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 & 0x80000000) == 0) {
    uVar1 = DAT_02335388 - (param_2 >> 0x14);
    if ((int)(param_2 >> 0x14) <= DAT_02335388) {
      if (0x3f < (int)uVar1) {
        return 0;
      }
      uVar2 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
      if (0x20 < (int)uVar1) {
        return (ulonglong)(uVar2 >> (uVar1 - 0x20 & 0xff));
      }
      return CONCAT44(uVar2 >> (uVar1 & 0xff),
                      (param_1 << 0xb) >> (uVar1 & 0xff) | uVar2 << (0x20 - uVar1 & 0xff));
    }
  }
  else if (param_2 < 0xfff00000 || param_2 == 0xfff00000 && param_1 == 0) {
    return 0;
  }
  return 0xffffffffffffffff;
}

