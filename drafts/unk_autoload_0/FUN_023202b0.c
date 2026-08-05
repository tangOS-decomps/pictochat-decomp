// decomp: module=unk_autoload_0 addr=0x023202b0 name=FUN_023202b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40c (Ghidra's cache says 0x3a8 - it excludes this function's trailing literal pool), thumb
// triage: noise=21 statements=192
// verify:  python tools/match.py --c <file> --func FUN_023202b0 --addr 0x023202b0 --size 0x40c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_023202b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort *puVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_12c [4];
  uint local_128;
  uint local_124;
  undefined2 local_11c [130];
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  FUN_02321198();
  FUN_023211b4();
  FUN_0233746c(0,DAT_023205fc,DAT_02320600);
  FUN_0232131c(DAT_02320604);
  iVar11 = DAT_0232060c;
  iVar10 = DAT_023205fc;
  *(undefined4 *)(DAT_02320608 + 0x24) = 0xffffffff;
  iVar13 = 0;
  do {
    puVar9 = (undefined4 *)(iVar11 + iVar13 * 0x10);
    puVar8 = (undefined4 *)(iVar10 + iVar13 * 0x50);
    uVar7 = puVar9[1];
    *puVar8 = *puVar9;
    puVar8[1] = uVar7;
    iVar13 = iVar13 + 1;
    uVar7 = puVar9[3];
    puVar8[2] = puVar9[2];
    puVar8[3] = uVar7;
  } while (iVar13 < 5);
  *(undefined4 *)(DAT_02320608 + 0x14) = 5;
  *DAT_02320610 = 0xffffffff;
  iVar10 = DAT_02320614;
  *(undefined4 *)(DAT_02320614 + 0x58) = 0x1f;
  *(undefined4 *)(iVar10 + 0x5c) = 0x1f;
  uVar1 = *DAT_02320618;
  *(uint *)(iVar10 + 0x54) = uVar1 & 7;
  FUN_02321cf8(uVar1 & 7);
  FUN_02322c00(auStack_12c);
  if ((local_128 == *DAT_0232061c) && (local_124 == DAT_0232061c[1])) {
    iVar10 = 1;
  }
  else {
    iVar10 = 0;
  }
  *(uint *)(DAT_02320614 + 100) = iVar10 << 10 | *(uint *)(DAT_02320614 + 100) & DAT_02320620;
  if (param_1 != 2) {
    FUN_0233746c(0xc0,DAT_02320624,0x400);
  }
  if (param_1 < 2) {
    FUN_02336334();
    puVar3 = DAT_02320628;
    *DAT_02320628 = DAT_0232062c & *DAT_02320628;
    FUN_0233746c(0,DAT_02320630,(uint)puVar3 >> 0x10);
    FUN_02336e04(1);
    FUN_02336f68(2);
    FUN_023363a4(1,0,0);
    puVar2 = DAT_02320634;
    *DAT_02320634 = *DAT_02320634 & 0x43 | 8;
    *puVar2 = *puVar2 & 0xfffc;
    puVar2[4] = 0;
    puVar2[5] = 0;
    _DAT_04000000 = _DAT_04000000 & DAT_02320638 | 0x1000;
    iVar10 = DAT_0232063c - DAT_02320640;
    FUN_02336c1c(DAT_02320640,0,iVar10);
    FUN_023367c0(DAT_02320644,0,DAT_02320648 - DAT_02320644);
    FUN_02336a40(DAT_0232064c,0,DAT_02320650 - DAT_0232064c);
    FUN_02336840(DAT_02320654,0,DAT_02320658 - DAT_02320654);
    FUN_023367c0(DAT_0232065c,0,2);
    FUN_02337040(4);
    FUN_023370a0(8);
    FUN_023363f0(0);
    puVar2 = DAT_02320660;
    *DAT_02320660 = (ushort)DAT_02320664 | *DAT_02320660 & 0x43;
    *puVar2 = *puVar2 & 0xffbf;
    puVar2[1] = (ushort)DAT_02320668 | puVar2[1] & 0x43;
    puVar2[1] = puVar2[1] & 0xffbf;
    puVar2[3] = puVar2[3] & 0xffbf;
    uVar4 = DAT_02320670;
    uVar6 = DAT_0232066c;
    *(uint *)((int)puVar2 * 0x800000) =
         *(uint *)((int)puVar2 * 0x800000) & DAT_0232066c | DAT_02320670;
    *(uint *)(puVar2 + -4) = uVar6 & *(uint *)(puVar2 + -4) | uVar4;
    FUN_02336c60(DAT_02320640,0,iVar10);
    iVar10 = DAT_02320674;
    iVar11 = 0;
    do {
      FUN_02336a84(iVar10 + iVar11 * 0x80,iVar11 * 0x40,0x40);
      FUN_02336a84(iVar10 + (iVar11 * 2 + 1) * 0x40,iVar11 * 0x40 + 0x800,0x40);
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x20);
    FUN_02321db4();
    FUN_02320c7c();
    FUN_02320ac8();
    uVar7 = FUN_02320c7c();
    FUN_02320afc(uVar7,DAT_02320678);
    uVar7 = FUN_02320c74();
    FUN_02320afc(uVar7,DAT_0232067c);
  }
  puVar2 = DAT_02320660;
  *DAT_02320660 = *DAT_02320660 & 0xfffc;
  puVar2[1] = puVar2[1] & 0xfffc | 3;
  puVar2[2] = puVar2[2] & 0xfffc;
  puVar2[3] = puVar2[3] & 0xfffc;
  uVar7 = DAT_02320680;
  puVar2[4] = 0;
  puVar2[5] = 0;
  *(undefined4 *)(puVar2 + 6) = uVar7;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  FUN_02321db4();
  FUN_02337454(DAT_02320684,0x6200000,DAT_02320688 - DAT_02320684);
  FUN_023221d4(0x1f,0x22,6);
  FUN_02321df4();
  pvVar5 = FUN_023215e4();
  uVar7 = FUN_0232dff0(DAT_02320678);
  FUN_02321600(pvVar5,uVar7);
  FUN_02322244(pvVar5);
  FUN_02321e24(pvVar5);
  iVar10 = DAT_023205fc;
  iVar11 = 0;
  do {
    iVar13 = iVar10 + iVar11 * 0x50;
    if (-1 < *(int *)(iVar13 + 8)) {
      FUN_02321634(pvVar5,iVar13 + 0x10,DAT_0232068c);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 5);
  uVar6 = (uint)((*DAT_02320690 & 2) != 0) << 4 | *(uint *)(DAT_02320614 + 100) & 0xffffffef;
  *(uint *)(DAT_02320614 + 100) = uVar6;
  if ((int)(uVar6 << 0x1b) < 0) {
    FUN_0233621c(local_11c,DAT_02320694);
    FUN_0233697c(DAT_02320698,DAT_0232069c,0x200);
    iVar11 = *(int *)(DAT_02320614 + 0x54);
    iVar10 = iVar11;
    if (*(short *)(DAT_02320698 + iVar11 * 0x100 + 0x220) == 0) {
      iVar13 = DAT_023206a0;
      if ((iVar11 != 0) && (iVar13 = DAT_023206a8, iVar11 == 1)) {
        iVar13 = DAT_023206a4;
      }
      iVar12 = 0;
      while ((iVar10 = iVar11, iVar12 < 6 &&
             (iVar10 = (int)*(short *)(iVar13 + iVar12 * 2),
             *(short *)(DAT_02320698 + iVar10 * 0x100 + 0x220) == 0))) {
        iVar12 = iVar12 + 1;
      }
    }
    iVar11 = 0;
    do {
      iVar13 = iVar11 + 1;
      local_11c[iVar11] = *(undefined2 *)(DAT_023205fc + iVar10 * 0x100 + iVar11 * 2 + DAT_023206ac)
      ;
      iVar11 = iVar13;
    } while (iVar13 < 0x80);
    local_11c[iVar13] = 0;
    FUN_023216e0(DAT_023206b0);
    if (param_1 < 2) {
      FUN_023228a4();
    }
  }
  else {
    FUN_02321684(DAT_023206b0,DAT_0232068c,0x25);
    *(undefined2 *)(DAT_023206b4 + 0x26) = 4;
  }
  FUN_023209c4();
  FUN_02336800(DAT_023206b8,0,2);
  puVar3 = DAT_02320628;
  *DAT_02320628 = *DAT_02320628 & DAT_02320638 | 0x1200;
  FUN_02336428(puVar3 + 0x14,2,0x20,0,0x10);
  FUN_02320728(0);
  *(uint *)(DAT_02320718 + 100) = *(uint *)(DAT_02320718 + 100) | 0xc;
  *(undefined4 *)(DAT_0232071c + 4) = 0;
  *(undefined4 *)(DAT_02320720 + 0x10) = 3;
  FUN_023307d4(1);
  FUN_02336310(1);
  FUN_02336368();
  *DAT_02320724 = *DAT_02320724 | 0x10000;
  return;
}

