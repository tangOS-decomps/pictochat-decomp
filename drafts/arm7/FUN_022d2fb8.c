// decomp: module=arm7 addr=0x022d2fb8 name=FUN_022d2fb8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x13c (Ghidra's cache says 0x134 - it excludes this function's trailing literal pool), arm
// triage: noise=16 statements=74
// verify:  python tools/match.py --c <file> --func FUN_022d2fb8 --addr 0x022d2fb8 --size 0x13c --module arm7 --version 2.0/sp1


void FUN_022d2fb8(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  
  uVar6 = *(uint *)(param_1 + 0x10);
  iVar13 = *(int *)(DAT_022d30ec + 0x550);
  uVar8 = *(uint *)(param_1 + 8);
  uVar1 = *(ushort *)(iVar13 + 0x182);
  uVar14 = *(undefined4 *)(param_1 + 4);
  uVar9 = *(uint *)(param_1 + 0xc);
  uVar10 = *(undefined4 *)(param_1 + 0x18);
  uVar11 = *(undefined4 *)(param_1 + 0x1c);
  if (*(short *)(iVar13 + 0x188) != 0) {
    uVar9 = 1;
  }
  if (*(int *)(iVar13 + 0xc) == 0) {
    iVar12 = 3;
  }
  else if ((uVar9 & uVar1) == 0) {
    iVar12 = 0;
  }
  else {
    iVar12 = FUN_022d540c((uint)uVar1,*(uint *)(param_1 + 0x14) & 0xffff,uVar6 & 0xffff,uVar9,uVar14
                          ,uVar8 & 0xffff,uVar10,uVar11);
  }
  if (iVar12 != 2) {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 0x81;
    puVar3[1] = (short)iVar12;
    puVar3[4] = 0x14;
    uVar4 = (ushort)uVar6;
    puVar3[5] = uVar4;
    if (iVar12 == 10) {
      uVar4 = (ushort)uVar9 & uVar1;
    }
    puVar3[6] = (ushort)uVar9;
    if (iVar12 != 10) {
      uVar4 = 0;
    }
    puVar3[7] = uVar4;
    puVar3[8] = 0;
    puVar3[0xc] = (short)uVar8;
    *(undefined4 *)(puVar3 + 10) = uVar14;
    *(undefined4 *)(puVar3 + 0xe) = uVar10;
    uVar10 = DAT_022d30f0;
    *(undefined4 *)(puVar3 + 0x10) = uVar11;
    puVar3[0xd] = (short)uVar10;
    uVar2 = *(undefined2 *)(iVar13 + 0x30);
    uVar7 = *(undefined2 *)(iVar13 + 0x32);
    uVar5 = uVar2;
    if (*(short *)(iVar13 + 0x188) != 0) {
      uVar5 = uVar7;
    }
    puVar3[0x12] = uVar5;
    if (*(short *)(iVar13 + 0x188) != 0) {
      uVar7 = uVar2;
    }
    puVar3[0x13] = uVar7;
    func_0x037d1464();
  }
  return;
}

