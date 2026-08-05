// decomp: module=arm7 addr=0x022d83e0 name=FUN_022d83e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd0 (Ghidra's cache says 0xcc - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=51
// verify:  python tools/match.py --c <file> --func FUN_022d83e0 --addr 0x022d83e0 --size 0xd0 --module arm7 --version 2.0/sp1


undefined4 FUN_022d83e0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  iVar1 = *DAT_022d84ac;
  if (param_1 < 0x21) {
    uVar6 = (uint)*(ushort *)(iVar1 + 0x362);
    if (uVar6 == 0) {
      uVar2 = 1;
    }
    else {
      if (*(short *)(iVar1 + 0x404) == 0x13) {
        if (param_1 < uVar6) {
          return 0;
        }
      }
      else {
        bVar9 = param_1 != uVar6;
        uVar6 = param_1;
        if (bVar9) {
          return 0;
        }
      }
      iVar7 = iVar1 + 0x364;
      iVar1 = iVar1 + 900;
      for (uVar8 = 0; uVar8 < uVar6; uVar8 = uVar8 + 1) {
        uVar3 = FUN_022d8d6c(iVar1);
        iVar1 = iVar1 + 1;
        uVar4 = FUN_022d8d6c(param_2);
        param_2 = param_2 + 1;
        uVar5 = FUN_022d8d6c(iVar7);
        iVar7 = iVar7 + 1;
        if ((uVar4 | uVar3) != (uVar5 | uVar3)) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

