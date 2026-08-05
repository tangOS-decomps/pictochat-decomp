// decomp: module=unk_autoload_0 addr=0x023312a0 name=FUN_023312a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x66, thumb
// triage: noise=10 statements=24
// verify:  python tools/match.py --c <file> --func FUN_023312a0 --addr 0x023312a0 --size 0x66 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023312a0(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  
  uVar1 = FUN_02332080();
  if (*(int *)(param_1 + 0x1c) == 0) {
    do {
      if ((param_3 & 1) == 0) {
        FUN_02332094(uVar1);
        return 0;
      }
      FUN_02330f38(param_1 + 8);
    } while (*(int *)(param_1 + 0x1c) == 0);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
  }
  FUN_02335e0c(*(int *)(param_1 + 0x18) + 1,*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x18) = extraout_r1;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  FUN_02330f6c(param_1);
  FUN_02332094(uVar1);
  return 1;
}

