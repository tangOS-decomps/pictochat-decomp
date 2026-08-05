// decomp: module=unk_autoload_0 addr=0x023271c0 name=FUN_023271c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x108 (Ghidra's cache says 0x104 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=88
// verify:  python tools/match.py --c <file> --func FUN_023271c0 --addr 0x023271c0 --size 0x108 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023271c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int a;
  int *piVar8;
  int local_4c [7];
  int local_30 [7];
  
  iVar6 = DAT_023272c4;
  a = *(int *)(DAT_023272c4 + 0x18);
  iVar4 = *(int *)(DAT_023272c4 + 0x14);
  if (param_1 < 1) {
    if (param_1 < 0) {
      iVar1 = FUN_02326774(a);
      iVar6 = DAT_023272c4;
      piVar7 = local_4c;
      *(int *)(DAT_023272c4 + 0x18) = iVar1;
      iVar5 = DAT_023272c4;
      piVar8 = (int *)(*(int *)(iVar6 + 8) + iVar1 * 0x1c);
      iVar6 = 3;
      do {
        iVar2 = *piVar8;
        iVar3 = piVar8[1];
        piVar8 = piVar8 + 2;
        *piVar7 = iVar2;
        piVar7[1] = iVar3;
        piVar7 = piVar7 + 2;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *piVar7 = *piVar8;
      do {
        if (local_4c[0] != *(int *)(*(int *)(iVar5 + 8) + iVar1 * 0x1c)) goto LAB_02327280;
        iVar1 = FUN_02326774(iVar1);
        *(int *)(iVar5 + 0x18) = iVar1;
      } while (iVar1 != *(int *)(iVar5 + 0x20));
      *(int *)(DAT_023272c4 + 0x18) = a;
LAB_02327280:
      iVar6 = *(int *)(DAT_023272c4 + 0x18);
      if (*(int *)(*(int *)(DAT_023272c4 + 8) + iVar6 * 0x1c) == 0) {
        *(int *)(DAT_023272c4 + 0x18) = a;
        return 0;
      }
      if (iVar6 != a) {
        iVar6 = FUN_02326764(iVar6);
        *(int *)(DAT_023272c4 + 0x18) = iVar6;
      }
    }
  }
  else {
    if (*(int *)(DAT_023272c4 + 0x20) == a) {
      return 0;
    }
    piVar8 = (int *)(*(int *)(DAT_023272c4 + 8) + a * 0x1c);
    piVar7 = local_30;
    iVar5 = 3;
    do {
      iVar1 = *piVar8;
      iVar2 = piVar8[1];
      piVar8 = piVar8 + 2;
      *piVar7 = iVar1;
      piVar7[1] = iVar2;
      piVar7 = piVar7 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *piVar7 = *piVar8;
    iVar5 = a;
    do {
      if (local_30[0] != *(int *)(*(int *)(iVar6 + 8) + iVar5 * 0x1c)) goto LAB_023272a2;
      iVar5 = FUN_02326764(iVar5);
      *(int *)(iVar6 + 0x18) = iVar5;
      iVar1 = FUN_02326764(*(int *)(iVar6 + 0x20));
    } while (iVar5 != iVar1);
    *(int *)(DAT_023272c4 + 0x18) = a;
  }
LAB_023272a2:
  if ((iVar4 == a * 8) && (param_2 != 0)) {
    *(int *)(DAT_023272c4 + 0x14) = *(int *)(DAT_023272c4 + 0x18) << 3;
  }
  else if (param_2 != 0) {
    *(int *)(DAT_023272c4 + 0x18) = a;
  }
  return 1;
}

