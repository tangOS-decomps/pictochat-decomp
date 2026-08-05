// decomp: module=unk_autoload_0 addr=0x02325408 name=FUN_02325408
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x234 (Ghidra's cache says 0x22e - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=132
// verify:  python tools/match.py --c <file> --func FUN_02325408 --addr 0x02325408 --size 0x234 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325408(int param_1)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint a;
  int iVar7;
  uint uVar8;
  uint a_00;
  uint uVar9;
  int local_38;
  int local_34;
  int local_2c;
  int local_28;
  uint local_20;
  uint local_1c;
  
  iVar3 = FUN_023212e0();
  if (iVar3 == 0) {
    if (*(short *)(param_1 + 0x50) == 0) {
      return;
    }
    *(ushort *)(param_1 + 0x48) = (ushort)DAT_02325638 & *(ushort *)(param_1 + 0x48);
    FUN_023278e0();
    return;
  }
  iVar3 = FUN_023212ec();
  if (iVar3 == 1) {
    uVar4 = FUN_023212f8();
    uVar5 = FUN_02321304();
    iVar3 = FUN_02325c4c(uVar4,uVar5);
    if (iVar3 != 0) {
      *(ushort *)(param_1 + 0x48) = *(ushort *)(param_1 + 0x48) | 0x100;
      if ((*(ushort *)(param_1 + 0x48) & 0xff) >> 4 == 2) {
        uVar4 = 0xd;
      }
      else {
        uVar4 = 0xe;
      }
      FUN_023278ac(uVar4);
      uVar4 = FUN_023212f8();
      uVar5 = FUN_02321304();
      FUN_02325308(param_1,uVar4,uVar5);
      goto LAB_023255f8;
    }
  }
  if ((int)((uint)*(ushort *)(param_1 + 0x48) << 0x17) < 0) {
    uVar4 = FUN_023212f8();
    uVar5 = FUN_02321304();
    iVar3 = FUN_02325c4c(uVar4,uVar5);
    if (iVar3 == 0) {
      FUN_02325c88(0,0,0,0);
      FUN_023278f0();
    }
    else {
      uVar4 = FUN_023212f8();
      uVar5 = FUN_02321304();
      FUN_02325c88(*(undefined2 *)(param_1 + 0x4c),*(undefined2 *)(param_1 + 0x4e),uVar4,uVar5);
      FUN_023278f0();
    }
    local_20 = FUN_02321304();
    local_1c = FUN_023212f8();
    a = (uint)*(ushort *)(param_1 + 0x4e);
    a_00 = (uint)*(ushort *)(param_1 + 0x4c);
    iVar3 = FUN_02325c7c(a_00,local_1c);
    iVar6 = FUN_02325c7c(a,local_20);
    if (iVar6 < iVar3) {
      bVar1 = (int)a_00 <= (int)local_1c;
      uVar8 = a;
      uVar9 = a_00;
      if (!bVar1) {
        uVar8 = local_20;
        uVar9 = local_1c;
        local_20 = a;
        local_1c = a_00;
      }
      iVar6 = local_1c - uVar9;
      iVar3 = FUN_02335e0c((local_20 - uVar8) * 0x1000,iVar6);
      if (bVar1) {
        local_34 = 0;
        for (local_38 = 0; local_38 <= iVar6; local_38 = local_38 + 1) {
          FUN_02325308(param_1,uVar9 + local_38,uVar8 + (local_34 >> 0xc));
          local_34 = local_34 + iVar3;
        }
      }
      else {
        iVar7 = 0;
        for (; -1 < iVar6; iVar6 = iVar6 + -1) {
          FUN_02325308(param_1,uVar9 + iVar6,local_20 - (iVar7 >> 0xc));
          iVar7 = iVar7 + iVar3;
        }
      }
    }
    else {
      bVar1 = (int)local_20 < (int)a;
      uVar8 = a;
      uVar9 = a_00;
      if (bVar1) {
        uVar8 = local_20;
        uVar9 = local_1c;
        local_20 = a;
        local_1c = a_00;
      }
      iVar6 = local_20 - uVar8;
      iVar3 = FUN_02335e0c((local_1c - uVar9) * 0x1000,iVar6);
      if (bVar1) {
        iVar7 = 0;
        for (; -1 < iVar6; iVar6 = iVar6 + -1) {
          FUN_02325308(param_1,local_1c - (iVar7 >> 0xc),uVar8 + iVar6);
          iVar7 = iVar7 + iVar3;
        }
      }
      else {
        local_28 = 0;
        for (local_2c = 0; local_2c <= iVar6; local_2c = local_2c + 1) {
          FUN_02325308(param_1,uVar9 + (local_28 >> 0xc),uVar8 + local_2c);
          local_28 = local_28 + iVar3;
        }
      }
    }
  }
LAB_023255f8:
  uVar2 = FUN_023212f8();
  *(undefined2 *)(param_1 + 0x4c) = uVar2;
  uVar2 = FUN_02321304();
  *(undefined2 *)(param_1 + 0x4e) = uVar2;
  iVar3 = FUN_023212e0();
  *(short *)(param_1 + 0x50) = (short)iVar3;
  return;
}

