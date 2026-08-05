// decomp: module=unk_autoload_0 addr=0x02320c84 name=FUN_02320c84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x190 (Ghidra's cache says 0x174 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=62
// verify:  python tools/match.py --c <file> --func FUN_02320c84 --addr 0x02320c84 --size 0x190 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_02320c84(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            uint param_7,uint param_8,uint param_9)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_3c;
  uint local_30;
  
  iVar6 = param_4 * 8;
  iVar9 = param_2 + 8 + iVar6;
  iVar3 = param_3;
  puVar2 = (ushort *)FUN_0232dff4(param_1,*(undefined4 *)(iVar9 + 4));
  local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(param_2 + 8 + iVar6));
  iVar6 = FUN_0232df40(local_3c,*puVar2 & 0xff,iVar3,param_4);
  local_3c = CONCAT22(local_3c._2_2_,*(undefined2 *)(iVar9 + 2));
  iVar3 = FUN_0232df74(local_3c,(uint)(*puVar2 >> 8),iVar3,param_4);
  iVar9 = *(int *)(iVar9 + 4);
  uVar1 = FUN_0232dfc0(param_1,iVar9);
  puVar4 = FUN_0232dfd0(param_1,iVar9);
  FUN_0232dff4(param_1,iVar9);
  local_30 = 0;
  for (iVar9 = 0; iVar9 < *(int *)(param_3 + DAT_02320df8); iVar9 = iVar9 + 1) {
    iVar8 = param_3 + iVar9 * 8;
    if (*(undefined4 **)(iVar8 + DAT_02320dfc) == param_1) {
      local_30 = *(uint *)(iVar8 + DAT_02320e00) >> 7;
    }
  }
  for (iVar9 = 0; iVar9 < (int)(uint)uVar1; iVar9 = iVar9 + 1) {
    iVar8 = *(int *)(param_3 + 0x600) * 8;
    uVar7 = puVar4[1];
    puVar5 = (uint *)(param_3 + iVar8);
    *(undefined4 *)(param_3 + iVar8) = *puVar4;
    puVar5[1] = uVar7;
    if ((int)((*(uint *)(param_3 + iVar8) & 0xff) + param_6 + iVar3) < 0xc0) {
      *(ushort *)(puVar5 + 1) =
           *(short *)(puVar4 + 2) + (short)local_30 | (ushort)puVar5[1] & (ushort)DAT_02320e04;
      uVar7 = *puVar5 & DAT_02320e08;
      *puVar5 = (uVar7 & 0xff) + param_6 + iVar3 & 0xff |
                uVar7 & 0xffffff00 |
                (((*puVar5 & 0x1ffffff) >> 0x10) + param_5 + iVar6 & 0x1ff) << 0x10;
      if (-1 < (int)param_7) {
        puVar5[1] = (param_7 & 0xf) << 0xc | puVar5[1] & DAT_02320e0c;
      }
      if (-1 < (int)param_8) {
        *puVar5 = (param_8 & 3) << 10 | *puVar5 & DAT_02320e10;
      }
      if (-1 < (int)param_9) {
        puVar5[1] = (param_9 & 3) << 10 | puVar5[1] & DAT_02320e10;
      }
      *(int *)(param_3 + 0x600) = *(int *)(param_3 + 0x600) + 1;
    }
    puVar4 = puVar4 + 3;
  }
  return 1;
}

