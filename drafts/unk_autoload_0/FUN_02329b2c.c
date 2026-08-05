// decomp: module=unk_autoload_0 addr=0x02329b2c name=FUN_02329b2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02329b2c --addr 0x02329b2c --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329b2c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(DAT_02329b6c + 0x10) == 0) {
    if (param_2 == 0) {
      iVar1 = FUN_0232996c();
      if (0xb < iVar1) {
        return;
      }
    }
    else {
      FUN_02329bf0(2);
    }
    iVar1 = FUN_0232cae8(param_1);
    *(undefined4 *)(DAT_02329b6c + 0x10) = 1;
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
      *(undefined4 *)(DAT_02329b6c + 0x10) = 0;
    }
  }
  return;
}

