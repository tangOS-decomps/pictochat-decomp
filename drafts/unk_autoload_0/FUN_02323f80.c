// decomp: module=unk_autoload_0 addr=0x02323f80 name=FUN_02323f80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x174 (Ghidra's cache says 0x15a - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=79  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02323f80 --addr 0x02323f80 --size 0x174 --module unk_autoload_0 --version 2.0/sp1


void FUN_02323f80(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_4c;
  uint local_48;
  
  if ((param_4 < param_6) && (param_5 < param_7)) {
    for (iVar10 = param_5 >> 3; iVar10 < (param_7 + -1 >> 3) + 1; iVar10 = iVar10 + 1) {
      iVar2 = param_5 + iVar10 * -8;
      iVar3 = param_7 + iVar10 * -8;
      for (iVar1 = param_4 >> 3; iVar1 < (param_6 + -1 >> 3) + 1; iVar1 = iVar1 + 1) {
        local_48 = param_4 + iVar1 * -8;
        if ((int)local_48 < 0) {
          local_48 = 0;
        }
        iVar11 = iVar2;
        if (iVar2 < 0) {
          iVar11 = 0;
        }
        iVar9 = param_6 + iVar1 * -8;
        if (8 < iVar9) {
          iVar9 = 8;
        }
        local_4c = iVar3;
        if (8 < iVar3) {
          local_4c = 8;
        }
        iVar4 = param_1 + (iVar1 + iVar10 * (param_2 >> 3)) * 0x20;
        uVar7 = 0;
        for (uVar5 = 0; (int)uVar5 < (int)(iVar9 - local_48); uVar5 = uVar5 + 1) {
          uVar7 = uVar7 | param_3 << ((uVar5 & 0x3f) << 2);
        }
        uVar7 = uVar7 << ((local_48 & 0x3f) << 2);
        uVar5 = DAT_023240dc & uVar7;
        for (; iVar11 < local_4c; iVar11 = iVar11 + 1) {
          iVar9 = iVar11 * 4;
          uVar8 = *(uint *)(iVar4 + iVar9);
          uVar6 = uVar7;
          if ((uVar8 & 0xf0000000) == 0) {
            uVar6 = uVar5;
          }
          if ((uVar8 & 0xf000000) == 0) {
            uVar6 = uVar6 & DAT_023240e0;
          }
          if ((uVar8 & 0xf00000) == 0) {
            uVar6 = uVar6 & DAT_023240e4;
          }
          if ((uVar8 & 0xf0000) == 0) {
            uVar6 = uVar6 & DAT_023240e8;
          }
          if ((uVar8 & 0xf000) == 0) {
            uVar6 = uVar6 & DAT_023240ec;
          }
          if ((uVar8 & 0xf00) == 0) {
            uVar6 = uVar6 & DAT_023240f0;
          }
          if ((uVar8 & 0xf0) == 0) {
            uVar6 = uVar6 & 0xffffff0f;
          }
          if ((uVar8 & 0xf) == 0) {
            uVar6 = uVar6 & 0xfffffff0;
          }
          *(uint *)(iVar4 + iVar9) = *(int *)(iVar4 + iVar9) + uVar6;
        }
      }
    }
  }
  return;
}

