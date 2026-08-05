// decomp: module=unk_autoload_0 addr=0x02331308 name=FUN_02331308
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60, thumb
// triage: noise=7 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02331308 --addr 0x02331308 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02331308(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = FUN_02332080();
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 <= *(int *)(param_1 + 0x1c)) {
    do {
      if ((param_3 & 1) == 0) {
        FUN_02332094(uVar1);
        return 0;
      }
      FUN_02330f38(param_1);
      iVar2 = *(int *)(param_1 + 0x14);
    } while (iVar2 <= *(int *)(param_1 + 0x1c));
  }
  FUN_02335e0c(*(int *)(param_1 + 0x18) + iVar2 + -1);
  *(int *)(param_1 + 0x18) = extraout_r1;
  *(undefined4 *)(*(int *)(param_1 + 0x10) + extraout_r1 * 4) = param_2;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_02330f6c(param_1 + 8);
  FUN_02332094(uVar1);
  return 1;
}

