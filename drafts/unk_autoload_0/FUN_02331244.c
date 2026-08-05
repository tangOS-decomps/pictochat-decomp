// decomp: module=unk_autoload_0 addr=0x02331244 name=FUN_02331244
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c, thumb
// triage: noise=6 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02331244 --addr 0x02331244 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02331244(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_r1;
  
  uVar1 = FUN_02332080();
  iVar2 = *(int *)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x14) <= iVar2) {
    do {
      if ((param_3 & 1) == 0) {
        FUN_02332094(uVar1);
        return 0;
      }
      FUN_02330f38(param_1);
      iVar2 = *(int *)(param_1 + 0x1c);
    } while (*(int *)(param_1 + 0x14) <= iVar2);
  }
  FUN_02335e0c(*(int *)(param_1 + 0x18) + iVar2);
  *(undefined4 *)(*(int *)(param_1 + 0x10) + extraout_r1 * 4) = param_2;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_02330f6c(param_1 + 8);
  FUN_02332094(uVar1);
  return 1;
}

