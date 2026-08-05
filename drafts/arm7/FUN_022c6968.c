// decomp: module=arm7 addr=0x022c6968 name=FUN_022c6968
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022c6968 --addr 0x022c6968 --size 0x90 --module arm7 --version 2.0/sp1


void FUN_022c6968(int *param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_022c6d40();
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    FUN_022c6e94();
  }
  uVar1 = *DAT_022c69f4;
  iVar3 = FUN_022c6ce8((uint)uVar1);
  param_1[7] = 1;
  *(short *)(param_1 + 4) = (short)param_2;
  if (param_2 <= (int)(uint)uVar1) {
    iVar3 = iVar3 + 1;
  }
  param_1[3] = iVar3;
  *(undefined2 *)((int)param_1 + 0x12) = param_3;
  *param_1 = param_4;
  param_1[1] = param_5;
  param_1[9] = 0;
  FUN_022c67e8(param_1);
  FUN_022c6d54(uVar2);
  return;
}

