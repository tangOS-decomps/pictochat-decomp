// decomp: module=unk_autoload_0 addr=0x0232b410 name=FUN_0232b410
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x25c (Ghidra's cache says 0x252 - it excludes this function's trailing literal pool), thumb
// triage: noise=34 statements=118
// verify:  python tools/match.py --c <file> --func FUN_0232b410 --addr 0x0232b410 --size 0x25c --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232b410(byte *param_1,undefined4 param_2,undefined1 *param_3,undefined2 param_4,ushort param_5,
            undefined4 param_6)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  int iVar10;
  short *psVar11;
  uint extraout_r1;
  short *psVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  ulonglong uVar17;
  
  uVar8 = *param_3;
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  uVar4 = param_3[3];
  uVar5 = param_3[4];
  uVar6 = param_3[5];
  if (0xff < param_5) {
    param_5 = 0xff;
  }
  uVar7 = (undefined1)param_5;
  if ((param_1[1] != 0) && (iVar15 = 0, param_1[2] != 0)) {
    psVar11 = *(short **)(param_1 + 4);
    iVar10 = 0;
    psVar12 = psVar11;
    do {
      if ((((*psVar12 == 1) && (CONCAT11(uVar8,uVar2) == *(short *)((int)psVar11 + iVar10 + 2))) &&
          (CONCAT11(uVar3,uVar4) == *(short *)((int)psVar11 + iVar10 + 4))) &&
         (CONCAT11(uVar5,uVar6) == *(short *)((int)psVar11 + iVar10 + 6))) {
        FUN_02331ef0(*(int *)(param_1 + 8) + iVar15 * 0x2c);
        uVar9 = FUN_02332080();
        iVar13 = iVar15 * 0xe0;
        iVar14 = 0;
        *(undefined2 *)(*(int *)(param_1 + 4) + iVar13 + 8) = param_4;
        iVar10 = *(int *)(param_1 + 4);
        FUN_02335e0c(*(char *)(iVar10 + 0xb + iVar13) + '\x01',6);
        *(char *)(iVar10 + 0xb + iVar13) = (char)extraout_r1;
        *(undefined1 *)(*(int *)(param_1 + 4) + iVar13 + (extraout_r1 & 0xff) + 0xc) = uVar7;
        iVar10 = *(int *)(param_1 + 4);
        iVar16 = 0;
        iVar13 = iVar10 + iVar13;
        do {
          pbVar1 = (byte *)(iVar13 + 0xc);
          iVar16 = iVar16 + 1;
          iVar13 = iVar13 + 1;
          iVar14 = iVar14 + (uint)*pbVar1;
        } while (iVar16 < 6);
        iVar16 = iVar15 * 0xe0;
        uVar8 = FUN_02335e0c(iVar14,6);
        *(undefined1 *)(iVar10 + iVar16 + 10) = uVar8;
        FUN_023374b8(param_6,*(int *)(param_1 + 4) + iVar16 + 0x20,0xc0);
        FUN_023314e8(*(int *)(param_1 + 4) + iVar16 + 0x20,0xc0);
        FUN_02332094(uVar9);
        uVar17 = FUN_02335dec(param_2,0,DAT_0232b664,0);
        FUN_02331ea8(*(int *)(param_1 + 8) + iVar15 * 0x2c,(int)(uVar17 >> 6),
                     (int)((uVar17 >> 6) >> 0x20),DAT_0232b668,*(int *)(param_1 + 4) + iVar16);
        FUN_02331ff8(*(int *)(param_1 + 8) + iVar15 * 0x2c,*param_1 + 0x80);
        return 1;
      }
      iVar15 = iVar15 + 1;
      psVar12 = psVar12 + 0x70;
      iVar10 = iVar10 + 0xe0;
    } while (iVar15 < (int)(uint)param_1[2]);
  }
  iVar15 = 0;
  if (param_1[2] != 0) {
    psVar12 = *(short **)(param_1 + 4);
    do {
      if (*psVar12 == 0) {
        uVar9 = FUN_02332080();
        param_1[1] = param_1[1] + 1;
        iVar16 = iVar15 * 0xe0;
        *(undefined2 *)(*(int *)(param_1 + 4) + iVar16) = 1;
        *(short *)(*(int *)(param_1 + 4) + iVar16 + 2) = CONCAT11(uVar8,uVar2);
        *(short *)(*(int *)(param_1 + 4) + iVar16 + 4) = CONCAT11(uVar3,uVar4);
        *(short *)(*(int *)(param_1 + 4) + iVar16 + 6) = CONCAT11(uVar5,uVar6);
        *(undefined2 *)(*(int *)(param_1 + 4) + iVar16 + 8) = param_4;
        *(byte **)(*(int *)(param_1 + 4) + iVar16 + 0x14) = param_1;
        iVar10 = 0;
        *(undefined1 *)(*(int *)(param_1 + 4) + iVar16 + 0xb) = 0;
        do {
          iVar13 = iVar10 + iVar16 + *(int *)(param_1 + 4);
          iVar10 = iVar10 + 1;
          *(undefined1 *)(iVar13 + 0xc) = uVar7;
        } while (iVar10 < 6);
        iVar10 = iVar15 * 0xe0;
        *(undefined1 *)(*(int *)(param_1 + 4) + iVar10 + 10) = uVar7;
        FUN_023374b8(param_6,*(int *)(param_1 + 4) + iVar10 + 0x20,0xc0);
        FUN_023314e8(*(int *)(param_1 + 4) + iVar10 + 0x20,0xc0);
        FUN_02332094(uVar9);
        iVar15 = iVar15 * 0x2c;
        FUN_02331ef0(*(int *)(param_1 + 8) + iVar15);
        uVar17 = FUN_02335dec(param_2,0,DAT_0232b664,0);
        FUN_02331ea8(*(int *)(param_1 + 8) + iVar15,(int)(uVar17 >> 6),(int)((uVar17 >> 6) >> 0x20),
                     DAT_0232b668,*(int *)(param_1 + 4) + iVar10);
        FUN_02331ff8(*(int *)(param_1 + 8) + iVar15,*param_1 + 0x80);
        if (*(code **)(param_1 + 0xc) != (code *)0x0) {
          (**(code **)(param_1 + 0xc))(*(int *)(param_1 + 4) + iVar16);
        }
        return 1;
      }
      iVar15 = iVar15 + 1;
      psVar12 = psVar12 + 0x70;
    } while (iVar15 < (int)(uint)param_1[2]);
  }
  return 0;
}

