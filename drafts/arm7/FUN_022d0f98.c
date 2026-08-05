// decomp: module=arm7 addr=0x022d0f98 name=FUN_022d0f98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xb8 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022d0f98 --addr 0x022d0f98 --size 0xc0 --module arm7 --version 2.0/sp1


void FUN_022d0f98(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined1 auStack_208 [512];
  
  iVar4 = *(int *)(DAT_022d1050 + 0x550);
  func_0x037cb8b4(*(undefined4 *)(param_1 + 4),iVar4 + 0xe8,0x40);
  if (((uint)*(ushort *)(iVar4 + 500) & 1 << (*(ushort *)(iVar4 + 0x11a) & 0xff)) == 0) {
    puVar3 = (undefined2 *)func_0x037d14bc();
    *puVar3 = 7;
    puVar3[1] = 6;
    func_0x037d1464();
  }
  else {
    iVar4 = FUN_022d0684(auStack_208,*(undefined2 *)(iVar4 + 0xf8));
    sVar1 = *(short *)(iVar4 + 4);
    if (sVar1 == 0) {
      puVar3 = (undefined2 *)func_0x037d14bc();
      *puVar3 = 7;
      puVar3[1] = 0;
      func_0x037d1464();
    }
    else {
      puVar3 = (undefined2 *)func_0x037d14bc();
      *puVar3 = 7;
      uVar2 = DAT_022d1054;
      puVar3[1] = 1;
      puVar3[2] = (short)uVar2;
      puVar3[3] = sVar1;
      func_0x037d1464();
    }
  }
  return;
}

