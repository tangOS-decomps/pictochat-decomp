// decomp: module=unk_autoload_0 addr=0x0232ce20 name=FUN_0232ce20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xfe, thumb
// triage: noise=9 statements=61
// verify:  python tools/match.py --c <file> --func FUN_0232ce20 --addr 0x0232ce20 --size 0xfe --module unk_autoload_0 --version 2.0/sp1


int FUN_0232ce20(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,ushort param_5,
                undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined2 local_58 [2];
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined1 auStack_44 [28];
  undefined1 auStack_28 [16];
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  pvVar1 = FUN_0232c4d0();
  iVar3 = *(int *)((int)pvVar1 + 4);
  iVar2 = FUN_0232c520(2,7,8);
  if (iVar2 == 0) {
    FUN_023314cc(iVar3 + 0x188,2);
    FUN_023314cc(iVar3 + 0xc6,2);
    if ((*(short *)(iVar3 + 0x188) != 0) && (*(short *)(iVar3 + 0xc6) != 1)) {
      return 3;
    }
    FUN_023314cc(iVar3 + 0xc,4);
    if (*(int *)(iVar3 + 0xc) == 1) {
      return 3;
    }
    if ((param_3 & 0x3f) != 0) {
      return 6;
    }
    if ((param_5 & 0x1f) != 0) {
      return 6;
    }
    FUN_023314cc(iVar3 + 0x9c,2);
    if (*(short *)(iVar3 + 0x9c) == 0) {
      iVar2 = FUN_0232c998();
      if ((int)param_3 < iVar2) {
        return 6;
      }
      iVar2 = FUN_0232c954();
      if ((int)(uint)param_5 < iVar2) {
        return 6;
      }
    }
    FUN_0232c3bc(0xe,param_1);
    FUN_02337440(0,local_58,0x40);
    local_58[0] = 0xe;
    local_50 = param_3 >> 1;
    local_48 = (uint)param_5;
    local_54 = param_2;
    local_4c = param_4;
    FUN_02337440(0,auStack_44,0x1c);
    FUN_02337454(param_6,auStack_28,0x10);
    iVar2 = FUN_0232c484(local_58,0x40);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
  }
  return iVar2;
}

