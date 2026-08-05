// decomp: module=arm7 addr=0x022d40d8 name=FUN_022d40d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xa8 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022d40d8 --addr 0x022d40d8 --size 0xb0 --module arm7 --version 2.0/sp1


void FUN_022d40d8(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 in_r3;
  int iVar5;
  
  iVar1 = DAT_022d4184;
  iVar5 = *(int *)(DAT_022d4180 + 0x550);
  func_0x037cb520();
  if (*(short *)(iVar5 + 0xce) == 1) {
    func_0x037cb534();
  }
  else {
    *(undefined2 *)(iVar5 + 0xce) = 1;
    func_0x037cb534();
    puVar2 = FUN_022ce718();
    if (puVar2 == (undefined4 *)0x0) {
      iVar3 = 0;
    }
    else {
      *puVar2 = 0x1c;
      iVar3 = func_0x037c9e90(iVar1 + 0x88,puVar2,0,0x1c,in_r3);
    }
    if ((iVar3 == 0) && (*(undefined2 *)(iVar5 + 0xce) = 0, *(int *)(iVar1 + 0x154c) != 0)) {
      puVar4 = (undefined2 *)func_0x037d14bc();
      *puVar4 = 0x80;
      puVar4[1] = 8;
      puVar4[2] = 0x16;
      puVar4[3] = 0x1c;
      func_0x037d1464();
    }
  }
  return;
}

