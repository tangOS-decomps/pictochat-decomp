// decomp: module=unk_autoload_0 addr=0x02326140 name=FUN_02326140
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x330 (Ghidra's cache says 0x2d8 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=158
// verify:  python tools/match.py --c <file> --func FUN_02326140 --addr 0x02326140 --size 0x330 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_02326140(void)

{
  short sVar1;
  ushort uVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 in_r3;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  if (DAT_02326418[3] == 0) {
    iVar5 = FUN_023230cc(0x100000);
    DAT_02326418[3] = iVar5;
  }
  if (*DAT_02326418 == 0) {
    iVar5 = FUN_023230cc(0x1000);
    *DAT_02326418 = iVar5;
  }
  if (DAT_02326418[4] == 0) {
    iVar5 = FUN_023230cc(DAT_0232641c);
    DAT_02326418[4] = iVar5;
  }
  if (DAT_02326418[2] == 0) {
    iVar5 = FUN_023230cc(0x7000);
    DAT_02326418[2] = iVar5;
  }
  _DAT_04000000 = _DAT_04000000 & DAT_02326420 | 0x100;
  _DAT_04000008 = _DAT_04000008 & 0x40 | 0xf13;
  uVar2 = _DAT_0400000a & 0x40;
  _DAT_0400000a = uVar2 | 0x209;
  _DAT_0400000c = ((ushort)DAT_02326424 | _DAT_0400000c & 0x43) & 0xfffc | 2;
  _DAT_0400000e = ((ushort)DAT_02326428 | _DAT_0400000e & 0x43) & 0xfffc | 2;
  FUN_0233746c(0,0x6400000,0x20000,uVar2 | 0x208,in_r3);
  *DAT_0232642c = 5;
  FUN_02336840(PTR_DAT_02326430,0,0xc0);
  puVar4 = PTR_DAT_02326434;
  iVar5 = 0;
  do {
    FUN_02336840(puVar4 + iVar5 * 0x10,iVar5 * 0x20 + 0x10,0x10);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  FUN_023367c0(PTR_DAT_02326438,0,(int)PTR_DAT_0232643c - (int)PTR_DAT_02326438);
  FUN_023367c0(PTR_DAT_02326440,0,2);
  FUN_02336ca4(PTR_DAT_02326444,0,(int)PTR_DAT_02326448 - (int)PTR_DAT_02326444);
  iVar5 = FUN_02336728();
  iVar8 = iVar5 + 0x400;
  iVar13 = 0;
  do {
    for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1) {
      uVar12 = *(uint *)(iVar5 + uVar6 * 4);
      uVar11 = DAT_0232644c & uVar12;
      uVar10 = 0;
      if ((uVar11 & 0xf0000000) != 0) {
        uVar10 = 0x80000000;
      }
      if ((uVar11 & 0xf000000) != 0) {
        uVar10 = uVar10 | 0x8000000;
      }
      if ((uVar11 & 0xf00000) != 0) {
        uVar10 = uVar10 | 0x800000;
      }
      if ((uVar11 & 0xf0000) != 0) {
        uVar10 = uVar10 | 0x80000;
      }
      if ((uVar11 & 0xf000) != 0) {
        uVar10 = uVar10 | 0x8000;
      }
      if ((uVar11 & 0xf00) != 0) {
        uVar10 = uVar10 | 0x800;
      }
      if ((uVar11 & 0xf0) != 0) {
        uVar10 = uVar10 | 0x80;
      }
      if ((uVar11 & 0xf) != 0) {
        uVar10 = uVar10 | 8;
      }
      *(uint *)(iVar8 + uVar6 * 4) = uVar10 + uVar12;
    }
    iVar13 = iVar13 + 1;
    iVar5 = iVar5 + 0x20;
    iVar8 = iVar8 + 0x20;
  } while (iVar13 < 0x20);
  iVar5 = FUN_023365d8();
  iVar8 = 0;
  sVar1 = (short)DAT_02326450;
  do {
    iVar14 = 0;
    iVar13 = iVar5 + iVar8 * 0x40;
    do {
      iVar9 = iVar14 * 2;
      iVar14 = iVar14 + 1;
      *(short *)(iVar13 + iVar9) = sVar1;
    } while (iVar14 < 3);
    iVar14 = 3;
    do {
      iVar9 = iVar14 * 2;
      iVar14 = iVar14 + 1;
      *(short *)(iVar13 + iVar9) = sVar1 + 8;
    } while (iVar14 < 0x20);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x18);
  iVar5 = FUN_023365d8();
  uVar7 = DAT_02326454;
  iVar8 = 0;
  do {
    iVar13 = iVar8 * 0x40;
    iVar8 = iVar8 + 1;
    *(short *)(iVar5 + 0x800 + iVar13) = (short)uVar7;
  } while (iVar8 < 0x18);
  FUN_0233746c(0,DAT_02326418[3],0x100000);
  FUN_0233746c(0,*DAT_02326418,0x40);
  piVar3 = DAT_02326418;
  iVar5 = 0;
  do {
    iVar8 = 0;
    do {
      sVar1 = (short)iVar8;
      iVar13 = iVar8 * 2;
      iVar8 = iVar8 + 1;
      *(short *)(iVar13 + iVar5 * 0x40 + *piVar3) = sVar1 + (short)iVar5 * 0x20;
    } while (iVar8 < 0x20);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  FUN_02331504(*DAT_02326418,0x1000);
  FUN_02336a40(*DAT_02326418,0,0x1000);
  FUN_02336bd8(PTR_DAT_02326458,0,(int)PTR_DAT_0232645c - (int)PTR_DAT_02326458);
  FUN_023369b8(PTR_s_OpPpOpPpOpPpOpPpOpPpOpPpOpPpOpPp_02344ce2_2_02326460,0,
               (int)PTR_s__02344ce2_0x802_02326464 -
               (int)PTR_s_OpPpOpPpOpPpOpPpOpPpOpPpOpPpOpPp_02344ce2_2_02326460);
  FUN_0233746c(0,DAT_02326418[4],DAT_0232641c);
  FUN_0233746c(0,DAT_02326418[2],0x7000);
  piVar3 = DAT_02326418;
  DAT_02326418[8] = 0;
  piVar3[1] = 0;
  piVar3[5] = 0;
  piVar3[6] = 0;
  piVar3[7] = 0;
  FUN_02320c74();
  FUN_02320ac8();
  uVar7 = FUN_02320c74();
  uVar7 = FUN_02320afc(uVar7,PTR_DAT_02326468);
  FUN_023215d0();
  iVar5 = FUN_02320c74();
  FUN_02321600(uVar7,*(undefined4 *)(iVar5 + DAT_0232646c));
  FUN_023273a0();
  piVar3 = DAT_02326418;
  DAT_02326418[10] = 0x14;
  piVar3[9] = 0x14;
  return;
}

