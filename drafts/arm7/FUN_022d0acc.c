// decomp: module=arm7 addr=0x022d0acc name=FUN_022d0acc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e0 (Ghidra's cache says 0x3cc - it excludes this function's trailing literal pool), arm
// triage: noise=17 statements=170
// verify:  python tools/match.py --c <file> --func FUN_022d0acc --addr 0x022d0acc --size 0x3e0 --module arm7 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x022d0c64) */

void FUN_022d0acc(void)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined2 *puVar8;
  undefined4 in_r3;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  int unaff_r10;
  undefined1 auStack_234 [6];
  undefined1 auStack_22e [6];
  undefined1 auStack_228 [512];
  undefined4 local_28;
  
  bVar3 = false;
  psVar10 = *(short **)(DAT_022d0e98 + 0x550);
  local_28 = in_r3;
  uVar4 = func_0x037cb520();
  if (*(int *)(psVar10 + 6) == 1) {
    psVar10[6] = 0;
    psVar10[7] = 0;
    bVar3 = true;
    FUN_022d3bd4();
    FUN_022ce658();
    if (*psVar10 == 10) {
      *psVar10 = 8;
    }
    else if (*psVar10 == 9) {
      *psVar10 = 7;
    }
  }
  sVar1 = *psVar10;
  if ((ushort)(sVar1 - 7U) < 2) {
    if (sVar1 == 7) {
      unaff_r10 = 1;
    }
    uVar11 = (uint)(ushort)psVar10[0xc1];
    if (sVar1 != 7) {
      unaff_r10 = 0;
    }
  }
  else {
    uVar11 = 0;
  }
  psVar10[0xc1] = 0;
  psVar10[0x43] = 0;
  psVar10[10] = 0;
  psVar10[0xb] = 0;
  psVar10[8] = 0;
  psVar10[9] = 0;
  psVar10[0xe] = 0;
  psVar10[0xf] = 0;
  psVar10[0x61] = 0;
  func_0x037cb534(uVar4);
  if (bVar3) {
    FUN_022d5870(DAT_022d0e9c);
  }
  if (unaff_r10 != 0) {
    psVar10[0x7b] = 0;
  }
  if (uVar11 != 0) {
    uVar9 = 0;
    do {
      if ((uVar11 & 1 << (uVar9 & 0xff)) != 0) {
        FUN_022d2ad8(unaff_r10,uVar9 & 0xffff);
      }
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < 0x10);
  }
  func_0x037cb820(psVar10 + 0x94,0,0x5a);
  iVar5 = FUN_022d0960((int)auStack_228);
  if (*(short *)(iVar5 + 4) != 0) {
    FUN_022d0eac(0x308);
    return;
  }
  uVar2 = *(ushort *)(iVar5 + 6);
  iVar5 = FUN_022d08a8((int)auStack_228);
  if (*(short *)(iVar5 + 4) != 0) {
    FUN_022d0eac(0x284);
    return;
  }
  sVar1 = *(short *)(iVar5 + 6);
  if (uVar2 < 0x21) {
    if (0x1f < uVar2) goto LAB_022d0d60;
    if (uVar2 == 0) goto LAB_022d0d84;
    if ((0x12 < uVar2) || (uVar2 < 0x10)) goto LAB_022d0e64;
    if (uVar2 != 0x10) {
      if (uVar2 != 0x11 && uVar2 != 0x12) goto LAB_022d0e64;
      if ((sVar1 == 0) && (iVar5 = FUN_022d0974(auStack_228,0,0,0x14,1), *(short *)(iVar5 + 4) != 0)
         ) {
        FUN_022d0eac(DAT_022d0ea8);
        return;
      }
      puVar7 = auStack_228;
      FUN_022d08d4(puVar7);
      if (*(short *)(puVar7 + 4) != 0) {
        FUN_022d0eac(DAT_022d0ea0);
        return;
      }
      *psVar10 = 2;
      goto LAB_022d0e74;
    }
  }
  else {
    if (uVar2 < 0x31) {
      if (uVar2 != 0x30) {
LAB_022d0e64:
        FUN_022d0eac(0x308,0);
        return;
      }
    }
    else if (uVar2 != 0x40) goto LAB_022d0e64;
    if ((ushort)(sVar1 - 2U) < 2) {
      func_0x037cb8b4(psVar10 + 0xc5,auStack_22e,6);
      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
        iVar6 = FUN_022d0008(auStack_228,auStack_22e,3);
        sVar1 = *(short *)(iVar6 + 4);
        if (sVar1 == 0) {
          *psVar10 = 3;
          break;
        }
        if (sVar1 != 7 && sVar1 != 0xc) break;
      }
    }
    else if (sVar1 == 1) {
      func_0x037cb820(auStack_234,0xff,6);
      iVar5 = FUN_022d0008(auStack_228,auStack_234,3);
      if (*(short *)(iVar5 + 4) == 0) {
        *psVar10 = 3;
      }
    }
LAB_022d0d60:
    iVar5 = FUN_022cfda4(auStack_228,1);
    if (*(short *)(iVar5 + 4) != 0) {
      FUN_022d0eac(0);
      return;
    }
LAB_022d0d84:
    puVar7 = auStack_228;
    FUN_022d08d4(puVar7);
    if (*(short *)(puVar7 + 4) != 0) {
      FUN_022d0eac(DAT_022d0ea0);
      return;
    }
  }
  if (psVar10[0xf7] == 0) {
    iVar5 = FUN_022d05c0(auStack_228,1);
    if (*(short *)(iVar5 + 4) != 0) {
      FUN_022d0eac(DAT_022d0ea4);
      return;
    }
    psVar10[0xf7] = 1;
  }
  *psVar10 = 2;
  psVar10[0xcc] = 0;
  psVar10[0xcd] = 0;
  FUN_022ce784();
LAB_022d0e74:
  puVar8 = (undefined2 *)func_0x037d14bc();
  *puVar8 = 1;
  puVar8[1] = 0;
  func_0x037d1464();
  return;
}

