// decomp: module=unk_autoload_0 addr=0x02331ef0 name=FUN_02331ef0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=31
// verify:  python tools/match.py --c <file> --func FUN_02331ef0 --addr 0x02331ef0 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331ef0(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_02332080();
  if (*param_1 == 0) {
    FUN_02332094();
    return;
  }
  iVar2 = param_1[6];
  if (iVar2 == 0) {
    *(int *)(DAT_02331f40 + 8) = param_1[5];
  }
  else {
    *(int *)(iVar2 + 0x14) = param_1[5];
  }
  if (param_1[5] == 0) {
    *(int *)(DAT_02331f40 + 4) = iVar2;
    if (iVar2 != 0) {
      FUN_02331d1c();
    }
  }
  else {
    *(int *)(param_1[5] + 0x18) = iVar2;
  }
  *param_1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_02332094(uVar1);
  return;
}

