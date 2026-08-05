// decomp: module=unk_autoload_0 addr=0x0232e104 name=FUN_0232e104
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=1 statements=21
// verify:  python tools/match.py --c <file> --func FUN_0232e104 --addr 0x0232e104 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e104(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    FUN_0232e0ac(param_1,param_3);
    return;
  }
  if (param_2 == *param_1) {
    FUN_0232e0d8(param_1,param_3,param_3,*param_1,param_4);
    return;
  }
  uVar2 = (uint)*(ushort *)((int)param_1 + 10);
  iVar1 = *(int *)(param_2 + uVar2);
  *(int *)(param_3 + uVar2) = iVar1;
  *(int *)(param_3 + uVar2 + 4) = param_2;
  *(int *)(iVar1 + uVar2 + 4) = param_3;
  *(int *)(param_2 + (uint)*(ushort *)((int)param_1 + 10)) = param_3;
  *(short *)(param_1 + 2) = (short)param_1[2] + 1;
  return;
}

