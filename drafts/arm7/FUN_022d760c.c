// decomp: module=arm7 addr=0x022d760c name=FUN_022d760c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x110 (Ghidra's cache says 0x10c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=50
// verify:  python tools/match.py --c <file> --func FUN_022d760c --addr 0x022d760c --size 0x110 --module arm7 --version 2.0/sp1


undefined4 FUN_022d760c(uint param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  iVar6 = *DAT_022d7718;
  bVar3 = false;
  if (param_1 < 0x21) {
    sVar1 = *(short *)(iVar6 + 0x34c);
    bVar8 = sVar1 == 0x40;
    if (bVar8) {
      sVar1 = *(short *)(iVar6 + 0x32e);
    }
    if (bVar8 && sVar1 == 1) {
      if (*(ushort *)(iVar6 + 0x362) != param_1) {
        return 6;
      }
      if (*(short *)(iVar6 + 0x3d6) != 0) {
        bVar3 = true;
      }
    }
    for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
      uVar4 = FUN_022d8d6c(param_2);
      FUN_022d8d40(iVar6 + 0x364 + uVar7,uVar4);
      param_2 = param_2 + 1;
    }
    for (; uVar7 < 0x20; uVar7 = uVar7 + 1) {
      FUN_022d8d40(iVar6 + 0x364 + uVar7,0);
    }
    *(short *)(iVar6 + 0x362) = (short)param_1;
    if (bVar3) {
      uVar2 = *(ushort *)(iVar6 + 0x3d6);
      iVar5 = *(int *)(*DAT_022d7718 + 0x4ac);
      for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
        uVar4 = FUN_022d8d6c(iVar6 + 0x364 + uVar7);
        FUN_022d8d40(iVar5 + 0x26 + (uint)uVar2 + uVar7,uVar4);
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 5;
  }
  return uVar4;
}

