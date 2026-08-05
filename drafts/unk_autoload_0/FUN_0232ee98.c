// decomp: module=unk_autoload_0 addr=0x0232ee98 name=FUN_0232ee98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232ee98 --addr 0x0232ee98 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ee98(void *param_1,undefined1 param_2)

{
  undefined4 *list;
  
  list = *(undefined4 **)((int)param_1 + 4);
  if (list != (undefined4 *)0x0) {
    FUN_0232e13c(list,param_1);
    *(undefined4 *)((int)param_1 + 4) = 0;
  }
  FUN_0232e13c(DAT_0232eed4,param_1);
  *(undefined1 *)((int)param_1 + 0x3d) = param_2;
  if (list != (undefined4 *)0x0) {
    FUN_0232ed20(list,param_1);
  }
  FUN_0232ed58(param_1);
  return;
}

