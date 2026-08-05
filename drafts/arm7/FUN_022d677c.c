// decomp: module=arm7 addr=0x022d677c name=FUN_022d677c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022d677c --addr 0x022d677c --size 0x78 --module arm7 --version 2.0/sp1


void FUN_022d677c(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined1 auStack_208 [512];
  
  iVar3 = FUN_022d0798(auStack_208,*(uint *)(param_1 + 4) & 0xffff);
  sVar1 = *(short *)(iVar3 + 4);
  if (sVar1 == 0) {
    puVar4 = (undefined2 *)func_0x037d14bc();
    *puVar4 = 0x24;
    puVar4[1] = 0;
    func_0x037d1464();
  }
  else {
    puVar4 = (undefined2 *)func_0x037d14bc();
    *puVar4 = 0x24;
    uVar2 = DAT_022d67f0;
    puVar4[1] = 1;
    puVar4[2] = (short)uVar2;
    puVar4[3] = sVar1;
    func_0x037d1464();
  }
  return;
}

