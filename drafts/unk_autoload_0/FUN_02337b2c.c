// decomp: module=unk_autoload_0 addr=0x02337b2c name=FUN_02337b2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02337b2c --addr 0x02337b2c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337b2c(undefined4 *param_1)

{
  int iVar1;
  
  FUN_02332080();
  iVar1 = DAT_02337b50;
  if (*(undefined4 **)(DAT_02337b50 + 0xc) == (undefined4 *)0x0) {
    *(undefined4 **)(DAT_02337b50 + 8) = param_1;
  }
  else {
    **(undefined4 **)(DAT_02337b50 + 0xc) = param_1;
  }
  *(undefined4 **)(iVar1 + 0xc) = param_1;
  *param_1 = 0;
  FUN_02332094();
  return;
}

