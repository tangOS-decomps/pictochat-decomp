// decomp: module=unk_autoload_0 addr=0x02326488 name=FUN_02326488
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x290 (Ghidra's cache says 0x272 - it excludes this function's trailing literal pool), thumb
// triage: noise=16 statements=104
// verify:  python tools/match.py --c <file> --func FUN_02326488 --addr 0x02326488 --size 0x290 --module unk_autoload_0 --version 2.0/sp1


void FUN_02326488(int param_1,int param_2)

{
  short sVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int extraout_r1;
  int iVar7;
  undefined4 uVar8;
  uint local_64;
  int local_44;
  int local_40;
  undefined4 local_3c;
  uint uStack_38;
  undefined4 local_34;
  undefined4 local_30 [4];
  short local_20;
  ushort uStack_1e;
  undefined4 local_1c;
  undefined4 local_18;
  
  switch(param_2) {
  case 0x10:
    uVar8 = 8;
    FUN_02320978(0x16);
    break;
  case 0x11:
    uVar8 = 0xb;
    FUN_02320978(0x15);
    break;
  case 0x12:
    uVar8 = 1;
    FUN_02320978(0x17);
    break;
  case 0x13:
    uVar8 = 2;
    break;
  default:
    uVar8 = 8;
  }
  puVar2 = FUN_0232dfa8(DAT_02326704,0);
  local_18 = puVar2[2];
  uStack_1e = (ushort)((uint)*puVar2 >> 0x10);
  uStack_1e = (ushort)((uint)(((((int)(short)uStack_1e << 0x14) >> 0x14) + -4) * 0x10000) >> 0x10) &
              (ushort)((uint)DAT_02326708 >> 0x14) | uStack_1e & (ushort)DAT_02326708;
  local_20 = (short)*puVar2;
  local_1c._0_2_ = (ushort)puVar2[1];
  local_1c._2_2_ = (undefined2)((uint)puVar2[1] >> 0x10);
  local_1c = CONCAT22(local_1c._2_2_,(ushort)local_1c & (ushort)DAT_0232670c) | 0x400;
  FUN_0233746c(0,DAT_02326710,0x2800);
  piVar3 = FUN_02321c58();
  FUN_0232db10(local_30,DAT_02326710,0x100,0x50,0,piVar3);
  if (param_2 == 0x12) {
    local_44 = ((int)local_20 << 0x14) >> 0x14;
    for (iVar7 = 0; (sVar1 = *(short *)(param_1 + iVar7 * 2), sVar1 != 10 && (sVar1 != 0));
        iVar7 = iVar7 + 1) {
      piVar3 = FUN_02321c60();
      piVar4 = FUN_02321c60();
      iVar5 = FUN_0232df14(piVar4,*(undefined2 *)(param_1 + iVar7 * 2));
      FUN_02335e0c(iVar7,0xd);
      FUN_0232dc5c(piVar3,local_30,local_44 - iVar5,((int)(short)uStack_1e << 0x14) >> 0x14,
                   *(undefined2 *)(param_1 + iVar7 * 2),extraout_r1 + 3);
      piVar3 = FUN_02321c60();
      iVar5 = FUN_0232de60(piVar3,*(undefined2 *)(param_1 + iVar7 * 2));
      local_44 = local_44 + (char)local_1c + iVar5;
    }
    if (*(short *)(param_1 + iVar7 * 2) == 10) {
      uStack_38 = local_1c;
      local_34 = local_18;
      local_3c = CONCAT22((ushort)((uint)(((((int)(short)uStack_1e << 0x14) >> 0x14) + 0x10) *
                                         0x10000) >> 0x10) & (ushort)((uint)DAT_02326708 >> 0x14) |
                          uStack_1e & (ushort)DAT_02326708,local_20);
      piVar3 = FUN_02321c60();
      local_64 = local_3c & 0xffff;
      FUN_0232dd40(piVar3,local_30,local_64,local_3c >> 0x10,(int)(char)uStack_38,
                   ((int)(short)uStack_38 << 0x10) >> 0x18,param_1 + (iVar7 + 1) * 2,uVar8);
    }
  }
  else if (param_2 == 0x13) {
    piVar3 = FUN_02321c60();
    FUN_0232dd40(piVar3,local_30,local_20,uStack_1e,(int)(char)local_1c,
                 ((int)(short)(ushort)local_1c << 0x10) >> 0x18,param_1,uVar8);
  }
  else {
    piVar3 = FUN_02321c60();
    FUN_0232dd40(piVar3,local_30,local_20,uStack_1e,(int)(char)local_1c,
                 ((int)(short)(ushort)local_1c << 0x10) >> 0x18,param_1,2);
    iVar7 = DAT_02326714;
    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
      iVar6 = FUN_023346a8(param_1,iVar5 + iVar7 & 0xffff);
      if (iVar6 != 0) {
        *(undefined2 *)(iVar6 + 2) = 0;
        piVar3 = FUN_02321c60();
        FUN_0232dd40(piVar3,local_30,local_20,uStack_1e,(int)(char)local_1c,
                     ((int)(short)(ushort)local_1c << 0x10) >> 0x18,param_1,uVar8);
        break;
      }
    }
  }
  FUN_02325b74(local_30[0],&local_40,0);
  FUN_0232679c(local_30[0],local_40 << 0xb,param_2,0);
  return;
}

