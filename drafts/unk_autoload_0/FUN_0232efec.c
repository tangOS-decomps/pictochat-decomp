// decomp: module=unk_autoload_0 addr=0x0232efec name=FUN_0232efec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232efec --addr 0x0232efec --size 0x64 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232efec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  FUN_0232f050();
  if (*DAT_0232f04c != 0) {
    return 0;
  }
  FUN_02337440(0,param_1,param_2);
  FUN_02331504(param_1,param_2);
  uVar1 = FUN_0232f0d0(1,param_1,param_1 + (param_2 >> 1),param_2 >> 1,param_3,0,0,1,param_4,0x7f,0,
                       0x7f,param_5,param_6,param_7);
  return uVar1;
}

