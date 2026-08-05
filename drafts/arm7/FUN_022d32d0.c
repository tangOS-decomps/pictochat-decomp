// decomp: module=arm7 addr=0x022d32d0 name=FUN_022d32d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf8 (Ghidra's cache says 0xf4 - it excludes this function's trailing literal pool), arm
// triage: noise=21 statements=41
// verify:  python tools/match.py --c <file> --func FUN_022d32d0 --addr 0x022d32d0 --size 0xf8 --module arm7 --version 2.0/sp1


void FUN_022d32d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 local_240 [3];
  undefined2 local_23a;
  undefined1 local_232;
  undefined1 auStack_228 [6];
  undefined1 auStack_222 [14];
  undefined4 local_214;
  undefined1 auStack_210 [512];
  undefined4 local_10;
  
  iVar2 = *(int *)(DAT_022d33c4 + 0x550);
  local_10 = param_4;
  func_0x037cb8b4(param_1 + 4,iVar2 + 0xa2,6);
  *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(param_1 + 0xc);
  *(short *)(iVar2 + 0xac) = (short)*(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(iVar2 + 0x18) = 1;
  func_0x037cb774(0,local_240,0x30);
  local_240[0] = 0;
  local_23a = (undefined2)*(undefined4 *)(param_1 + 0x10);
  if (*(short *)(iVar2 + 0x1ec) == 2) {
    local_232 = 0x14;
  }
  else {
    local_232 = 10;
  }
  func_0x037cb8b4(param_1 + 4,auStack_228,6);
  func_0x037cb8b4(iVar2 + 0xe0,auStack_222,6);
  local_214 = *(undefined4 *)(param_1 + 0xc);
  iVar2 = FUN_022d023c(auStack_210,local_240);
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x12;
  puVar1[1] = (ushort)(*(short *)(iVar2 + 4) != 0);
  if (*(short *)(iVar2 + 4) != 0) {
    puVar1[2] = 0x100;
    puVar1[3] = *(undefined2 *)(iVar2 + 4);
  }
  func_0x037d1464();
  return;
}

