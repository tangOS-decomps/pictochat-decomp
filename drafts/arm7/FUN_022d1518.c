// decomp: module=arm7 addr=0x022d1518 name=FUN_022d1518
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x360 (Ghidra's cache says 0x350 - it excludes this function's trailing literal pool), arm
// triage: noise=22 statements=131
// verify:  python tools/match.py --c <file> --func FUN_022d1518 --addr 0x022d1518 --size 0x360 --module arm7 --version 2.0/sp1


void FUN_022d1518(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  short *psVar10;
  ushort local_250 [3];
  undefined1 local_24a;
  undefined1 auStack_249 [15];
  undefined1 auStack_23a [34];
  undefined1 auStack_218 [512];
  undefined4 local_18;
  
  psVar10 = *(short **)(DAT_022d1868 + 0x550);
  sVar1 = *psVar10;
  local_18 = param_4;
  if ((sVar1 == 2 || sVar1 == 3) || sVar1 == 5) {
    *(undefined4 *)(psVar10 + 0xc2) = *(undefined4 *)(param_1 + 4);
    uVar2 = *(ushort *)(param_1 + 2);
    psVar10[200] = uVar2;
    uVar5 = *(undefined2 *)(param_1 + 8);
    func_0x037cb8b4(param_1 + 10,local_250,6);
    if ((local_250[0] != DAT_022d186c) && ((local_250[0] & 1) != 0)) {
      local_250[0] = local_250[0] & 0xfffe;
    }
    if (uVar2 == 0) {
      puVar6 = (undefined2 *)func_0x037d14bc();
      *puVar6 = 10;
      puVar6[1] = 6;
      puVar6[4] = 4;
      func_0x037d1464();
    }
    else if (((uint)(ushort)psVar10[0xfa] & 1 << (uVar2 & 0xff)) == 0) {
      puVar6 = (undefined2 *)func_0x037d14bc();
      *puVar6 = 10;
      puVar6[1] = 6;
      puVar6[4] = 4;
      func_0x037d1464();
    }
    else {
      psVar10[0x73] = 2;
      iVar7 = FUN_022d0960((int)auStack_218);
      if (*(short *)(iVar7 + 4) == 0) {
        if (*(short *)(iVar7 + 6) == 0x10) {
          iVar7 = FUN_022ce3e8(10,auStack_218);
          if (iVar7 == 0) {
            return;
          }
          puVar8 = auStack_218;
          FUN_022d08ec(auStack_218);
          if (*(short *)(puVar8 + 4) != 0) {
            FUN_022d1dbc(DAT_022d1870);
            return;
          }
          *psVar10 = 3;
          iVar7 = FUN_022cfdf8(auStack_218,1,0,1);
          if (*(short *)(iVar7 + 4) != 0) {
            FUN_022d1dbc(1,*(short *)(iVar7 + 4),0);
            return;
          }
          psVar10[99] = 1;
        }
        uVar4 = DAT_022d186c;
        *psVar10 = 5;
        func_0x037cb774(uVar4,auStack_23a,0x20);
        local_24a = (undefined1)uVar2;
        func_0x037cb820(auStack_249,0,0xf);
        iVar7 = FUN_022cfe58(auStack_218,DAT_022d1874,local_250,0,auStack_23a,1,&local_24a,uVar5);
        if (*(short *)(iVar7 + 4) == 0) {
          puVar6 = (undefined2 *)func_0x037d14bc();
          if (*(short *)(iVar7 + 8) == 0) {
            *puVar6 = 10;
            puVar6[1] = 0;
            puVar6[4] = 4;
            puVar6[8] = uVar2;
            puVar6[9] = 0;
          }
          else {
            func_0x037cb774(0,*(int *)(psVar10 + 0xc2) + 0x40,0x80);
            func_0x037cb8b4(iVar7 + 10,*(undefined4 *)(psVar10 + 0xc2),
                            (uint)*(ushort *)(iVar7 + 10) << 1);
            *puVar6 = 10;
            puVar6[1] = 0;
            puVar6[4] = 5;
            puVar6[8] = *(undefined2 *)(iVar7 + 0x40);
            iVar9 = FUN_022d1878(*(ushort *)(iVar7 + 0xc) & 0xff);
            uVar5 = FUN_022ce5f0();
            puVar6[9] = uVar5;
            FUN_022d188c(iVar9);
            puVar6[10] = *(undefined2 *)(iVar7 + 0x14);
            func_0x037cb8b4(iVar7 + 0xe,puVar6 + 5,6);
            func_0x037cb78c(iVar7 + 0x16,puVar6 + 0xb,0x20);
            uVar3 = *(ushort *)(iVar7 + 0x46);
            puVar6[0x1b] = uVar3;
            if (uVar3 < 0x81) {
              func_0x037cb774(0,puVar6 + 0x1c,0x80);
              func_0x037cb78c(iVar7 + 0x4a,puVar6 + 0x1c,(ushort)puVar6[0x1b] + 1 & 0xfffffffe);
            }
            else {
              *puVar6 = 10;
              puVar6[1] = 0;
              puVar6[4] = 4;
              puVar6[8] = uVar2;
              puVar6[9] = 0;
            }
          }
          func_0x037d1464(puVar6);
        }
        else {
          FUN_022d1dbc(2,*(short *)(iVar7 + 4),0);
        }
      }
      else {
        FUN_022d1dbc(0x308,*(short *)(iVar7 + 4),0);
      }
    }
  }
  else {
    puVar6 = (undefined2 *)func_0x037d14bc();
    *puVar6 = 10;
    puVar6[1] = 3;
    puVar6[4] = 4;
    func_0x037d1464();
  }
  return;
}

