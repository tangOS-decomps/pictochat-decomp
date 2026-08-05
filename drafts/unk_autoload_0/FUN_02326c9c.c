// decomp: module=unk_autoload_0 addr=0x02326c9c name=FUN_02326c9c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x524 (Ghidra's cache says 0x502 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=312
// verify:  python tools/match.py --c <file> --func FUN_02326c9c --addr 0x02326c9c --size 0x524 --module unk_autoload_0 --version 2.0/sp1


void FUN_02326c9c(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int local_d0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0 [7];
  int local_94 [7];
  int local_78 [7];
  int local_5c [9];
  byte local_35;
  undefined4 local_34 [4];
  undefined4 local_24 [4];
  
  if (*(int *)(DAT_02326f8c + 0x14) != *(int *)(DAT_02326f8c + 0x18) * 8) {
    if (*(int *)(DAT_02326f8c + 4) == 0x380) {
      iVar10 = *(int *)(DAT_02326f8c + 0x20);
      FUN_02326774(iVar10);
      FUN_02326718();
    }
    else {
      iVar10 = 0;
    }
    iVar2 = FUN_02326718(*(undefined4 *)(DAT_02326f8c + 0x18));
    if (iVar2 == iVar10) {
      iVar2 = iVar2 + 0x400;
    }
    iVar3 = FUN_02326718(*(int *)(DAT_02326f8c + 0x14) >> 3);
    iVar3 = (*(uint *)(DAT_02326f8c + 0x14) & 7) + iVar3 * 8;
    if ((iVar3 >> 3 <= iVar10) && (*(int *)(DAT_02326f8c + 4) == 0x380)) {
      iVar3 = iVar3 + 0x2000;
    }
    iVar10 = iVar2 * 8;
    if (iVar10 - iVar3 == 0 || iVar10 < iVar3) {
      iVar12 = iVar3;
      if (iVar10 < iVar3) {
        iVar12 = iVar3 + iVar2 * -8 >> 3;
        if (iVar12 < 6) {
          iVar12 = 6;
        }
        iVar12 = iVar3 - iVar12;
        if (iVar10 - iVar12 != 0 && iVar12 <= iVar10) {
          iVar12 = iVar10;
        }
      }
    }
    else {
      iVar2 = iVar10 - iVar3 >> 3;
      if (iVar2 < 6) {
        iVar2 = 6;
      }
      iVar12 = iVar3 + iVar2;
      if (iVar10 < iVar3 + iVar2) {
        iVar12 = iVar10;
      }
    }
    for (; 0x1fff < iVar12; iVar12 = iVar12 + -0x2000) {
    }
    *(int *)(DAT_02326f8c + 0x14) = iVar12;
  }
  uVar4 = FUN_02320c74();
  FUN_02320f00(uVar4,DAT_02326f90,DAT_02326f94,0x14,1);
  uVar4 = FUN_02320c74();
  FUN_02320f00(uVar4,DAT_02326f90,DAT_02326f94,0x15,1);
  local_24[0] = *DAT_02326f98;
  local_24[1] = DAT_02326f98[1];
  local_24[2] = DAT_02326f98[2];
  local_24[3] = DAT_02326f98[3];
  uVar4 = FUN_02320c74(local_24[2],local_24[3],&stack0xffffffec,DAT_02326f98 + 4);
  piVar5 = FUN_023260bc();
  FUN_02320f24(uVar4,DAT_02326f90,DAT_02326f94,local_24[*piVar5],0,
               *(undefined4 *)(DAT_02326f8c + 0x24),1);
  local_34[0] = *DAT_02326f9c;
  local_34[1] = DAT_02326f9c[1];
  local_34[2] = DAT_02326f9c[2];
  local_34[3] = DAT_02326f9c[3];
  uVar4 = FUN_02320c74(local_34[2],local_34[3],local_24,DAT_02326f9c + 4);
  FUN_023299ac();
  iVar10 = FUN_02329270();
  FUN_02320f24(uVar4,DAT_02326f90,DAT_02326f94,local_34[iVar10],0,-*(int *)(DAT_02326f8c + 0x24),1);
  iVar10 = *(int *)(DAT_02326f8c + 0x24);
  if (iVar10 < *(int *)(DAT_02326f8c + 0x28)) {
    *(int *)(DAT_02326f8c + 0x24) = iVar10 + 1;
  }
  else if (*(int *)(DAT_02326f8c + 0x28) < iVar10) {
    *(int *)(DAT_02326f8c + 0x24) = iVar10 + -1;
  }
  iVar10 = 0;
  if (0 < *(int *)(DAT_02326f8c + 4)) {
    iVar2 = FUN_02326774(*(int *)(DAT_02326f8c + 0x1c));
    for (; iVar10 < 0x22; iVar10 = iVar10 + 1) {
      piVar5 = local_5c + 3;
      piVar13 = (int *)(*(int *)(DAT_02326f8c + 8) + iVar2 * 0x1c);
      iVar3 = 3;
      do {
        iVar12 = *piVar13;
        iVar7 = piVar13[1];
        piVar13 = piVar13 + 2;
        *piVar5 = iVar12;
        piVar5[1] = iVar7;
        piVar5 = piVar5 + 2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      *piVar5 = *piVar13;
      local_b8 = (uint)local_35 * 2 + 1;
      iVar12 = (int)*(uint *)(DAT_02326f8c + 0x14) >> 3;
      iVar3 = iVar2;
      if ((*(uint *)(DAT_02326f8c + 0x14) & 3) == 0) {
        iVar12 = FUN_02326774(iVar12);
        iVar7 = 0x18;
      }
      else {
        iVar7 = 0x19;
      }
      for (; 0 < local_b8; local_b8 = local_b8 + -1) {
        iVar3 = FUN_02326774(iVar3);
      }
      iVar3 = FUN_02326764(iVar3);
      for (; 0 < iVar7; iVar7 = iVar7 + -1) {
        if ((iVar12 == iVar3) || (iVar12 == iVar2)) {
          uVar4 = 1;
          goto LAB_02326e8c;
        }
        iVar12 = FUN_02326774(iVar12);
        if (iVar12 == *(int *)(DAT_02326f8c + 0x20)) break;
      }
      uVar4 = 0;
LAB_02326e8c:
      FUN_02326c2c(iVar10,iVar2,0,uVar4);
      iVar3 = DAT_02326f8c;
      for (; iVar12 = *(int *)(*(int *)(iVar3 + 8) + iVar2 * 0x1c), local_5c[3] == iVar12;
          iVar2 = FUN_02326774(iVar2)) {
      }
      if ((iVar12 == 0) || (iVar3 = FUN_02326764(iVar2), *(int *)(DAT_02326f8c + 0x20) == iVar3))
      break;
    }
    iVar3 = DAT_02326f8c;
    if (iVar10 == 0x22) {
      for (iVar10 = 0; iVar10 < 2; iVar10 = iVar10 + 1) {
        piVar13 = (int *)(*(int *)(iVar3 + 8) + iVar2 * 0x1c);
        piVar5 = local_b0;
        iVar12 = 3;
        do {
          iVar7 = *piVar13;
          iVar6 = piVar13[1];
          piVar13 = piVar13 + 2;
          *piVar5 = iVar7;
          piVar5[1] = iVar6;
          piVar5 = piVar5 + 2;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *piVar5 = *piVar13;
        FUN_02326c2c(iVar10 + 0x22,iVar2,0,0);
        for (; iVar12 = *(int *)(*(int *)(iVar3 + 8) + iVar2 * 0x1c), local_b0[0] == iVar12;
            iVar2 = FUN_02326774(iVar2)) {
        }
        if ((iVar12 == 0) || (iVar12 = FUN_02326764(iVar2), *(int *)(iVar3 + 0x20) == iVar12))
        break;
      }
    }
    iVar10 = DAT_02326f8c;
    iVar2 = *(int *)(DAT_02326f8c + 0x1c);
    if (iVar2 != *(int *)(DAT_02326f8c + 0x20)) {
      for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
        piVar13 = (int *)(*(int *)(iVar10 + 8) + iVar2 * 0x1c);
        piVar5 = local_94;
        iVar12 = 3;
        do {
          iVar7 = *piVar13;
          iVar6 = piVar13[1];
          piVar13 = piVar13 + 2;
          *piVar5 = iVar7;
          piVar5[1] = iVar6;
          piVar5 = piVar5 + 2;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *piVar5 = *piVar13;
        if (local_94[0] == 0) break;
        FUN_02326c2c(-1 - iVar3,iVar2,0,0);
        for (; local_94[0] == *(int *)(*(int *)(iVar10 + 8) + iVar2 * 0x1c);
            iVar2 = FUN_02326764(iVar2)) {
        }
        if (iVar2 == *(int *)(iVar10 + 0x20)) break;
      }
    }
  }
  uVar8 = *(uint *)(DAT_02326f8c + 0x14);
  local_bc = (int)uVar8 >> 3;
  FUN_02326780();
  FUN_023273dc();
  local_b4 = 0;
  do {
    iVar2 = local_bc * 0x1c;
    iVar10 = *(int *)(DAT_023271b4 + 8) + iVar2;
    if (*(short *)(iVar10 + 4) != 0) {
      iVar10 = FUN_023273fc(iVar10 + 4);
      *(ushort *)(iVar10 + 0x16) = (ushort)*(byte *)(*(int *)(DAT_023271b4 + 8) + iVar2 + 0x1a);
      if (*(short *)(iVar10 + 0x16) == 0x10) {
        *(undefined2 *)(iVar10 + 0x16) = 0;
      }
      iVar3 = (0x17 - local_b4) * 8 - (uVar8 & 7);
      FUN_023210c8(iVar10,0,iVar3,1,0);
      if (*(char *)(*(int *)(DAT_023271b4 + 8) + iVar2 + 0x1b) == '\x01') {
        local_5c[0] = 9;
        local_5c[1] = 10;
        local_5c[2] = 0xb;
      }
      else {
        local_5c[0] = 6;
        local_5c[1] = 7;
        local_5c[2] = 8;
      }
      for (uVar11 = 0; uVar11 < 3; uVar11 = uVar11 + 1) {
        if (*(ushort *)(iVar10 + 0xc) < 0x33) {
          local_d0 = 0;
        }
        else {
          local_d0 = (int)((*(ushort *)(iVar10 + 0xc) - 0x32) * uVar11) / 2;
        }
        uVar4 = FUN_02320c74();
        FUN_02320f74(uVar4,DAT_023271bc,DAT_023271b8,local_5c[uVar11],local_d0,iVar3,
                     *(undefined1 *)(iVar2 + *(int *)(DAT_023271b4 + 8) + 0x1a),1);
      }
    }
    local_bc = FUN_02326774(local_bc);
    local_b4 = local_b4 + 1;
  } while (local_b4 < 0x19);
  FUN_02327474();
  if (0 < *(int *)(DAT_023271b4 + 4)) {
    iVar10 = (int)*(uint *)(DAT_023271b4 + 0x14) >> 3;
    if ((*(uint *)(DAT_023271b4 + 0x14) & 3) == 0) {
      iVar10 = FUN_02326774(iVar10);
      iVar12 = 0x17;
      iVar2 = DAT_023271b4;
      iVar3 = iVar10;
    }
    else {
      iVar12 = 0x18;
      iVar2 = DAT_023271b4;
      iVar3 = iVar10;
    }
    for (; 0 < iVar12; iVar12 = iVar12 + -1) {
      iVar10 = FUN_02326774(iVar10);
      if ((*(int *)(*(int *)(iVar2 + 8) + iVar10 * 0x1c) == 0) ||
         (iVar7 = FUN_02326764(iVar10), *(int *)(iVar2 + 0x20) == iVar7)) {
        iVar10 = FUN_02326764(iVar10);
        break;
      }
    }
    iVar10 = FUN_02326718(iVar10);
    iVar2 = FUN_02326718(iVar3);
    do {
      if (*(int *)(DAT_023271b4 + 4) < 1) {
        iVar3 = 0;
        iVar12 = 0;
        bVar1 = false;
      }
      else {
        iVar3 = FUN_02326774(*(int *)(DAT_023271b4 + 0x1c));
        for (iVar12 = 0; iVar12 < 0x22; iVar12 = iVar12 + 1) {
          piVar5 = local_78;
          piVar13 = (int *)(*(int *)(DAT_023271b4 + 8) + iVar3 * 0x1c);
          iVar7 = 3;
          do {
            iVar6 = *piVar13;
            iVar9 = piVar13[1];
            piVar13 = piVar13 + 2;
            *piVar5 = iVar6;
            piVar5[1] = iVar9;
            piVar5 = piVar5 + 2;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          *piVar5 = *piVar13;
          for (; iVar7 = *(int *)(*(int *)(DAT_023271b4 + 8) + iVar3 * 0x1c), local_78[0] == iVar7;
              iVar3 = FUN_02326774(iVar3)) {
          }
          if ((iVar7 == 0) || (iVar7 = FUN_02326764(iVar3), *(int *)(DAT_023271b4 + 0x20) == iVar7))
          break;
        }
        iVar3 = FUN_02326764(iVar3);
        iVar12 = FUN_02326774(*(int *)(DAT_023271b4 + 0x1c));
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      iVar3 = FUN_02326718(iVar3);
      iVar12 = FUN_02326718(iVar12);
      if (iVar10 < iVar3) {
        iVar7 = FUN_02326774(*(int *)(DAT_023271b4 + 0x1c));
        *(int *)(DAT_023271b4 + 0x1c) = iVar7;
      }
      if (iVar12 < iVar2) {
        iVar7 = FUN_02326764(*(int *)(DAT_023271b4 + 0x1c));
        *(int *)(DAT_023271b4 + 0x1c) = iVar7;
      }
    } while ((iVar10 < iVar3) || (iVar12 < iVar2));
  }
  return;
}

