// decomp: module=arm7 addr=0x022d540c name=FUN_022d540c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x134 (Ghidra's cache says 0x12c - it excludes this function's trailing literal pool), arm
// triage: noise=15 statements=73
// verify:  python tools/match.py --c <file> --func FUN_022d540c --addr 0x022d540c --size 0x134 --module arm7 --version 2.0/sp1


undefined4
FUN_022d540c(ushort param_1,int param_2,ushort param_3,ushort param_4,undefined4 param_5,
            ushort param_6,undefined4 param_7,undefined4 param_8)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  
  iVar8 = *(int *)(DAT_022d5538 + 0x550);
  puVar10 = (ushort *)(iVar8 + 0x70c + param_2 * 4);
  iVar9 = iVar8 + 0x2f8;
  if (param_6 == 0) {
    uVar4 = 6;
  }
  else {
    if ((param_3 & 8) == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = 2;
    }
    if ((uint)param_6 + iVar6 < 0x205) {
      func_0x037ca044(iVar8 + 0x71c);
      uVar3 = DAT_022d553c;
      uVar1 = *(ushort *)(iVar8 + 0x6f8);
      uVar7 = (uint)uVar1;
      if (uVar7 == DAT_022d553c) {
        func_0x037ca0c8(iVar8 + 0x71c);
        uVar4 = 10;
      }
      else {
        puVar5 = (undefined2 *)(iVar9 + uVar7 * 0x20);
        *(undefined2 *)(iVar8 + 0x6f8) = *(undefined2 *)(iVar9 + uVar7 * 0x20);
        if (*(ushort *)(iVar8 + 0x6fa) == uVar7) {
          *(short *)(iVar8 + 0x6fa) = (short)uVar3;
        }
        puVar5[1] = param_3;
        puVar5[2] = param_4;
        puVar5[3] = param_4 & param_1;
        puVar5[4] = 0;
        puVar5[5] = 0;
        *(undefined4 *)(puVar5 + 10) = param_5;
        puVar5[7] = param_6;
        *(undefined4 *)(puVar5 + 0xc) = param_7;
        *(undefined4 *)(puVar5 + 0xe) = param_8;
        uVar3 = DAT_022d553c;
        uVar2 = (undefined2)DAT_022d553c;
        *puVar5 = uVar2;
        puVar5[8] = uVar2;
        puVar5[9] = *(undefined2 *)(iVar8 + 0x7ca);
        if (puVar10[1] == uVar3) {
          *puVar10 = uVar1;
        }
        else {
          *(ushort *)(iVar9 + (uint)puVar10[1] * 0x20) = uVar1;
        }
        puVar10[1] = uVar1;
        func_0x037ca0c8(iVar8 + 0x71c);
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 6;
    }
  }
  return uVar4;
}

