// decomp: module=arm7 addr=0x022c57d8 name=FUN_022c57d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, arm
// triage: noise=5 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022c57d8 --addr 0x022c57d8 --size 0x74 --module arm7 --version 2.0/sp1


undefined4 FUN_022c57d8(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_022c6d40();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
      }
      FUN_022c6d54(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_022c5274(param_1 + 8);
  }
  FUN_022c6d54(uVar1);
  return 0;
}

