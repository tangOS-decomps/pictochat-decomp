// decomp: module=arm7 addr=0x022c8600 name=FUN_022c8600
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022c8600 --addr 0x022c8600 --size 0x40 --module arm7 --version 2.0/sp1


uint FUN_022c8600(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = DAT_022c863c;
  if (param_1 != 0x7f) {
    if (param_1 == 0x7e) {
      uVar1 = 0x3c00;
    }
    else if (param_1 < 0x32) {
      uVar1 = param_1 * 2 + 1U & 0xffff;
    }
    else {
      uVar1 = thunk_EXT_FUN_037fbaa4(0x1e00,0x7e - param_1,param_1,param_4,param_4);
      uVar1 = uVar1 & 0xffff;
    }
  }
  return uVar1;
}

