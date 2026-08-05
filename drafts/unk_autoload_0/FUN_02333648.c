// decomp: module=unk_autoload_0 addr=0x02333648 name=FUN_02333648
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x338 (Ghidra's cache says 0x30c - it excludes this function's trailing literal pool), thumb
// triage: noise=17 statements=212
// verify:  python tools/match.py --c <file> --func FUN_02333648 --addr 0x02333648 --size 0x338 --module unk_autoload_0 --version 2.0/sp1


char * FUN_02333648(uint param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
                   undefined4 param_6,int param_7)

{
  undefined1 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  char cVar17;
  undefined8 uVar18;
  undefined1 local_64 [2];
  undefined2 local_62;
  char acStack_60 [5];
  char local_5b;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint uStack_28;
  byte bStack_11;
  uint local_10;
  undefined4 local_c;
  int iStack_8;
  uint uStack_4;
  
  uVar10 = param_4 >> 8 & 0xff;
  if (DAT_02333954 < param_7) {
    return (char *)0x0;
  }
  local_64[0] = 0;
  local_62 = 0x20;
  uStack_28 = param_4;
  local_10 = param_1;
  local_c = param_2;
  iStack_8 = param_3;
  uStack_4 = param_4;
  FUN_02334eb4(local_64,param_1,param_2,acStack_60);
  uVar18 = FUN_023346ec(local_10,local_c);
  cVar17 = '\x01';
  FUN_02335b58(0,0,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
  pcVar9 = DAT_02333978;
  pcVar8 = DAT_02333974;
  pcVar7 = DAT_02333970;
  pcVar6 = DAT_0233396c;
  pcVar5 = DAT_02333968;
  pcVar4 = DAT_02333964;
  pcVar3 = DAT_02333960;
  pcVar16 = DAT_0233395c;
  pcVar11 = DAT_02333958;
  if (cVar17 != '\0') {
    *(char *)(param_3 + -6) = *DAT_02333958;
    *(char *)(param_3 + -5) = pcVar11[1];
    *(char *)(param_3 + -4) = pcVar11[2];
    *(char *)(param_3 + -3) = pcVar11[3];
    *(char *)(param_3 + -2) = pcVar11[4];
    *(char *)(param_3 + -1) = pcVar11[5];
    return (char *)(param_3 + -6);
  }
  if (local_5b == 'I') {
    if (acStack_60[0] == '\0') {
      pcVar11 = (char *)(param_3 + -4);
      if (param_5._1_1_ == 'A') {
        *pcVar11 = *DAT_02333964;
        *(char *)(param_3 + -3) = pcVar4[1];
        *(char *)(param_3 + -2) = pcVar4[2];
        *(char *)(param_3 + -1) = pcVar4[3];
        return pcVar11;
      }
      *pcVar11 = *DAT_02333968;
      *(char *)(param_3 + -3) = pcVar5[1];
      *(char *)(param_3 + -2) = pcVar5[2];
      *(char *)(param_3 + -1) = pcVar5[3];
      return pcVar11;
    }
    pcVar11 = (char *)(param_3 + -5);
    if (param_5._1_1_ == 'A') {
      *pcVar11 = *DAT_0233395c;
      *(char *)(param_3 + -4) = pcVar16[1];
      *(char *)(param_3 + -3) = pcVar16[2];
      *(char *)(param_3 + -2) = pcVar16[3];
      *(char *)(param_3 + -1) = pcVar16[4];
      return pcVar11;
    }
    *pcVar11 = *DAT_02333960;
    *(char *)(param_3 + -4) = pcVar3[1];
    *(char *)(param_3 + -3) = pcVar3[2];
    *(char *)(param_3 + -2) = pcVar3[3];
    *(char *)(param_3 + -1) = pcVar3[4];
    return pcVar11;
  }
  if (local_5b != 'N') {
    iVar12 = 0;
    local_38 = 0x101;
    local_2c = 1;
    local_30 = 0;
    local_34 = CONCAT22(local_34._2_2_,0x6400);
    do {
      iVar2 = -iVar12;
      uVar1 = *(undefined1 *)((int)&local_10 + iVar12);
      *(undefined1 *)((int)&local_10 + iVar12) = *(undefined1 *)((int)&local_c + iVar2 + 3);
      iVar12 = iVar12 + 1;
      *(undefined1 *)((int)&local_c + iVar2 + 3) = uVar1;
    } while (iVar12 < 4);
    iVar12 = FUN_02333288((((local_10 >> 8 & 0xff) << 0x11 | local_10 << 0x19) >> 0x15 &
                          DAT_0233397c) - (DAT_0233397c >> 1),param_3,0x101,local_34,0,1);
    if (param_5._1_1_ == 'a') {
      cVar17 = 'p';
    }
    else {
      cVar17 = 'P';
    }
    pcVar11 = (char *)(iVar12 + -1);
    *pcVar11 = cVar17;
    uVar15 = param_7 * 4 + 0xb;
    for (iVar12 = param_7; 0 < iVar12; iVar12 = iVar12 + -1) {
      if ((int)uVar15 < 0x40) {
        uVar13 = 7 - (uVar15 & 7);
        uVar14 = (int)(uint)*(byte *)((int)&local_10 + ((int)uVar15 >> 3)) >> (uVar13 & 0xff) & 0xff
        ;
        if ((uVar15 & 0xfffffff8) != (uVar15 - 4 & 0xfffffff8)) {
          uVar14 = (int)((uint)(&bStack_11)[(int)uVar15 >> 3] << 8) >> (uVar13 & 0xff) & 0xffU |
                   uVar14;
        }
        cVar17 = (char)(uVar14 & 0xf);
        if ((uVar14 & 0xf) < 10) {
          cVar17 = cVar17 + '0';
        }
        else if (param_5._1_1_ == 'a') {
          cVar17 = cVar17 + 'W';
        }
        else {
          cVar17 = cVar17 + '7';
        }
      }
      else {
        cVar17 = '0';
      }
      pcVar11 = pcVar11 + -1;
      uVar15 = uVar15 - 4;
      *pcVar11 = cVar17;
    }
    if ((param_7 != 0) || (param_4 >> 0x18 != 0)) {
      pcVar11 = pcVar11 + -1;
      *pcVar11 = '.';
    }
    pcVar11[-1] = '1';
    if (param_5._1_1_ == 'a') {
      cVar17 = 'x';
    }
    else {
      cVar17 = 'X';
    }
    pcVar11[-2] = cVar17;
    pcVar16 = pcVar11 + -3;
    *pcVar16 = '0';
    if (acStack_60[0] == '\0') {
      if (uVar10 == 1) {
        pcVar16 = pcVar11 + -4;
        *pcVar16 = '+';
      }
      else if (uVar10 == 2) {
        pcVar16 = pcVar11 + -4;
        *pcVar16 = ' ';
      }
    }
    else {
      pcVar16 = pcVar11 + -4;
      *pcVar16 = '-';
    }
    return pcVar16;
  }
  if (acStack_60[0] != '\0') {
    pcVar11 = (char *)(param_3 + -5);
    if (param_5._1_1_ == 'A') {
      *pcVar11 = *DAT_0233396c;
      *(char *)(param_3 + -4) = pcVar6[1];
      *(char *)(param_3 + -3) = pcVar6[2];
      *(char *)(param_3 + -2) = pcVar6[3];
      *(char *)(param_3 + -1) = pcVar6[4];
      return pcVar11;
    }
    *pcVar11 = *DAT_02333970;
    *(char *)(param_3 + -4) = pcVar7[1];
    *(char *)(param_3 + -3) = pcVar7[2];
    *(char *)(param_3 + -2) = pcVar7[3];
    *(char *)(param_3 + -1) = pcVar7[4];
    return pcVar11;
  }
  pcVar11 = (char *)(param_3 + -4);
  if (param_5._1_1_ == 'A') {
    *pcVar11 = *DAT_02333974;
    *(char *)(param_3 + -3) = pcVar8[1];
    *(char *)(param_3 + -2) = pcVar8[2];
    *(char *)(param_3 + -1) = pcVar8[3];
    return pcVar11;
  }
  *pcVar11 = *DAT_02333978;
  *(char *)(param_3 + -3) = pcVar9[1];
  *(char *)(param_3 + -2) = pcVar9[2];
  *(char *)(param_3 + -1) = pcVar9[3];
  return pcVar11;
}

