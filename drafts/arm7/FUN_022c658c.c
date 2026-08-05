// decomp: module=arm7 addr=0x022c658c name=FUN_022c658c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, arm
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022c658c --addr 0x022c658c --size 0x74 --module arm7 --version 2.0/sp1


void FUN_022c658c(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    FUN_022c6e94();
  }
  uVar1 = FUN_022c6d40();
  param_1[7] = param_4;
  param_1[8] = param_5;
  param_1[9] = param_2;
  param_1[10] = param_3;
  *param_1 = param_6;
  param_1[1] = param_7;
  FUN_022c63f0(param_1,0,0);
  FUN_022c6d54(uVar1);
  return;
}

