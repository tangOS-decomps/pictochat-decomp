// decomp: module=unk_autoload_0 addr=0x02321798 name=FUN_02321798
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc (Ghidra's cache says 0xb6 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=78
// verify:  python tools/match.py --c <file> --func FUN_02321798 --addr 0x02321798 --size 0xcc --module unk_autoload_0 --version 2.0/sp1


void FUN_02321798(int param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  
  if (DAT_02321850 < param_1) {
    if (param_1 < 0x8001) {
      if (param_1 < 0x8000) {
        if (param_1 < 1) {
          if (param_1 == 0) {
            param_1 = 8;
            param_4 = 8;
          }
        }
        else if (param_1 == 0x4000) {
          param_1 = 0x10;
          param_4 = 8;
        }
      }
      else {
        param_1 = 8;
        param_4 = 0x10;
      }
    }
    else if (DAT_0232185c < param_1) {
      if (param_1 == DAT_02321860) {
        param_1 = 8;
        param_4 = 0x20;
      }
    }
    else if (param_1 < DAT_0232185c) {
      if (param_1 == DAT_0232185c * 0x10000) {
        param_1 = 0x10;
        param_4 = 0x10;
      }
    }
    else {
      param_1 = 0x20;
      param_4 = 8;
    }
  }
  else if (param_1 < DAT_02321850) {
    if (DAT_02321854 < param_1) {
      if (param_1 < -0x3fffffff) {
        if (param_1 == -0x40000000) {
          param_1 = 0x40;
          param_4 = 0x40;
        }
      }
      else if (param_1 == DAT_02321854 >> 1) {
        param_1 = 0x40;
        param_4 = 0x20;
      }
    }
    else if (param_1 < DAT_02321854) {
      iVar1 = DAT_02321854 * 0x10000;
      if (param_1 == iVar1 || param_1 < iVar1) {
        if (param_1 == iVar1) {
          param_1 = 0x20;
          param_4 = 0x20;
        }
      }
      else if (param_1 == DAT_02321858) {
        param_1 = 0x20;
        param_4 = 0x10;
      }
    }
    else {
      param_1 = 0x10;
      param_4 = 0x20;
    }
  }
  else {
    param_1 = 0x20;
    param_4 = 0x40;
  }
  *param_2 = param_1;
  *param_3 = param_4;
  return;
}

