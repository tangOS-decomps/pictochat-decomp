// decomp: module=unk_autoload_0 addr=0x02334528 name=FUN_02334528
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=21
// verify:  python tools/match.py --c <file> --func FUN_02334528 --addr 0x02334528 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02334528(int param_1,uint param_2)

{
  uint uVar1;
  int local_18;
  uint local_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = param_1;
  local_14 = param_2;
  uVar1 = FUN_02333f20(DAT_02334560,&local_18);
  if (param_1 != 0) {
    if (uVar1 < param_2) {
      *(undefined1 *)(param_1 + uVar1) = 0;
      return;
    }
    if (param_2 != 0) {
      *(undefined1 *)(param_1 + param_2 + -1) = 0;
    }
  }
  return;
}

