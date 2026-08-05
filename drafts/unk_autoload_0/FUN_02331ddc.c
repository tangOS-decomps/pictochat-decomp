// decomp: module=unk_autoload_0 addr=0x02331ddc name=FUN_02331ddc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc (Ghidra's cache says 0xc6 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=59
// verify:  python tools/match.py --c <file> --func FUN_02331ddc --addr 0x02331ddc --size 0xcc --module unk_autoload_0 --version 2.0/sp1


void FUN_02331ddc(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong lVar8;
  
  lVar2 = CONCAT44(param_3,param_2);
  if (*(int *)(param_1 + 0x20) != 0 || *(int *)(param_1 + 0x1c) != 0) {
    lVar8 = FUN_02331ca8();
    uVar3 = (uint)((ulonglong)lVar8 >> 0x20);
    puVar1 = (uint *)(param_1 + 0x24);
    lVar2 = *(longlong *)puVar1;
    if (*(uint *)(param_1 + 0x28) <= uVar3 &&
        (uint)((uint)lVar8 <= *puVar1) <= *(uint *)(param_1 + 0x28) - uVar3) {
      uVar5 = *(undefined4 *)(param_1 + 0x1c);
      uVar6 = *(undefined4 *)(param_1 + 0x20);
      lVar8 = FUN_02335da4((int)(lVar8 - *(longlong *)puVar1),
                           (int)((ulonglong)(lVar8 - *(longlong *)puVar1) >> 0x20),uVar5,uVar6);
      lVar8 = FUN_02335dec(uVar5,uVar6,(int)(lVar8 + 1),(int)((ulonglong)(lVar8 + 1) >> 0x20));
      lVar2 = lVar8 + lVar2;
    }
  }
  iVar4 = (int)((ulonglong)lVar2 >> 0x20);
  *(uint *)(param_1 + 0xc) = (uint)lVar2;
  iVar7 = DAT_02331ea4;
  *(int *)(param_1 + 0x10) = iVar4;
  for (iVar7 = *(int *)(iVar7 + 4); iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x18)) {
    if ((int)((iVar4 - *(int *)(iVar7 + 0x10)) - (uint)((uint)lVar2 < *(uint *)(iVar7 + 0xc))) < 0)
    {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar7 + 0x14);
      *(int *)(iVar7 + 0x14) = param_1;
      *(int *)(param_1 + 0x18) = iVar7;
      if (*(int *)(param_1 + 0x14) == 0) {
        *(int *)(DAT_02331ea4 + 4) = param_1;
        FUN_02331d1c(param_1);
        return;
      }
      *(int *)(*(int *)(param_1 + 0x14) + 0x18) = param_1;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar7 = DAT_02331ea4;
  iVar4 = *(int *)(DAT_02331ea4 + 8);
  *(int *)(DAT_02331ea4 + 8) = param_1;
  *(int *)(param_1 + 0x14) = iVar4;
  if (iVar4 == 0) {
    *(int *)(iVar7 + 8) = param_1;
    *(int *)(iVar7 + 4) = param_1;
    FUN_02331d1c(param_1);
    return;
  }
  *(int *)(iVar4 + 0x18) = param_1;
  return;
}

