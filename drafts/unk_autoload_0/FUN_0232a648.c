// decomp: module=unk_autoload_0 addr=0x0232a648 name=FUN_0232a648
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x17c (Ghidra's cache says 0x16e - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=94
// verify:  python tools/match.py --c <file> --func FUN_0232a648 --addr 0x0232a648 --size 0x17c --module unk_autoload_0 --version 2.0/sp1


ushort * FUN_0232a648(int param_1,undefined1 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar7;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  ushort *puVar6;
  
  puVar3 = DAT_0232a7c0;
  if (param_2 == (undefined1 *)0x0) {
    local_12 = 0;
    local_10 = 0;
    local_e = 0;
  }
  else {
    local_12 = CONCAT11(*param_2,param_2[1]);
    local_10 = CONCAT11(param_2[2],param_2[3]);
    local_e = CONCAT11(param_2[4],param_2[5]);
  }
  if (*(int *)(DAT_0232a7b8 + 0x14) == 0) {
    DAT_0232a7c0[param_1 * 3] = local_12;
    puVar3[param_1 * 3 + 1] = local_10;
    puVar3[param_1 * 3 + 2] = local_e;
    uVar4 = FUN_0232a9f8();
    puVar6 = (ushort *)(uint)uVar4;
  }
  else {
    if (param_2 == (undefined1 *)0x0) {
      iVar7 = 0;
      puVar5 = (ushort *)(DAT_0232a7bc + param_1 * 6);
      puVar6 = DAT_0232a7c0;
      while (((*puVar6 != *puVar5 || (puVar6[1] != puVar5[1])) || (puVar6[2] != puVar5[2]))) {
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 3;
        if (0xf < iVar7) {
LAB_0232a784:
          *puVar5 = local_12;
          puVar5[1] = local_10;
          puVar5[2] = local_e;
          return (ushort *)(uint)local_e;
        }
      }
      DAT_0232a7c0[iVar7 * 3] = local_12;
      puVar3[iVar7 * 3 + 1] = local_10;
      puVar3[iVar7 * 3 + 2] = local_e;
      goto LAB_0232a784;
    }
    iVar7 = DAT_0232a7bc + param_1 * 6;
    *(ushort *)(DAT_0232a7bc + param_1 * 6) = local_12;
    *(ushort *)(iVar7 + 2) = local_10;
    *(ushort *)(iVar7 + 4) = local_e;
    puVar3 = DAT_0232a7c0;
    iVar7 = 0;
    puVar6 = DAT_0232a7c0;
    while (((local_12 != *puVar6 || (local_10 != puVar6[1])) || (local_e != puVar6[2]))) {
      iVar7 = iVar7 + 1;
      puVar6 = puVar6 + 3;
      if (0xf < iVar7) {
        iVar7 = 0;
        puVar6 = DAT_0232a7c0;
        while (((puVar5 = (ushort *)(uint)*puVar6, puVar5 != (ushort *)0x0 ||
                (puVar5 = (ushort *)(uint)puVar6[1], puVar5 != (ushort *)0x0)) ||
               (puVar5 = (ushort *)(uint)puVar6[2], puVar5 != (ushort *)0x0))) {
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 3;
          if (0xf < iVar7) {
            return puVar5;
          }
        }
        DAT_0232a7c0[iVar7 * 3] = local_12;
        puVar3[iVar7 * 3 + 1] = local_10;
        puVar3[iVar7 * 3 + 2] = local_e;
        return (ushort *)(uint)local_e;
      }
    }
    if (param_1 == 0) {
      uVar2 = DAT_0232a7c0[iVar7 * 3];
      uVar4 = DAT_0232a7c0[iVar7 * 3 + 1];
      uVar1 = DAT_0232a7c0[iVar7 * 3 + 2];
      DAT_0232a7c0[iVar7 * 3] = *DAT_0232a7c0;
      puVar3[iVar7 * 3 + 1] = puVar3[1];
      puVar3[iVar7 * 3 + 2] = puVar3[2];
      *puVar3 = uVar2;
      puVar3[1] = uVar4;
      puVar3[2] = uVar1;
      return (ushort *)(uint)uVar1;
    }
  }
  return puVar6;
}

