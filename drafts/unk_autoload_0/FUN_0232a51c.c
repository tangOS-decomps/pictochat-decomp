// decomp: module=unk_autoload_0 addr=0x0232a51c name=FUN_0232a51c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=23
// verify:  python tools/match.py --c <file> --func FUN_0232a51c --addr 0x0232a51c --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a51c(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  uchar local_c;
  undefined1 local_b;
  undefined2 local_a;
  
  if (param_1 == DAT_0232a56c) {
    FUN_02337584(*(undefined4 *)(DAT_0232a570 + 0x34),&local_10,8);
  }
  else {
    local_10 = (undefined2)param_1;
  }
  iVar1 = DAT_0232a574 * *(int *)(DAT_0232a570 + 0x4c) + DAT_0232a578;
  *(int *)(DAT_0232a570 + 0x4c) = iVar1;
  local_e = (undefined2)iVar1;
  local_c = FUN_02329dac();
  local_a = 4;
  local_b = param_2;
  FUN_02337584(&local_10,*(undefined4 *)(DAT_0232a570 + 0x34),8);
  return;
}

