// decomp: module=arm7 addr=0x022d99c4 name=FUN_022d99c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x140 (Ghidra's cache says 0x13c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=64
// verify:  python tools/match.py --c <file> --func FUN_022d99c4 --addr 0x022d99c4 --size 0x140 --module arm7 --version 2.0/sp1


uint FUN_022d99c4(ushort *param_1)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  piVar2 = DAT_022d9b00;
  iVar3 = *DAT_022d9b00;
  if ((*param_1 & 1) == 0) {
    uVar4 = 1;
    iVar7 = iVar3;
    if (1 < *(ushort *)(iVar3 + 0x52c)) {
      uVar9 = 0;
      uVar8 = 0;
      psVar1 = *(short **)(iVar3 + 0x31c);
      for (; uVar4 < *(ushort *)(iVar3 + 0x322); uVar4 = uVar4 + 1) {
        if (psVar1[0xe] == 0) {
          if (uVar9 == 0) {
            uVar9 = uVar4;
          }
        }
        else {
          iVar7 = FUN_022d84b0((undefined4 *)(psVar1 + 0x10),(undefined4 *)param_1);
          if (iVar7 != 0) {
            return uVar4;
          }
          iVar7 = *piVar2;
          uVar8 = uVar8 + 1;
          if (*(ushort *)(iVar7 + 0x52c) <= uVar8) break;
        }
        psVar1 = psVar1 + 0xe;
      }
      if (uVar9 != 0) {
        uVar4 = uVar9;
      }
    }
    if (*(ushort *)(iVar7 + 0x322) <= uVar4) {
      iVar7 = *(int *)(iVar3 + 0x31c);
      uVar9 = 0x10000;
      uVar4 = 0;
      for (uVar8 = 1; uVar8 < *(ushort *)(iVar3 + 0x322); uVar8 = uVar8 + 1) {
        iVar6 = iVar7 + uVar8 * 0x1c;
        if (((*(ushort *)(iVar7 + uVar8 * 0x1c) < 0x30) && (*(short *)(iVar6 + 0x16) == 0)) &&
           (uVar5 = (uint)*(ushort *)(iVar6 + 0x18), uVar5 < uVar9)) {
          uVar9 = uVar5;
          uVar4 = uVar8;
        }
      }
      if (uVar4 == 0) {
        return 0xff;
      }
    }
    FUN_022da5b4(uVar4,param_1);
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

