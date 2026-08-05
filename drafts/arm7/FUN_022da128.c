// decomp: module=arm7 addr=0x022da128 name=FUN_022da128
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xbc (Ghidra's cache says 0xb4 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022da128 --addr 0x022da128 --size 0xbc --module arm7 --version 2.0/sp1


void FUN_022da128(uint param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_022d9ffc();
  if ((iVar2 == 0x40) && (((uint)*(ushort *)(*DAT_022da1dc + 0x534) & 1 << (param_1 & 0xff)) == 0))
  {
    iVar2 = (uint)*(ushort *)(*DAT_022da1dc + 0x3d8) + DAT_022da1e0;
    uVar3 = func_0x037c9084(0x1000000);
    if (param_1 == 0) {
      bVar1 = FUN_022d8d6c(iVar2 + 4);
      FUN_022d8d40(iVar2 + 4,bVar1 | 1);
    }
    else {
      uVar4 = FUN_022da0e8(param_1);
      iVar2 = iVar2 + 5 + (uVar4 >> 3);
      uVar5 = FUN_022d8d6c(iVar2);
      FUN_022d8d40(iVar2,(uVar5 | 1 << (uVar4 & 7)) & 0xff);
    }
    func_0x037c904c(uVar3);
  }
  return;
}

