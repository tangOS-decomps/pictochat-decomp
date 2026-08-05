// decomp: module=unk_autoload_0 addr=0x0232e2d4 name=FUN_0232e2d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=18
// verify:  python tools/match.py --c <file> --func FUN_0232e2d4 --addr 0x0232e2d4 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e2d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_0232e1f4(param_1,DAT_0232e31c,param_1 + 0x38,param_2,param_3);
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  *(ushort *)(param_1 + 0x36) = *(ushort *)(param_1 + 0x36) & 0xfffe;
  local_14 = *(undefined4 *)(param_1 + 0x18);
  local_10 = *(undefined4 *)(param_1 + 0x1c);
  uVar1 = FUN_0232e2b8(&local_14,DAT_0232e320);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  return param_1;
}

