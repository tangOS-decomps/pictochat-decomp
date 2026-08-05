// decomp: module=arm7 addr=0x022c63f0 name=FUN_022c63f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x12c (Ghidra's cache says 0x128 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=70
// verify:  python tools/match.py --c <file> --func FUN_022c63f0 --addr 0x022c63f0 --size 0x12c --module arm7 --version 2.0/sp1


void FUN_022c63f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  longlong lVar12;
  
  lVar1 = CONCAT44(param_3,param_2);
  if (*(int *)(param_1 + 0x20) != 0 || *(int *)(param_1 + 0x1c) != 0) {
    uVar11 = FUN_022c625c();
    uVar5 = (uint)((ulonglong)uVar11 >> 0x20);
    uVar4 = (uint)uVar11;
    uVar7 = *(uint *)(param_1 + 0x28);
    uVar9 = *(uint *)(param_1 + 0x24);
    lVar1 = *(longlong *)(param_1 + 0x24);
    bVar10 = uVar5 <= uVar7;
    if (uVar7 == uVar5) {
      bVar10 = uVar4 <= uVar9;
    }
    if (!bVar10) {
      lVar2 = *(longlong *)(param_1 + 0x1c);
      lVar12 = FUN_022c3f7c(uVar4 - uVar9,uVar5 - (uVar7 + (uVar4 < uVar9)),
                            *(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20));
      lVar1 = (lVar12 + 1) * lVar2 + lVar1;
    }
  }
  iVar8 = (int)((ulonglong)lVar1 >> 0x20);
  *(uint *)(param_1 + 0xc) = (uint)lVar1;
  iVar6 = DAT_022c6518;
  *(int *)(param_1 + 0x10) = iVar8;
  iVar3 = DAT_022c6518;
  iVar6 = *(int *)(iVar6 + 4);
  while( true ) {
    if (iVar6 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      iVar6 = *(int *)(iVar3 + 8);
      *(int *)(iVar3 + 8) = param_1;
      *(int *)(param_1 + 0x14) = iVar6;
      if (iVar6 == 0) {
        *(int *)(iVar3 + 8) = param_1;
        *(int *)(iVar3 + 4) = param_1;
        FUN_022c6300(param_1);
      }
      else {
        *(int *)(iVar6 + 0x18) = param_1;
      }
      return;
    }
    if ((int)(iVar8 - (*(int *)(iVar6 + 0x10) + (uint)((uint)lVar1 < *(uint *)(iVar6 + 0xc)))) < 0)
    break;
    iVar6 = *(int *)(iVar6 + 0x18);
  }
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar6 + 0x14);
  *(int *)(iVar6 + 0x14) = param_1;
  *(int *)(param_1 + 0x18) = iVar6;
  if (*(int *)(param_1 + 0x14) == 0) {
    *(int *)(DAT_022c6518 + 4) = param_1;
    FUN_022c6300(param_1);
    return;
  }
  *(int *)(*(int *)(param_1 + 0x14) + 0x18) = param_1;
  return;
}

