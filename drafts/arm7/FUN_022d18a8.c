// decomp: module=arm7 addr=0x022d18a8 name=FUN_022d18a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x514 (Ghidra's cache says 0x500 - it excludes this function's trailing literal pool), arm
// triage: noise=20 statements=213
// verify:  python tools/match.py --c <file> --func FUN_022d18a8 --addr 0x022d18a8 --size 0x514 --module arm7 --version 2.0/sp1


void FUN_022d18a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined1 *a0;
  int iVar9;
  uint uVar10;
  short sVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  short *psVar15;
  ushort *puVar16;
  uint uVar17;
  bool bVar18;
  ushort local_4d8 [3];
  undefined1 local_4d2 [16];
  undefined1 auStack_4c2 [32];
  undefined1 auStack_4a2 [34];
  undefined1 auStack_480 [1112];
  undefined4 local_28;
  
  psVar15 = *(short **)(DAT_022d1da8 + 0x550);
  sVar11 = *psVar15;
  local_28 = param_4;
  if ((sVar11 == 2 || sVar11 == 3) || sVar11 == 5) {
    *(undefined4 *)(psVar15 + 0xc2) = *(undefined4 *)(param_1 + 4);
    uVar2 = *(ushort *)(param_1 + 2);
    psVar15[200] = uVar2;
    uVar3 = *(undefined2 *)(param_1 + 10);
    func_0x037cb8b4(param_1 + 0xc,local_4d8,6);
    sVar11 = *(short *)(param_1 + 0x12);
    uVar4 = *(ushort *)(param_1 + 0x36);
    if (sVar11 == 2) {
      bVar18 = true;
      sVar11 = 0;
    }
    else if (sVar11 == 3) {
      bVar18 = true;
      sVar11 = 1;
    }
    else {
      bVar18 = false;
    }
    sVar5 = *(short *)(param_1 + 0x14);
    func_0x037cb8b4(param_1 + 0x16,auStack_4a2,0x20);
    uVar13 = (uint)*(ushort *)(param_1 + 8);
    if ((local_4d8[0] != DAT_022d1dac) && ((local_4d8[0] & 1) != 0)) {
      local_4d8[0] = local_4d8[0] & 0xfffe;
    }
    uVar17 = (uint)(ushort)psVar15[0xfa] & (uVar2 & 0x7fff) << 1;
    if ((((uVar17 == 0) || ((*(uint *)(psVar15 + 100) & 1) != 0 && sVar11 != 1)) ||
        (*(uint *)(param_1 + 4) == 0)) ||
       (((*(uint *)(param_1 + 4) & 3) != 0 || (*(ushort *)(param_1 + 8) < 0x40)))) {
      puVar7 = (undefined2 *)func_0x037d14bc();
      *puVar7 = 0x26;
      puVar7[1] = 6;
      puVar7[4] = 4;
      func_0x037d1464();
    }
    else {
      psVar15[0x73] = 2;
      iVar8 = FUN_022d0960((int)auStack_480);
      if (*(short *)(iVar8 + 4) == 0) {
        if (*(short *)(iVar8 + 6) == 0x10) {
          iVar8 = FUN_022ce3e8(0x26,auStack_480);
          if (iVar8 == 0) {
            return;
          }
          a0 = auStack_480;
          FUN_022d08ec(a0);
          if (*(short *)(a0 + 4) != 0) {
            FUN_022d1dbc(DAT_022d1db0,*(short *)(a0 + 4),1);
            return;
          }
          *psVar15 = 3;
          iVar8 = FUN_022cfdf8(auStack_480,1,0,1);
          if (*(short *)(iVar8 + 4) != 0) {
            FUN_022d1dbc(1,*(short *)(iVar8 + 4),1);
            return;
          }
          psVar15[99] = 1;
        }
        if (sVar11 == 0) {
          if (psVar15[0xf7] == 1) {
            iVar8 = FUN_022d05c0(auStack_480,0);
            if (*(short *)(iVar8 + 4) != 0) {
              FUN_022d1dbc(DAT_022d1db4,*(short *)(iVar8 + 4),1);
              return;
            }
            psVar15[0xf7] = 0;
          }
        }
        else if (psVar15[0xf7] == 0) {
          iVar8 = FUN_022d05c0(auStack_480,1);
          if (*(short *)(iVar8 + 4) != 0) {
            FUN_022d1dbc(DAT_022d1db4,*(short *)(iVar8 + 4),1);
            return;
          }
          psVar15[0xf7] = 1;
        }
        if (bVar18) {
          func_0x037cb820(auStack_4c2,0xff,0x20);
          if (uVar4 < 0x21) {
            func_0x037cb820(auStack_4c2,0,uVar4);
          }
          iVar8 = FUN_022d054c(auStack_480,auStack_4c2);
          if (*(short *)(iVar8 + 4) != 0) {
            FUN_022d1dbc(DAT_022d1db8,*(short *)(iVar8 + 4),1);
            return;
          }
        }
        uVar12 = 0;
        *psVar15 = 5;
        func_0x037cb820(local_4d2,0,0x10);
        uVar10 = 1;
        do {
          if ((uVar17 & 1 << (uVar10 & 0xff)) != 0) {
            local_4d2[uVar12] = (char)uVar10;
            uVar12 = uVar12 + 1 & 0xffff;
          }
          uVar10 = uVar10 + 1 & 0xffff;
        } while (uVar10 < 0xf);
        iVar8 = func_0x037c8a00(uVar13 - 0x40,0x42);
        iVar8 = FUN_022cfe58(auStack_480,uVar13 + iVar8 * -2 + 0x5e,local_4d8,sVar5,auStack_4a2,
                             sVar11,local_4d2,uVar3);
        if (*(short *)(iVar8 + 4) == 0) {
          puVar7 = (undefined2 *)func_0x037d14bc();
          uVar3 = (undefined2)((int)uVar17 >> 1);
          if (*(short *)(iVar8 + 8) == 0) {
            *puVar7 = 0x26;
            puVar7[1] = 0;
            puVar7[4] = 4;
            puVar7[7] = 0;
            puVar7[5] = uVar3;
          }
          else {
            uVar17 = *(uint *)(psVar15 + 0xc2);
            puVar16 = (ushort *)(iVar8 + 10);
            func_0x037cb774(0,uVar17,uVar13);
            for (iVar14 = 0; iVar14 < (int)(uint)*(ushort *)(iVar8 + 8); iVar14 = iVar14 + 1) {
              uVar2 = *puVar16;
              iVar1 = (uVar2 & 0x7fff) * 2;
              func_0x037cb8b4(puVar16,uVar17,iVar1);
              if (sVar5 != 0) {
                uVar13 = (uint)*(ushort *)(uVar17 + 10);
                if (uVar13 == 0) {
                  bVar18 = false;
                }
                else if (uVar13 < 0x21) {
                  for (iVar9 = 0; iVar9 < (int)uVar13; iVar9 = iVar9 + 1) {
                    if (*(char *)(uVar17 + iVar9 + 0xc) != '\0') {
                      bVar18 = true;
                      goto LAB_022d1cfc;
                    }
                  }
                  bVar18 = false;
                }
                else {
                  bVar18 = false;
                }
LAB_022d1cfc:
                if (!bVar18) {
                  *(short *)(uVar17 + 10) = sVar5;
                  func_0x037cb8b4(auStack_4a2,uVar17 + 0xc,0x20);
                }
              }
              *(uint *)(puVar7 + iVar14 * 2 + 8) = uVar17;
              iVar9 = FUN_022d1878(puVar16[1] & 0xff);
              uVar6 = FUN_022ce5f0();
              puVar7[iVar14 + 0x28] = uVar6;
              uVar13 = FUN_022d188c(iVar9);
              uVar17 = uVar17 + iVar1;
              bVar18 = (uVar17 & 2) != 0;
              if (bVar18) {
                uVar13 = uVar17 + 2;
              }
              puVar16 = puVar16 + (uVar2 & 0x7fff);
              if (bVar18) {
                uVar17 = uVar13 & 0xfffffffc;
              }
            }
            *puVar7 = 0x26;
            puVar7[1] = 0;
            puVar7[4] = 5;
            puVar7[7] = *(undefined2 *)(iVar8 + 8);
            puVar7[5] = uVar3;
          }
          func_0x037d1464(puVar7);
        }
        else {
          FUN_022d1dbc(2,*(short *)(iVar8 + 4),1);
        }
      }
      else {
        FUN_022d1dbc(0x308,*(short *)(iVar8 + 4),1);
      }
    }
  }
  else {
    puVar7 = (undefined2 *)func_0x037d14bc();
    *puVar7 = 0x26;
    puVar7[1] = 3;
    puVar7[4] = 4;
    func_0x037d1464();
  }
  return;
}

