// decomp: module=unk_autoload_0 addr=0x0232102c name=FUN_0232102c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=61
// verify:  python tools/match.py --c <file> --func FUN_0232102c --addr 0x0232102c --size 0x9c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232102c(int param_1)

{
  int iVar1;
  
  if (DAT_023210b4 < param_1) {
    if (param_1 < 0x8001) {
      if (0x7fff < param_1) {
        return 2;
      }
      if (param_1 < 1) {
        if (param_1 == 0) {
          return 1;
        }
      }
      else if (param_1 == 0x4000) {
        return 2;
      }
    }
    else {
      iVar1 = DAT_023210c4;
      if (param_1 <= DAT_023210c0) {
        if (DAT_023210c0 <= param_1) {
          return 4;
        }
        iVar1 = DAT_023210c0 * 0x10000;
      }
      if (param_1 == iVar1) {
        return 4;
      }
    }
    return 0;
  }
  if (DAT_023210b4 <= param_1) {
    return 0x20;
  }
  if (DAT_023210b8 < param_1) {
    if (-0x40000000 < param_1) {
      if (param_1 != DAT_023210b8 >> 1) {
        return 0;
      }
      return 0x20;
    }
    if (param_1 != -0x40000000) {
      return 0;
    }
    return 0x40;
  }
  if (DAT_023210b8 <= param_1) {
    return 8;
  }
  iVar1 = DAT_023210b8 * 0x10000;
  if (param_1 == iVar1 || param_1 < iVar1) {
    if (param_1 != iVar1) {
      return 0;
    }
    return 0x10;
  }
  if (param_1 != DAT_023210bc) {
    return 0;
  }
  return 8;
}

