// decomp: module=arm7 addr=0x022c5038 name=FUN_022c5038
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x108 (Ghidra's cache says 0xf8 - it excludes this function's trailing literal pool), arm
// triage: noise=23 statements=39
// verify:  python tools/match.py --c <file> --func FUN_022c5038 --addr 0x022c5038 --size 0x108 --module arm7 --version 2.0/sp1


void FUN_022c5038(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_022c6d40();
  iVar3 = *(int *)(DAT_022c5130 + 0x18) + 1;
  *(int *)(DAT_022c5130 + 0x18) = iVar3;
  *(undefined4 *)(param_1 + 0x54) = param_6;
  *(int *)(param_1 + 0x50) = iVar3;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  FUN_022c4d84(param_1);
  *(int *)(param_1 + 0x78) = param_4;
  *(int *)(param_1 + 0x74) = param_4 - param_5;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  uVar1 = DAT_022c5138;
  *(undefined4 *)(*(int *)(param_1 + 0x78) + -8) = DAT_022c5134;
  **(undefined4 **)(param_1 + 0x74) = uVar1;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  FUN_022c55bc(param_1,param_2,param_4 + -8);
  uVar1 = DAT_022c513c;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  FUN_022c6fc8(0,(param_4 - param_5) + 4,param_5 + -0xc);
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  FUN_022c6fc8(0,param_1 + 0x88,0xc);
  *(undefined4 *)(param_1 + 0x94) = 0;
  FUN_022c6d54(uVar2);
  return;
}

