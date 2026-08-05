// decomp: module=arm7 addr=0x022d6470 name=FUN_022d6470
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30c (Ghidra's cache says 0x2f8 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=143
// verify:  python tools/match.py --c <file> --func FUN_022d6470 --addr 0x022d6470 --size 0x30c --module arm7 --version 2.0/sp1


undefined4 FUN_022d6470(uint *param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  short *psVar7;
  
  psVar7 = *(short **)(DAT_022d6768 + 0x550);
  uVar6 = *param_1;
  uVar5 = 0;
  if (((ushort)(*psVar7 - 9U) < 2) && ((uVar6 & 0x2c00) != 0)) {
    uVar6 = uVar6 & 0xffffd3ff;
    uVar5 = 3;
  }
  uVar2 = func_0x037cb520();
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = DAT_022d676c;
    *(short *)(param_2 + 1) = psVar7[0x2c];
    *(short *)((int)param_2 + 6) = psVar7[0x2d];
    *(short *)(param_2 + 2) = psVar7[0x2e];
    *(short *)((int)param_2 + 10) = psVar7[0x18];
    *(short *)(param_2 + 3) = psVar7[0x19];
    *(short *)((int)param_2 + 0xe) = psVar7[0x22];
    *(short *)(param_2 + 4) = psVar7[0x23];
    *(short *)((int)param_2 + 0x12) = psVar7[0x20];
    *(short *)(param_2 + 5) = psVar7[0x21];
    *(short *)((int)param_2 + 0x16) = psVar7[0x4c];
    *(char *)(param_2 + 6) = (char)psVar7[0x49];
    *(char *)((int)param_2 + 0x19) = (char)psVar7[0x4a];
    *(char *)((int)param_2 + 0x1a) = (char)psVar7[0x4d];
    *(char *)((int)param_2 + 0x1b) = (char)psVar7[0x4e];
  }
  if ((uVar6 & 1) != 0) {
    sVar3 = (short)param_1[1];
    if (sVar3 == 0) {
      sVar3 = 0x10;
    }
    psVar7[0x2c] = sVar3;
    psVar7[0x3e0] = sVar3;
  }
  if ((uVar6 & 2) != 0) {
    uVar4 = (uint)*(ushort *)((int)param_1 + 6);
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    sVar3 = (short)uVar4;
    psVar7[0x2d] = sVar3;
    psVar7[0x3e1] = sVar3;
    if ((int)uVar4 < (int)psVar7[0x31]) {
      psVar7[0x31] = sVar3;
    }
  }
  if ((uVar6 & 4) != 0) {
    uVar4 = (uint)(ushort)param_1[2];
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    sVar3 = (short)uVar4;
    psVar7[0x2e] = sVar3;
    psVar7[0x3e2] = sVar3;
    if ((int)uVar4 < (int)psVar7[0x31]) {
      psVar7[0x31] = sVar3;
    }
  }
  if ((uVar6 & 8) != 0) {
    if ((ushort)psVar7[0x1a] < (*(short *)((int)param_1 + 10) + 1U & 0xfffe)) {
      uVar5 = 6;
    }
    else {
      FUN_022ce858();
    }
  }
  if ((uVar6 & 0x10) != 0) {
    if (((ushort)param_1[3] + 1 & 0xfffe) < 0x201) {
      FUN_022ce884((uint)(ushort)param_1[3]);
    }
    else {
      uVar5 = 6;
    }
  }
  uVar4 = DAT_022d6774;
  if ((uVar6 & 0x20) != 0) {
    uVar1 = *(ushort *)((int)param_1 + 0xe);
    if (DAT_022d6770 < uVar1) {
      uVar5 = 6;
    }
    else {
      psVar7[0x22] = uVar1;
      *(ulonglong *)(psVar7 + 0x24) = (ulonglong)uVar4 * (ulonglong)(uint)uVar1 >> 0x10;
    }
  }
  uVar4 = DAT_022d6774;
  if ((uVar6 & 0x40) != 0) {
    uVar1 = (ushort)param_1[4];
    if (DAT_022d6770 < uVar1) {
      uVar5 = 6;
    }
    else {
      psVar7[0x23] = uVar1;
      *(ulonglong *)(psVar7 + 0x28) = (ulonglong)uVar4 * (ulonglong)(uint)uVar1 >> 0x10;
    }
  }
  if ((uVar6 & 0x80) != 0) {
    uVar4 = (uint)*(ushort *)((int)param_1 + 0x12);
    if ((uVar4 < 0xbf) || ((0xdb < uVar4 && (uVar4 <= DAT_022d6778)))) {
      psVar7[0x20] = *(ushort *)((int)param_1 + 0x12);
    }
    else {
      uVar5 = 6;
    }
  }
  if ((uVar6 & 0x100) != 0) {
    uVar4 = (uint)(ushort)param_1[5];
    if ((uVar4 < 0xbf) || ((0xdb < uVar4 && (uVar4 <= DAT_022d6778)))) {
      psVar7[0x21] = (ushort)param_1[5];
    }
    else {
      uVar5 = 6;
    }
  }
  if ((uVar6 & 0x200) != 0) {
    sVar3 = *(short *)((int)param_1 + 0x16);
    psVar7[0x4c] = sVar3;
    psVar7[0x3e5] = sVar3;
  }
  if ((uVar6 & 0x400) != 0) {
    psVar7[0x49] = (ushort)(byte)param_1[6];
  }
  if ((uVar6 & 0x800) != 0) {
    psVar7[0x4a] = (ushort)*(byte *)((int)param_1 + 0x19);
  }
  if ((uVar6 & 0x1000) != 0) {
    psVar7[0x4d] = (ushort)*(byte *)((int)param_1 + 0x1a);
    psVar7[0x3e6] = psVar7[0x4d];
  }
  if ((uVar6 & 0x2000) != 0) {
    psVar7[0x4e] = (ushort)*(byte *)((int)param_1 + 0x1b);
  }
  func_0x037cb534(uVar2);
  return uVar5;
}

