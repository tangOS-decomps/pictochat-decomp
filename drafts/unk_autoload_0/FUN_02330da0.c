// decomp: module=unk_autoload_0 addr=0x02330da0 name=FUN_02330da0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd8 (Ghidra's cache says 0xcc - it excludes this function's trailing literal pool), thumb
// triage: noise=25 statements=36
// verify:  python tools/match.py --c <file> --func FUN_02330da0 --addr 0x02330da0 --size 0xd8 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330da0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_02332080();
  uVar2 = FUN_02330afc();
  *(undefined4 *)(param_1 + 0x70) = param_6;
  *(undefined4 *)(param_1 + 0x6c) = uVar2;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  FUN_02330be8(param_1);
  *(int *)(param_1 + 0x94) = param_4;
  *(int *)(param_1 + 0x90) = param_4 - param_5;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x94) + -8) = DAT_02330e6c;
  **(undefined4 **)(param_1 + 0x90) = DAT_02330e70;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0xa0);
  FUN_023310dc(param_1,param_2,param_4 + -8);
  uVar2 = DAT_02330e74;
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  FUN_02337440(0,(param_4 - param_5) + 4,param_5 + -0xc);
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  FUN_023310d4(param_1,0);
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x80);
  FUN_02337440(0,param_1 + 0xa4,0xc);
  *(undefined4 *)(param_1 + 0xb0) = 0;
  FUN_02332094(uVar1);
  return;
}

