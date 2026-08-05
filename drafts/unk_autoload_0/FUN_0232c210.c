// decomp: module=unk_autoload_0 addr=0x0232c210 name=FUN_0232c210
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232c210 --addr 0x0232c210 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c210(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0232c22c(param_1,param_2,0xf00,param_4,param_4);
  if (iVar1 == 0) {
    *(undefined2 *)(*(int *)(DAT_0232c228 + 4) + 0x16) = 0;
  }
  return;
}

