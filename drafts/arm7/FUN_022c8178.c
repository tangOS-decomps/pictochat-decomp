// decomp: module=arm7 addr=0x022c8178 name=FUN_022c8178
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022c8178 --addr 0x022c8178 --size 0x30 --module arm7 --version 2.0/sp1


undefined4 FUN_022c8178(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*param_1 < 8) {
    uVar1 = 0;
  }
  else if (*param_1 < 0xe) {
    param_1[1] = 1;
    *(undefined4 *)(param_1 + 0x44) = param_2;
    *(short *)(param_1 + 0x3c) = (short)DAT_022c81a4;
    FUN_022c864c(param_1,param_3,param_3,1,param_4);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

