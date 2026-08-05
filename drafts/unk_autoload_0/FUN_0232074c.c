// decomp: module=unk_autoload_0 addr=0x0232074c name=FUN_0232074c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1ec (Ghidra's cache says 0x1a4 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=75
// verify:  python tools/match.py --c <file> --func FUN_0232074c --addr 0x0232074c --size 0x1ec --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0232074c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  *(undefined4 *)(DAT_023208f0 + 2) = 1;
  puVar3 = DAT_023208f8;
  bVar1 = *DAT_023208f4;
  *DAT_023208f8 = *DAT_023208f8 & 0xfffc;
  puVar3[1] = puVar3[1] & 0xfffc;
  puVar3[2] = puVar3[2] & 0xfffc | 3;
  uVar2 = puVar3[3];
  puVar3[3] = uVar2 & 0xfffc | 3;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  FUN_02336840(DAT_023208fc + (bVar1 & 0xf) * 0x20,0x1e0,0x20,uVar2 & 0xfffc,param_4);
  puVar4 = DAT_023208f0;
  if (param_1 != 2) {
    *(undefined4 *)(DAT_023208f0 + 4) = 0;
    if (param_1 == 3) {
      *(undefined4 *)(puVar4 + 6) = 0xc;
      *(undefined4 *)(puVar4 + 8) = 1;
      FUN_02336428(DAT_02320900,4,8,0,0x10);
    }
    else {
      *(undefined4 *)(puVar4 + 6) = 0x1f;
      FUN_02336444(DAT_02320900,0x1f,0x10);
    }
    puVar3 = DAT_023208f8;
    *DAT_023208f8 = *DAT_023208f8 & 0x43 | 0x10;
    puVar3[1] = puVar3[1] & 0x43 | 0xd08;
    puVar3[2] = puVar3[2] & 0x43 | 0xe10;
    puVar3[3] = puVar3[3] & 0x43 | 0xf10;
    pvVar5 = FUN_023364a8();
    for (iVar7 = 0; iVar7 < 0x18; iVar7 = iVar7 + 1) {
      for (iVar8 = 0; iVar8 < 0x20; iVar8 = iVar8 + 1) {
        *(ushort *)((int)pvVar5 + iVar8 * 2 + iVar7 * 0x40) =
             (short)iVar8 + (short)iVar7 * 0x20 | 0x3000;
      }
    }
    pvVar5 = FUN_023366e8();
    FUN_02337440(0,pvVar5,0x8000);
    FUN_02336ca4(DAT_02320904,0,DAT_02320908 - DAT_02320904);
    FUN_023367c0(DAT_0232090c,0,DAT_02320910 - DAT_0232090c);
    *DAT_023208f0 = 0;
    FUN_023314e8(DAT_02320914,2);
    FUN_023367c0(DAT_02320914,0,2);
    FUN_023367c0(DAT_023208fc + (bVar1 & 0xf) * 0x20,0x1e0,0x20);
    FUN_02336ac8(DAT_02320918,0,DAT_0232091c - DAT_02320918);
    FUN_02336b50(DAT_02320920,0,DAT_02320924 - DAT_02320920);
    _DAT_04000000 = *(int *)(DAT_023208f0 + 6) << 8 | _DAT_04000000 & DAT_02320928;
  }
  FUN_02320c74();
  FUN_02320ac8();
  uVar6 = FUN_02320c74();
  uVar6 = FUN_02320afc(uVar6,DAT_0232092c);
  FUN_023215d0();
  iVar7 = FUN_02320c74();
  FUN_02321600(uVar6,*(undefined4 *)(iVar7 + DAT_02320930));
  FUN_02320a64(param_1);
  *(undefined4 *)(DAT_02320934 + 8) = 0;
  return;
}

