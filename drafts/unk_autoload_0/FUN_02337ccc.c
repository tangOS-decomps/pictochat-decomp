// decomp: module=unk_autoload_0 addr=0x02337ccc name=FUN_02337ccc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02337ccc --addr 0x02337ccc --size 0x40 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02337ccc(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_02332080();
  uVar1 = *(uint *)(DAT_02337d08 + 4);
  if (uVar1 < param_1) {
    if (param_1 - uVar1 < 0x80000000) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (uVar1 - param_1 < 0x80000000) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  FUN_02332094();
  return uVar2;
}

