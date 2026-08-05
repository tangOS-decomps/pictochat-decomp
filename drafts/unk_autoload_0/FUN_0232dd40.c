// decomp: module=unk_autoload_0 addr=0x0232dd40 name=FUN_0232dd40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x11e, thumb
// triage: noise=14 statements=70
// verify:  python tools/match.py --c <file> --func FUN_0232dd40 --addr 0x0232dd40 --size 0x11e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232dd40(void *param_1,undefined4 param_2,ushort param_3,int param_4,int param_5,
                 int param_6,short *param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  int val2;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int *piVar6;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined2 local_4;
  
  iVar3 = param_4;
  local_40 = param_2;
  val2 = FUN_0232dec8(param_1,param_7,param_5);
  iVar4 = param_6;
  local_34 = FUN_0232def4(param_1,(undefined4 *)param_7,param_6);
  local_4c = CONCAT22(local_4c._2_2_,param_3);
  iVar2 = FUN_0232df40(local_4c,val2,iVar4,iVar3);
  local_4 = (undefined2)param_4;
  local_4c = CONCAT22(local_4c._2_2_,local_4);
  local_3c = FUN_0232df74(local_4c,local_34,iVar4,iVar3);
  local_4c = CONCAT22(local_4c._2_2_,param_3);
  iVar3 = FUN_0232dd18(local_4c,val2,iVar4,iVar3);
  piVar6 = &local_28;
  iVar4 = param_5;
  local_38 = iVar2 + iVar3;
  FUN_0232de74(param_1,param_7);
  local_4c = CONCAT22(local_4c._2_2_,param_3);
  iVar4 = FUN_0232dd18(local_4c,local_28,(int)piVar6,iVar4);
  sVar5 = *param_7;
  iVar4 = (iVar2 + iVar3) - iVar4;
  if (sVar5 != 0) {
    local_30 = &local_4c;
    local_2c = (uint)param_3;
    do {
      if (sVar5 == 10) {
        piVar6 = &local_28;
        iVar4 = param_5;
        FUN_0232de74(param_1,param_7 + 1);
        puVar1 = local_30;
        *(short *)local_30 = (short)local_2c;
        iVar4 = FUN_0232dd18(*puVar1,local_28,(int)piVar6,iVar4);
        iVar4 = local_38 - iVar4;
        local_3c = local_3c + ((*(ushort *)((int)param_1 + 0x16) & 0x3ff) >> 5) + param_6;
      }
      else if (sVar5 != 0xd) {
        local_48 = FUN_0232db60(param_1);
        local_48 = local_48 & 0xffff;
        iVar3 = local_48 * 2;
        local_44 = param_8;
        FUN_0232dc8c(param_1,local_40,
                     iVar4 - (*(ushort *)(*(int *)((int)param_1 + 0xc) + iVar3) & 0xff),local_3c);
        iVar4 = iVar4 + param_5 + (uint)(*(ushort *)(*(int *)((int)param_1 + 0xc) + iVar3) >> 8);
      }
      param_7 = param_7 + 1;
      sVar5 = *param_7;
    } while (sVar5 != 0);
  }
  return;
}

