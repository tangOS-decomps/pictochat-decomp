// decomp: module=arm7 addr=0x022c5ab4 name=FUN_022c5ab4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=27  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5ab4 --addr 0x022c5ab4 --size 0x7c --module arm7 --version 2.0/sp1


uint FUN_022c5ab4(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    return DAT_022c5b1c;
  }
  if (param_1 == 7) {
    return 0x3800000;
  }
  if (param_1 != 8) {
    return 0;
  }
  uVar1 = 0x3800000;
  if (0x3800000 < DAT_022c5b28) {
    uVar1 = DAT_022c5b28;
  }
  if (DAT_022c5b2c != 0) {
    if (DAT_022c5b2c < 0) {
      uVar1 = uVar1 - DAT_022c5b2c;
    }
    else {
      uVar1 = (DAT_022c5b24 - DAT_022c5b20) - DAT_022c5b2c;
    }
    return uVar1;
  }
  return uVar1;
}

