// decomp: module=unk_autoload_0 addr=0x023301bc name=FUN_023301bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=35
// verify:  python tools/match.py --c <file> --func FUN_023301bc --addr 0x023301bc --size 0x8c --module unk_autoload_0 --version 2.0/sp1


void FUN_023301bc(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 != *DAT_02330230) {
    if (*DAT_02330230 == 1) {
      FUN_0233791c(0);
    }
    uVar2 = FUN_02332080();
    FUN_0233740c(0,DAT_02330234,0xc0);
    piVar1 = DAT_02330230;
    *DAT_02330230 = param_1;
    switch(param_1) {
    case 0:
      piVar1[1] = DAT_02330244;
      break;
    case 1:
      piVar1[1] = DAT_02330238;
      break;
    case 2:
      piVar1[1] = DAT_0233023c;
      break;
    case 3:
      piVar1[1] = DAT_02330240;
      break;
    default:
      DAT_02330230[1] = DAT_02330244;
    }
    FUN_02332094(uVar2);
    if (param_1 == 1) {
      FUN_0233791c(0x3000);
    }
  }
  return;
}

