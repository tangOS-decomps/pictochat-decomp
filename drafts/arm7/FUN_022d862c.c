// decomp: module=arm7 addr=0x022d862c name=FUN_022d862c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022d862c --addr 0x022d862c --size 0x30 --module arm7 --version 2.0/sp1


undefined4 FUN_022d862c(ushort param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_022d8658;
  *DAT_022d8658 = param_2;
  puVar1[-1] = param_1 | 0x5000;
  iVar2 = func_0x037c849c();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

