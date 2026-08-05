// decomp: module=arm7 addr=0x022c81a8 name=FUN_022c81a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022c81a8 --addr 0x022c81a8 --size 0x2c --module arm7 --version 2.0/sp1


undefined4 FUN_022c81a8(byte *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 < 0xe) {
    uVar1 = 0;
  }
  else if (*param_1 < 0x10) {
    param_1[1] = 2;
    *(short *)(param_1 + 0x3c) = (short)DAT_022c81d0;
    FUN_022c864c();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

