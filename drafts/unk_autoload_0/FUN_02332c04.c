// decomp: module=unk_autoload_0 addr=0x02332c04 name=FUN_02332c04
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x52 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02332c04 --addr 0x02332c04 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332c04(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02332080();
  if (*DAT_02332c58 == 0) {
    *DAT_02332c58 = (int)param_1;
    FUN_02332c68((int)(param_1 + 0x31));
    FUN_02332c68(DAT_02332c5c);
    param_1[0x30] = 0;
    FUN_02330da0(param_1,DAT_02332c60,param_1,DAT_02332c64,0x400,0x14,param_4);
    FUN_02330fb4(param_1);
  }
  FUN_02332094(uVar1);
  return;
}

