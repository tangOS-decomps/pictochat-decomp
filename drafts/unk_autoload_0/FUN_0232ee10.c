// decomp: module=unk_autoload_0 addr=0x0232ee10 name=FUN_0232ee10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=20
// verify:  python tools/match.py --c <file> --func FUN_0232ee10 --addr 0x0232ee10 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ee10(undefined4 *param_1)

{
  undefined4 *list;
  
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    *(undefined4 *)*param_1 = 0;
    *param_1 = 0;
  }
  list = (undefined4 *)param_1[1];
  FUN_0232e13c(list,param_1);
  param_1[1] = 0;
  if (param_1[2] != 0) {
    FUN_0232e0ac(list + 3);
    *(undefined4 *)(param_1[2] + 0xc) = 0;
    param_1[2] = 0;
  }
  FUN_0232e13c(DAT_0232ee5c,param_1);
  FUN_0232e0ac(DAT_0232ee60,param_1);
  *(undefined1 *)(param_1 + 0xb) = 0;
  return;
}

