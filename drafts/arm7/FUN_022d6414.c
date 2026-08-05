// decomp: module=arm7 addr=0x022d6414 name=FUN_022d6414
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c, arm
// triage: noise=10 statements=16
// verify:  python tools/match.py --c <file> --func FUN_022d6414 --addr 0x022d6414 --size 0x5c --module arm7 --version 2.0/sp1


void FUN_022d6414(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined1 auStack_30 [28];
  undefined4 local_14;
  
  local_14 = param_4;
  uVar1 = FUN_022d6470(param_1 + 4,auStack_30);
  puVar2 = (undefined2 *)func_0x037d14bc();
  *puVar2 = 0x23;
  puVar2[1] = uVar1;
  *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(param_1 + 4);
  func_0x037cb8b4(auStack_30,puVar2 + 4,0x1c);
  func_0x037d1464(puVar2);
  return;
}

