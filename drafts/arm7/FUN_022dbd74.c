// decomp: module=arm7 addr=0x022dbd74 name=FUN_022dbd74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xec (Ghidra's cache says 0xe8 - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022dbd74 --addr 0x022dbd74 --size 0xec --module arm7 --version 2.0/sp1


undefined4 FUN_022dbd74(ushort *param_1,undefined2 param_2,int param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = func_0x037c58fc(*DAT_022dbe5c + 0x188,0x3a,param_3,DAT_022dbe5c,param_4);
  if (iVar2 == 0) {
    FUN_022d9088(1);
    uVar3 = 0;
  }
  else {
    *(undefined2 *)(iVar2 + 0xc) = 0x87;
    *(undefined2 *)(iVar2 + 0xe) = 0x15;
    FUN_022d811c((ushort *)(iVar2 + 0x10),param_1);
    *(undefined2 *)(iVar2 + 0x16) = param_2;
    uVar1 = FUN_022d8d6c(param_3 + 1);
    *(undefined2 *)(iVar2 + 0x18) = uVar1;
    for (uVar4 = 0; (uVar4 < *(ushort *)(iVar2 + 0x18) && (uVar4 < 0x20)); uVar4 = uVar4 + 1) {
      uVar3 = FUN_022d8d6c(param_3 + 2 + uVar4);
      FUN_022d8d40(iVar2 + 0x1a + uVar4,uVar3);
    }
    for (; uVar4 < 0x20; uVar4 = uVar4 + 1) {
      FUN_022d8d40(iVar2 + 0x1a + uVar4,0);
    }
    func_0x037c5de8(*DAT_022dbe5c + 0x188,iVar2);
    uVar3 = 1;
  }
  return uVar3;
}

