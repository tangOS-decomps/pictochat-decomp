// decomp: module=arm7 addr=0x022d254c name=FUN_022d254c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58c (Ghidra's cache says 0x584 - it excludes this function's trailing literal pool), arm
// triage: noise=21 statements=229
// verify:  python tools/match.py --c <file> --func FUN_022d254c --addr 0x022d254c --size 0x58c --module arm7 --version 2.0/sp1


undefined4 FUN_022d254c(int param_1,int param_2,undefined2 *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  ushort uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined1 *a0;
  undefined2 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  undefined2 uVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStack_234 [6];
  undefined1 auStack_22e [6];
  undefined1 auStack_228 [512];
  undefined4 local_28;
  
  if (param_2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (undefined2)*(undefined4 *)(param_1 + 8);
  }
  uVar13 = 0;
  psVar10 = *(short **)(DAT_022d2ad0 + 0x550);
  uVar1 = *(uint *)(param_1 + 4) & 0xffff;
  sVar3 = *psVar10;
  bVar14 = false;
  local_28 = param_4;
  if (sVar3 == 9 || sVar3 == 7) {
    bVar14 = *(int *)(psVar10 + 6) == 1;
  }
  else {
    uVar12 = (undefined2)*(uint *)(param_1 + 4);
    if (sVar3 != 10 && sVar3 != 8) {
      if (param_2 == 0) {
        puVar7 = (undefined2 *)func_0x037d14bc();
        *puVar7 = 0xd;
        puVar7[1] = 3;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = uVar12;
        puVar7[5] = 0;
        func_0x037d1464();
      }
      return 0;
    }
    uVar8 = func_0x037cb520();
    if (psVar10[0xc1] == 0) {
      func_0x037cb534();
      if (param_2 == 0) {
        puVar7 = (undefined2 *)func_0x037d14bc();
        *puVar7 = 0xd;
        puVar7[1] = 3;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = uVar12;
        puVar7[5] = 0;
        func_0x037d1464();
      }
      return 0;
    }
    if (*(int *)(psVar10 + 6) == 1) {
      psVar10[6] = 0;
      psVar10[7] = 0;
      bVar14 = true;
      FUN_022d3bd4();
      FUN_022ce658();
      if (*psVar10 == 10) {
        *psVar10 = 8;
      }
    }
    psVar10[0xc1] = 0;
    psVar10[0x43] = 0;
    psVar10[10] = 0;
    psVar10[0xb] = 0;
    psVar10[8] = 0;
    psVar10[9] = 0;
    psVar10[0xe] = 0;
    psVar10[0xf] = 0;
    func_0x037cb534(uVar8);
  }
  if (*psVar10 == 10 || *psVar10 == 8) {
    func_0x037cb8b4(psVar10 + 0xc5,auStack_22e,6);
    for (iVar11 = 0; iVar11 < 2; iVar11 = iVar11 + 1) {
      iVar6 = FUN_022d0008(auStack_228,auStack_22e,3);
      uVar4 = *(ushort *)(iVar6 + 4);
      if (uVar4 < 8) {
        if (uVar4 < 7) {
          if ((1 < uVar4) || (1 < uVar4)) {
LAB_022d2724:
            if (param_2 == 0) {
              FUN_022d2b9c(5,uVar4,uVar1,0);
            }
            else {
              FUN_022d2be0();
            }
            if (bVar14) {
              FUN_022d5870(1);
            }
            return 0;
          }
          break;
        }
      }
      else if (uVar4 != 0xc) goto LAB_022d2724;
    }
    psVar10[0x61] = 0;
    uVar12 = 1;
    *psVar10 = 3;
    iVar11 = FUN_022cfda4(auStack_228,1);
    if (*(short *)(iVar11 + 4) != 0) {
      if (param_2 == 0) {
        FUN_022d2b9c(0,*(short *)(iVar11 + 4),uVar1,1);
      }
      else {
        FUN_022d2be0();
      }
      if (bVar14) {
        FUN_022d5870(1);
      }
      return 0;
    }
    a0 = auStack_228;
    FUN_022d08d4(a0);
    if (*(short *)(a0 + 4) != 0) {
      if (param_2 == 0) {
        FUN_022d2b9c(DAT_022d2ad4,*(short *)(a0 + 4),uVar1,1);
      }
      else {
        FUN_022d2be0();
      }
      if (bVar14) {
        FUN_022d5870(1);
      }
      return 0;
    }
    *psVar10 = 2;
    psVar10[0xcc] = 0;
    psVar10[0xcd] = 0;
    psVar10[0xcb] = 0;
    func_0x037cb820(psVar10 + 0xce,0,0x50);
    FUN_022ce784();
    if (param_2 == 1) {
      puVar7 = (undefined2 *)func_0x037d14bc();
      *puVar7 = 0xc;
      puVar7[1] = 0;
      puVar7[4] = 9;
      puVar7[6] = uVar5;
      puVar7[5] = psVar10[0xc4];
      func_0x037cb8b4(auStack_22e,puVar7 + 8,6);
      puVar7[0xb] = psVar10[0x18];
      puVar7[0xc] = psVar10[0x19];
      func_0x037d1464(puVar7);
    }
    else {
      FUN_022d2ad8(0,0,auStack_22e);
    }
    if (bVar14) {
      FUN_022d5870(1);
    }
  }
  else {
    for (uVar9 = 1; uVar12 = (undefined2)uVar13, (int)uVar9 < 0x10; uVar9 = uVar9 + 1) {
      uVar2 = 1 << (uVar9 & 0xff);
      if ((uVar2 & (ushort)psVar10[0xc1] & uVar1) != 0) {
        func_0x037cb8b4(psVar10 + (uVar9 - 1) * 3 + 0x94,auStack_234);
        for (iVar11 = 0; iVar11 < 2; iVar11 = iVar11 + 1) {
          iVar6 = FUN_022d0008(auStack_228,auStack_234,3);
          sVar3 = *(short *)(iVar6 + 4);
          if (sVar3 == 0) break;
          if (sVar3 != 7 && sVar3 != 0xc) {
            if (param_2 == 0) {
              FUN_022d2b9c(5,sVar3,uVar1,uVar13);
            }
            else {
              FUN_022d2be0();
            }
            if (bVar14) {
              FUN_022d5870(1);
            }
            return 0;
          }
        }
        uVar8 = func_0x037cb520();
        if (((ushort)psVar10[0xc1] & uVar2) == 0) {
          func_0x037cb534();
        }
        else {
          uVar13 = uVar13 | 1 << (uVar9 & 0xff) & 0xffffU;
          psVar10[0xc1] = psVar10[0xc1] & ~(ushort)uVar2;
          psVar10[0x43] = psVar10[0x43] & ~(ushort)uVar2;
          (psVar10 + (uVar9 & 0xffff) * 4 + 0x39c)[0] = 0;
          (psVar10 + (uVar9 & 0xffff) * 4 + 0x39c)[1] = 0;
          (psVar10 + (uVar9 & 0xffff) * 4 + 0x39e)[0] = 0;
          (psVar10 + (uVar9 & 0xffff) * 4 + 0x39e)[1] = 0;
          func_0x037cb820(psVar10 + (uVar9 - 1) * 3 + 0x94,0,6);
          func_0x037cb534(uVar8);
          if (param_2 == 1) {
            puVar7 = (undefined2 *)func_0x037d14bc();
            *puVar7 = 8;
            puVar7[1] = 0;
            puVar7[4] = 9;
            puVar7[9] = uVar5;
            puVar7[8] = (short)uVar9;
            func_0x037cb8b4(auStack_234,puVar7 + 5,6);
            puVar7[0x16] = psVar10[0x18];
            puVar7[0x17] = psVar10[0x19];
            func_0x037d1464(puVar7);
          }
          else {
            FUN_022d2ad8(1,uVar9 & 0xffff,auStack_234);
          }
          if (bVar14) {
            FUN_022d5870(uVar2 & 0xffff);
          }
        }
      }
    }
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = uVar12;
  }
  return 1;
}

