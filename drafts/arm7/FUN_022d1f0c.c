// decomp: module=arm7 addr=0x022d1f0c name=FUN_022d1f0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5ac (Ghidra's cache says 0x598 - it excludes this function's trailing literal pool), arm
// triage: noise=35 statements=260
// verify:  python tools/match.py --c <file> --func FUN_022d1f0c --addr 0x022d1f0c --size 0x5ac --module arm7 --version 2.0/sp1


void FUN_022d1f0c(int param_1)

{
  short sVar1;
  ushort uVar2;
  undefined2 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_r1;
  undefined1 *puVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined1 auStack_268 [6];
  undefined1 auStack_262 [6];
  undefined1 auStack_25c [10];
  undefined2 local_252;
  undefined2 local_250;
  undefined2 local_24e;
  undefined2 local_24c;
  undefined2 local_24a;
  undefined1 auStack_248 [48];
  undefined1 auStack_218 [512];
  
  psVar10 = *(short **)(DAT_022d24a4 + 0x550);
  iVar9 = *(int *)(DAT_022d24a4 + 0x54c);
  if ((*psVar10 == 2) && ((*(uint *)(psVar10 + 100) & 1) == 0)) {
    func_0x037cb8b4(*(undefined4 *)(param_1 + 4),iVar9 + 0x10,0xc0);
    if ((*(ushort *)(iVar9 + 0x4c) < 0x10) || ((*(byte *)(iVar9 + 0x5b) & 1) != 0)) {
      uVar8 = 1 << (*(ushort *)(iVar9 + 0x46) & 0xff);
      if (((uVar8 & (ushort)psVar10[0xfa]) == 0) || (((int)uVar8 >> 1 & 0x1fffU) == 0)) {
        puVar3 = (undefined2 *)func_0x037d14bc();
        *puVar3 = 0xc;
        puVar3[1] = 6;
        puVar3[4] = 6;
        func_0x037d1464();
      }
      else {
        puVar3 = (undefined2 *)func_0x037d14bc();
        *puVar3 = 0xc;
        puVar3[1] = 0;
        puVar3[4] = 6;
        func_0x037d1464();
        if (psVar10[0xf6] == 1) {
          bVar11 = (*(ushort *)(iVar9 + 0x3e) & 1) == 0;
          if (bVar11) {
            sVar1 = 2;
          }
          else {
            sVar1 = 1;
            psVar10[0xf6] = 1;
          }
        }
        else {
          bVar11 = (*(ushort *)(iVar9 + 0x3e) & 2) == 0;
          if (bVar11) {
            sVar1 = 1;
          }
          else {
            sVar1 = 2;
            psVar10[0xf6] = 2;
          }
        }
        if (bVar11) {
          psVar10[0xf6] = sVar1;
        }
        psVar10[0xf7] = (ushort)((*(ushort *)(iVar9 + 0x3c) & 0x20) != 0);
        if (*(short *)(iVar9 + 0x4c) == 0) {
          sVar1 = 3;
        }
        else {
          sVar1 = 2;
        }
        psVar10[0x73] = sVar1;
        iVar4 = FUN_022ce3e8(0xc,auStack_218);
        if (iVar4 != 0) {
          iVar4 = FUN_022d073c(auStack_218,0);
          if (*(short *)(iVar4 + 4) == 0) {
            if (*(ushort *)(iVar9 + 0x4c) < 0x10) {
              if (*(short *)(iVar9 + 0x42) == 0) {
                uVar2 = 1;
              }
              else {
                sVar1 = func_0x037c87f4(DAT_022d24ac);
                uVar2 = sVar1 + 1;
              }
              if (0xff < uVar2) {
                uVar2 = 0xff;
              }
              iVar4 = FUN_022d04f0(auStack_218,uVar2);
              if (*(short *)(iVar4 + 4) != 0) {
                FUN_022d24b8(DAT_022d24b0,*(short *)(iVar4 + 4),0);
                return;
              }
            }
            puVar7 = auStack_218;
            FUN_022d08ec(auStack_218);
            if (*(short *)(puVar7 + 4) == 0) {
              *psVar10 = 3;
              bVar11 = *(int *)(param_1 + 0x20) != 0;
              iVar4 = FUN_022cfdf8(auStack_218,bVar11,0,1);
              if (*(short *)(iVar4 + 4) == 0) {
                psVar10[99] = (ushort)bVar11;
                func_0x037cb8b4(iVar9 + 0x10,auStack_25c,0x40);
                if (psVar10[0x73] == 2) {
                  local_252 = 0x20;
                  local_250 = (undefined2)*(undefined4 *)(iVar9 + 0x54);
                  local_24e = (undefined2)((uint)*(undefined4 *)(iVar9 + 0x54) >> 0x10);
                  local_24c = *(undefined2 *)(iVar9 + 0x58);
                  local_24a = 0;
                  func_0x037cb8b4(param_1 + 8,auStack_248,0x18);
                }
                puVar7 = auStack_25c;
                iVar4 = FUN_022cff10(auStack_218,2000);
                sVar1 = *(short *)(iVar4 + 4);
                if (sVar1 == 0) {
                  puVar7 = (undefined1 *)(uint)*(ushort *)(iVar4 + 6);
                }
                if (sVar1 == 0 && puVar7 == (undefined1 *)0x0) {
                  func_0x037cb8b4(iVar4 + 8,psVar10 + 0xc5,6);
                  func_0x037cb8b4(psVar10 + 0xc5,auStack_262,6);
                  uVar8 = (uint)*(ushort *)(param_1 + 0x26);
                  iVar4 = FUN_022cff88(auStack_218,auStack_262,uVar8,2000);
                  sVar1 = *(short *)(iVar4 + 4);
                  if (sVar1 == 0xc) {
                    uVar8 = (uint)*(ushort *)(iVar4 + 6);
                  }
                  if (sVar1 != 0xc || uVar8 != 0x13) {
                    if (sVar1 == 0) {
                      uVar8 = (uint)*(ushort *)(iVar4 + 6);
                    }
                    if (sVar1 == 0 && uVar8 == 0) {
                      func_0x037cb8b4(psVar10 + 0xc5,auStack_268,6);
                      iVar4 = FUN_022d0080(auStack_218,auStack_268,1,2000);
                      uVar12 = func_0x037cb520();
                      uVar8 = (uint)((ulonglong)uVar12 >> 0x20);
                      uVar5 = (uint)uVar12;
                      sVar1 = *(short *)(iVar4 + 4);
                      if (sVar1 == 0xc) {
                        uVar8 = (uint)*(ushort *)(iVar4 + 6);
                      }
                      if (sVar1 != 0xc || uVar8 != 0x13) {
                        uVar8 = uVar5;
                        if (sVar1 == 0) {
                          uVar8 = (uint)*(ushort *)(iVar4 + 6);
                        }
                        if (sVar1 == 0 && uVar8 == 0) {
                          psVar10[0xc4] = *(short *)(iVar4 + 8);
                          psVar10[0x5d] = *(short *)(iVar9 + 0x58);
                          func_0x037cb774(1,psVar10 + 0xfc,0x10);
                          iVar4 = (int)(*(ushort *)(iVar9 + 0x12) & 0xff) >> 2;
                          if ((*(ushort *)(iVar9 + 0x12) & 2) == 0) {
                            iVar4 = iVar4 + 0x19;
                          }
                          sVar1 = FUN_022ce5f0(iVar4);
                          psVar10[0x5e] = sVar1;
                          FUN_022ce57c(iVar4);
                          uVar6 = func_0x037cb520();
                          psVar10[0xc1] = 1;
                          psVar10[0x43] = 1;
                          iVar4 = *(int *)(psVar10 + 0x3de);
                          if (iVar4 != 0 || *(int *)(psVar10 + 0x3dc) != 0) {
                            uVar12 = func_0x037caa3c();
                            iVar4 = (int)((ulonglong)uVar12 >> 0x20);
                            *(uint *)(psVar10 + 0x39c) = (uint)uVar12 | 1;
                            *(int *)(psVar10 + 0x39e) = iVar4;
                          }
                          *psVar10 = 8;
                          bVar11 = (*(byte *)(iVar9 + 0x5b) & 4) != 0;
                          if (bVar11) {
                            iVar4 = 0x2a;
                          }
                          if (!bVar11) {
                            iVar4 = 0;
                          }
                          FUN_022ce7b8((uint)*(ushort *)(iVar9 + 0x5c) + iVar4 & 0xffff);
                          bVar11 = (*(byte *)(iVar9 + 0x5b) & 4) != 0;
                          iVar4 = extraout_r1;
                          if (bVar11) {
                            iVar4 = 6;
                          }
                          if (!bVar11) {
                            iVar4 = 0;
                          }
                          FUN_022ce808((uint)*(ushort *)(iVar9 + 0x5e) + iVar4 & 0xffff);
                          func_0x037cb534(uVar6);
                          psVar10[0x61] = 1;
                          puVar3 = (undefined2 *)func_0x037d14bc();
                          *puVar3 = 0xc;
                          puVar3[1] = 0;
                          puVar3[4] = 7;
                          puVar3[5] = psVar10[0xc4];
                          func_0x037cb8b4(psVar10 + 0xc5,puVar3 + 8,6);
                          puVar3[0xb] = psVar10[0x18];
                          puVar3[0xc] = psVar10[0x19];
                          func_0x037d1464(puVar3);
                          func_0x037cb534(uVar5);
                        }
                        else {
                          func_0x037cb534(uVar5);
                          FUN_022d24b8(6,*(undefined2 *)(iVar4 + 4),*(undefined2 *)(iVar4 + 6));
                        }
                      }
                      else {
                        func_0x037cb534();
                        puVar3 = (undefined2 *)func_0x037d14bc();
                        *puVar3 = 0xc;
                        puVar3[1] = 0xc;
                        puVar3[4] = 6;
                        func_0x037d1464();
                      }
                    }
                    else {
                      FUN_022d24b8(4,sVar1,*(undefined2 *)(iVar4 + 6));
                    }
                  }
                  else {
                    puVar3 = (undefined2 *)func_0x037d14bc();
                    *puVar3 = 0xc;
                    puVar3[1] = 0xc;
                    puVar3[4] = 6;
                    func_0x037d1464();
                  }
                }
                else {
                  FUN_022d24b8(3,sVar1,*(undefined2 *)(iVar4 + 6));
                }
              }
              else {
                FUN_022d24b8(1,*(short *)(iVar4 + 4),0);
              }
            }
            else {
              FUN_022d24b8(DAT_022d24b4);
            }
          }
          else {
            FUN_022d24b8(DAT_022d24a8,*(short *)(iVar4 + 4),0);
          }
        }
      }
    }
    else {
      puVar3 = (undefined2 *)func_0x037d14bc();
      *puVar3 = 0xc;
      puVar3[1] = 0xb;
      puVar3[4] = 6;
      func_0x037d1464();
    }
  }
  else {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0xc;
    puVar3[1] = 3;
    puVar3[4] = 6;
    func_0x037d1464();
  }
  return;
}

