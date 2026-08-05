// decomp: module=arm7 addr=0x022c651c name=FUN_022c651c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70, arm
// triage: noise=6 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022c651c --addr 0x022c651c --size 0x70 --module arm7 --version 2.0/sp1


void FUN_022c651c(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = param_4;
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    FUN_022c6e94();
  }
  uVar1 = FUN_022c6d40();
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = param_4;
  param_1[1] = param_5;
  lVar3 = FUN_022c625c();
  lVar3 = lVar3 + CONCAT44(param_3,param_2);
  uVar2 = (undefined4)lVar3;
  FUN_022c63f0(param_1,uVar2,(int)((ulonglong)lVar3 >> 0x20),uVar2,iVar4);
  FUN_022c6d54(uVar1);
  return;
}

