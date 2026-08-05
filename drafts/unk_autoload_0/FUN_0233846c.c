// decomp: module=unk_autoload_0 addr=0x0233846c name=FUN_0233846c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x62, thumb
// triage: noise=11 statements=36
// verify:  python tools/match.py --c <file> --func FUN_0233846c --addr 0x0233846c --size 0x62 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233846c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = FUN_02332080();
  iVar6 = param_1[2];
  if (iVar6 != 0) {
    puVar3 = *(undefined4 **)(iVar6 + 8);
    puVar2 = (undefined4 *)(iVar6 + 8);
    while (puVar1 = puVar3, puVar1 != (undefined4 *)0x0) {
      if (puVar1 == param_1) {
        *puVar2 = *param_1;
        break;
      }
      puVar2 = puVar1;
      puVar3 = (undefined4 *)*puVar1;
    }
    *param_1 = 0;
  }
  uVar7 = (uint)param_1[3] >> 8 & 0xff;
  iVar5 = FUN_0233844c(uVar7);
  if (iVar5 == 0) {
    *(uint *)(iVar6 + 0x18) = uVar7;
    *(undefined4 *)(iVar6 + 0x1c) = param_2;
  }
  param_1[5] = param_2;
  param_1[3] = param_1[3] & 0xffffff30;
  FUN_02330f6c(param_1 + 6);
  FUN_02332094(uVar4);
  return;
}

