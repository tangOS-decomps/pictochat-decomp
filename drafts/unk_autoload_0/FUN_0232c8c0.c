// decomp: module=unk_autoload_0 addr=0x0232c8c0 name=FUN_0232c8c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=24 statements=51
// verify:  python tools/match.py --c <file> --func FUN_0232c8c0 --addr 0x0232c8c0 --size 0x94 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232c8c0(int param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined1 auStack_48 [6];
  undefined2 local_42;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  if (param_2 != (code *)0x0) {
    FUN_023374f0(&local_5c,0,0x44);
    local_5c = 0x82;
    local_5a = 0;
    local_58 = 0x19;
    local_56 = (undefined2)param_1;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_42 = (undefined2)DAT_0232c950;
    local_4a = 0;
    local_40 = param_3;
    FUN_02332188((int)auStack_48);
  }
  uVar1 = FUN_02332080();
  iVar2 = FUN_0232c4dc();
  if (iVar2 != 0) {
    FUN_02332094(uVar1);
    return iVar2;
  }
  pvVar3 = FUN_0232c4d0();
  *(code **)((int)pvVar3 + param_1 * 4 + 0xcc) = param_2;
  *(undefined4 *)((int)pvVar3 + param_1 * 4 + 0x10c) = param_3;
  if (param_2 != (code *)0x0) {
    local_3a = FUN_0232c85c();
    local_3c = FUN_0232c838();
    (*param_2)(&local_5c);
  }
  FUN_02332094(uVar1);
  return 0;
}

