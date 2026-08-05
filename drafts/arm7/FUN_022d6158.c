// decomp: module=arm7 addr=0x022d6158 name=FUN_022d6158
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x210 (Ghidra's cache says 0x1e8 - it excludes this function's trailing literal pool), arm
// triage: noise=33 statements=91
// verify:  python tools/match.py --c <file> --func FUN_022d6158 --addr 0x022d6158 --size 0x210 --module arm7 --version 2.0/sp1


undefined4
FUN_022d6158(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 auStack_218 [512];
  undefined4 local_18;
  
  puVar6 = auStack_218;
  puVar7 = auStack_218;
  puVar8 = auStack_218;
  puVar9 = auStack_218;
  iVar10 = *(int *)(DAT_022d6340 + 0x550);
  local_18 = param_4;
  iVar4 = FUN_022d0904((int)auStack_218);
  if (*(short *)(iVar4 + 4) == 0) {
    FUN_022d08d4(auStack_218);
    puVar2 = DAT_022d6348;
    if (*(short *)(puVar6 + 4) == 0) {
      *DAT_022d6348 = 200;
      puVar2[2] = 2000;
      puVar2[0x16] = (short)DAT_022d634c;
      FUN_022d0890(auStack_218);
      if (*(short *)(puVar7 + 4) == 0) {
        uVar1 = *(ushort *)(puVar7 + 6);
        *(ushort *)(iVar10 + 500) = uVar1;
        uVar3 = func_0x037d1510(uVar1 >> 1);
        *(undefined2 *)(iVar10 + 0x1f6) = uVar3;
        FUN_022d061c(auStack_218,DAT_022d6354,0x28,5);
        *(undefined4 *)(iVar10 + 0x7b8) = DAT_022d6358;
        *(undefined4 *)(iVar10 + 0x7bc) = 0;
        *(undefined2 *)(iVar10 + 0x1ec) = 2;
        *(undefined2 *)(iVar10 + 0x1ee) = 1;
        FUN_022d0930(auStack_218);
        if (*(short *)(puVar8 + 4) == 0) {
          func_0x037cb78c(puVar8 + 6,iVar10 + 0x20,8);
          *(undefined2 *)(iVar10 + 0x28) = *(undefined2 *)(puVar8 + 0xe);
          *(undefined2 *)(iVar10 + 0x2c) = *(undefined2 *)(puVar8 + 0x10);
          *(undefined2 *)(iVar10 + 0x2e) = *(undefined2 *)(puVar8 + 0x12);
          *(undefined2 *)(iVar10 + 0x2a) = *(undefined2 *)(puVar8 + 0x14);
          FUN_022d0878(auStack_218);
          if (*(short *)(puVar9 + 4) == 0) {
            func_0x037cb8b4(puVar9 + 6,iVar10 + 0xe0,6);
            iVar4 = FUN_022d06e0(auStack_218,1);
            if (*(short *)(iVar4 + 4) == 0) {
              uVar5 = 1;
            }
            else {
              *param_1 = (short)DAT_022d6364;
              uVar5 = 0;
              *param_2 = *(undefined2 *)(iVar4 + 4);
            }
          }
          else {
            *param_1 = (short)DAT_022d6360;
            uVar5 = 0;
            *param_2 = *(undefined2 *)(puVar9 + 4);
          }
        }
        else {
          uVar5 = 0;
          *param_1 = (short)DAT_022d635c;
          *param_2 = *(undefined2 *)(puVar8 + 4);
        }
      }
      else {
        *param_1 = (short)DAT_022d6350;
        uVar5 = 0;
        *param_2 = *(undefined2 *)(puVar7 + 4);
      }
    }
    else {
      *param_1 = (short)DAT_022d6344;
      uVar5 = 0;
      *param_2 = *(undefined2 *)(puVar6 + 4);
    }
  }
  else {
    *param_1 = 0x304;
    uVar5 = 0;
    *param_2 = *(undefined2 *)(iVar4 + 4);
  }
  return uVar5;
}

