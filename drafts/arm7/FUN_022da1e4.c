// decomp: module=arm7 addr=0x022da1e4 name=FUN_022da1e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022da1e4 --addr 0x022da1e4 --size 0xac --module arm7 --version 2.0/sp1


void FUN_022da1e4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_022d9ffc();
  if (iVar1 == 0x40) {
    iVar1 = (uint)*(ushort *)(*DAT_022da288 + 0x3d8) + DAT_022da28c;
    uVar2 = func_0x037c9084(0x1000000);
    if (param_1 == 0) {
      uVar3 = FUN_022d8d6c(iVar1 + 4);
      FUN_022d8d40(iVar1 + 4,uVar3 & 0xfe);
    }
    else {
      uVar3 = FUN_022da0e8(param_1);
      iVar1 = iVar1 + 5 + (uVar3 >> 3);
      uVar4 = FUN_022d8d6c(iVar1);
      FUN_022d8d40(iVar1,~(1 << (uVar3 & 7)) & uVar4 & 0xff);
    }
    func_0x037c904c(uVar2);
  }
  return;
}

