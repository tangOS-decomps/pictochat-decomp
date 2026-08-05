// decomp: module=arm7 addr=0x022ce5f0 name=FUN_022ce5f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=32
// verify:  python tools/match.py --c <file> --func FUN_022ce5f0 --addr 0x022ce5f0 --size 0x68 --module arm7 --version 2.0/sp1


undefined4 FUN_022ce5f0(uint param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(*(int *)(DAT_022ce654 + 0x54c) + 0x53) != '\b') {
    if (param_1 < 8) {
      return 0;
    }
    if (0xd < param_1) {
      if (param_1 < 0x14) {
        uVar1 = 2;
      }
      else {
        uVar1 = 3;
      }
      return uVar1;
    }
    return 1;
  }
  if (param_1 < 0x16) {
    return 0;
  }
  if (0x1b < param_1) {
    if (param_1 < 0x22) {
      uVar1 = 2;
    }
    else {
      uVar1 = 3;
    }
    return uVar1;
  }
  return 1;
}

