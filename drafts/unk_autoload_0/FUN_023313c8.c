// decomp: module=unk_autoload_0 addr=0x023313c8 name=FUN_023313c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_023313c8 --addr 0x023313c8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_023313c8(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *list;
  int iVar2;
  
  uVar1 = FUN_02332080();
  list = *(undefined4 **)(DAT_023313fc + 4);
  if ((undefined4 *)param_1[2] == list) {
    iVar2 = param_1[3];
    param_1[3] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_0233144c(list,param_1);
      param_1[2] = 0;
      FUN_02330f6c(param_1);
    }
  }
  FUN_02332094(uVar1);
  return;
}

