// decomp: module=arm7 addr=0x022c5b30 name=FUN_022c5b30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5b30 --addr 0x022c5b30 --size 0x58 --module arm7 --version 2.0/sp1


uint FUN_022c5b30(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    return DAT_022c5b80;
  }
  if (param_1 != 7) {
    if (param_1 != 8) {
      return 0;
    }
    uVar1 = 0x3800000;
    if (0x3800000 < DAT_022c5b84) {
      uVar1 = DAT_022c5b84;
    }
    return uVar1;
  }
  uVar1 = DAT_022c5b84;
  if (0x3800000 < DAT_022c5b84) {
    uVar1 = 0x3800000;
  }
  return uVar1;
}

