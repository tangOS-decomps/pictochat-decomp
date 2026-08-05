// decomp: module=unk_autoload_0 addr=0x023218cc name=FUN_023218cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, thumb
// triage: noise=6 statements=26
// verify:  python tools/match.py --c <file> --func FUN_023218cc --addr 0x023218cc --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_023218cc(undefined4 *param_1,int param_2,int *param_3,int *param_4,int *param_5,
                 int *param_6,undefined4 *param_7)

{
  undefined2 *puVar1;
  int *piVar2;
  int iVar3;
  int extra;
  int *unused3;
  undefined4 local_1c;
  
  unused3 = param_4;
  puVar1 = FUN_0232dfa8(param_1,param_2);
  piVar2 = FUN_02321c58();
  iVar3 = FUN_0232dec8(piVar2 + (uint)((ushort)puVar1[3] >> 0xc) * 8,param_7,(int)(char)puVar1[2]);
  *param_5 = iVar3;
  piVar2 = FUN_02321c58();
  extra = ((int)(short)puVar1[2] << 0x10) >> 0x18;
  iVar3 = FUN_0232def4(piVar2 + (uint)((ushort)puVar1[3] >> 0xc) * 8,param_7,extra);
  *param_6 = iVar3;
  local_1c = CONCAT22(local_1c._2_2_,*puVar1);
  iVar3 = FUN_0232df40(local_1c,*param_5,extra,(int)unused3);
  *param_3 = iVar3;
  local_1c = CONCAT22(local_1c._2_2_,puVar1[1]);
  iVar3 = FUN_0232df74(local_1c,*param_6,extra,(int)unused3);
  *param_4 = iVar3;
  return;
}

