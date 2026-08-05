// decomp: module=arm7 addr=0x022c573c name=FUN_022c573c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c, arm
// triage: noise=10 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022c573c --addr 0x022c573c --size 0x9c --module arm7 --version 2.0/sp1


undefined4 FUN_022c573c(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  
  uVar1 = FUN_022c6d40();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
      }
      FUN_022c4014(*(int *)(param_1 + 0x18) + 1,*(undefined4 *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x18) = extraout_r1;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      FUN_022c52c8(param_1);
      FUN_022c6d54(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_022c5274(param_1 + 8);
  }
  FUN_022c6d54(uVar1);
  return 0;
}

