// decomp: module=unk_autoload_0 addr=0x0232e324 name=FUN_0232e324
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x100 (Ghidra's cache says 0xee - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=49
// verify:  python tools/match.py --c <file> --func FUN_0232e324 --addr 0x0232e324 --size 0x100 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e324(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,short param_5)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int iStack_18;
  
  iStack_18 = param_4;
  FUN_0232e260(&local_20);
  local_24 = local_1c;
  local_28 = param_4 + param_3;
  local_1c = param_3 + -0x10;
  puVar2 = (undefined4 *)FUN_0232e27c(param_1,param_2);
  if ((uint)(local_1c - local_20) < 0x14) {
    local_1c = local_20;
  }
  else {
    puVar3 = (undefined4 *)FUN_0232e2b8(&local_20,DAT_0232e414);
    puVar2 = FUN_0232e298(param_1,puVar3,puVar2);
  }
  if ((uint)(local_24 - local_28) < 0x14) {
    local_28 = local_24;
  }
  else {
    puVar3 = (undefined4 *)FUN_0232e2b8(&local_28,DAT_0232e414);
    FUN_0232e298(param_1,puVar3,puVar2);
  }
  if ((param_1[-1] & 1) != 0) {
    FUN_02337440(0,local_1c,local_28 - local_1c);
  }
  local_2c = local_28;
  local_30 = param_3 + -0x10;
  puVar2 = (undefined4 *)FUN_0232e2b8(&local_30,DAT_0232e418);
  *(ushort *)((int)puVar2 + 2) = (ushort)DAT_0232e41c & *(ushort *)((int)puVar2 + 2);
  *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) | param_5 << 0xf;
  *(ushort *)((int)puVar2 + 2) = (ushort)DAT_0232e420 & *(ushort *)((int)puVar2 + 2);
  *(ushort *)((int)puVar2 + 2) =
       *(ushort *)((int)puVar2 + 2) | (ushort)(((int)puVar2 - local_1c & 0x7fU) << 8);
  uVar1 = *(ushort *)(param_1 + 4);
  *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) & 0xff00;
  *(ushort *)((int)puVar2 + 2) = *(ushort *)((int)puVar2 + 2) | uVar1 & 0xff;
  FUN_0232e298(param_1 + 2,puVar2,(undefined4 *)param_1[3]);
  return param_3;
}

