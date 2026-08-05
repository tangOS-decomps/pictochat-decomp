// decomp: module=arm7 addr=0x022c56b0 name=FUN_022c56b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c, arm
// triage: noise=6 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022c56b0 --addr 0x022c56b0 --size 0x8c --module arm7 --version 2.0/sp1


undefined4 FUN_022c56b0(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int extraout_r1;
  
  uVar1 = FUN_022c6d40();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x14)) {
      FUN_022c4014(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c));
      *(undefined4 *)(*(int *)(param_1 + 0x10) + extraout_r1 * 4) = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      FUN_022c52c8(param_1 + 8);
      FUN_022c6d54(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_022c5274(param_1);
  }
  FUN_022c6d54(uVar1);
  return 0;
}

