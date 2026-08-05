// decomp: module=unk_autoload_0 addr=0x02331ea8 name=FUN_02331ea8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=4 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02331ea8 --addr 0x02331ea8 --size 0x46 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331ea8(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    FUN_02332274();
  }
  uVar1 = FUN_02332080();
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = param_4;
  param_1[1] = param_5;
  lVar2 = FUN_02331ca8();
  lVar2 = lVar2 + CONCAT44(param_3,param_2);
  FUN_02331ddc(param_1,(int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
  FUN_02332094(uVar1);
  return;
}

