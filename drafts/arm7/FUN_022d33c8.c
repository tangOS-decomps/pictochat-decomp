// decomp: module=arm7 addr=0x022d33c8 name=FUN_022d33c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xbc (Ghidra's cache says 0xb8 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=40
// verify:  python tools/match.py --c <file> --func FUN_022d33c8 --addr 0x022d33c8 --size 0xbc --module arm7 --version 2.0/sp1


void FUN_022d33c8(void)

{
  short sVar1;
  undefined2 *puVar2;
  int iVar3;
  short *psVar4;
  undefined1 auStack_208 [512];
  
  psVar4 = *(short **)(DAT_022d3480 + 0x550);
  func_0x037cb520();
  if (*psVar4 == 0xb) {
    psVar4[8] = 0;
    psVar4[9] = 0;
    *psVar4 = 8;
    func_0x037cb534();
    iVar3 = FUN_022d03e8(auStack_208,7);
    sVar1 = *(short *)(iVar3 + 4);
    if (sVar1 == 0) {
      puVar2 = (undefined2 *)func_0x037d14bc();
      *puVar2 = 0x13;
      puVar2[1] = 0;
      func_0x037d1464();
    }
    else {
      puVar2 = (undefined2 *)func_0x037d14bc();
      *puVar2 = 0x13;
      puVar2[1] = 1;
      puVar2[2] = 0x104;
      puVar2[3] = sVar1;
      func_0x037d1464();
    }
  }
  else {
    func_0x037cb534();
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = 0x13;
    puVar2[1] = 3;
    func_0x037d1464();
  }
  return;
}

