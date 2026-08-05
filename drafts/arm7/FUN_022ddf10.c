// decomp: module=arm7 addr=0x022ddf10 name=FUN_022ddf10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x220 (Ghidra's cache says 0x214 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=80
// verify:  python tools/match.py --c <file> --func FUN_022ddf10 --addr 0x022ddf10 --size 0x220 --module arm7 --version 2.0/sp1


void FUN_022ddf10(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  
  iVar7 = *DAT_022de124;
  piVar13 = (int *)(param_1 * 0xc + iVar7 + 0x194);
  psVar10 = (short *)(param_1 * 0x14 + iVar7 + 0x42c);
  if ((short)piVar13[2] != 0) {
    uVar3 = func_0x037c9084(0x1000000);
    if (*psVar10 == 0) {
      iVar4 = *piVar13;
      while (iVar11 = iVar4, iVar11 != -1) {
        iVar4 = func_0x037c5b10(iVar11);
        iVar12 = iVar11 + 0x10;
        uVar1 = *(undefined2 *)(iVar11 + 0x12);
        iVar5 = FUN_022de298(iVar12);
        if (iVar5 == 0) {
          if ((param_1 != 0) && ((param_1 != 1 || (iVar5 = FUN_022d9ffc(uVar1), iVar5 != 0x40))))
          goto LAB_022de058;
          iVar5 = FUN_022da01c(uVar1);
          if (iVar5 != 0) {
            iVar5 = FUN_022d9ffc(uVar1);
            if (iVar5 == 0x40) {
LAB_022de058:
              *psVar10 = 1;
              psVar10[1] = psVar10[1] + 1;
              *(int *)(psVar10 + 6) = iVar12;
              uVar9 = *(uint *)(psVar10 + 4);
              if (*(short *)(iVar7 + 0x354) == 0) {
                FUN_022d7cf0(2);
              }
              FUN_022de130(uVar9,iVar11);
              if ((*(short *)(iVar7 + 0x350) == 1) && (uVar6 = FUN_022da108(uVar1), 1 < uVar6)) {
                *(ushort *)(uVar9 + 0xc) = *(ushort *)(uVar9 + 0xc) | 0x2000;
              }
              puVar8 = (ushort *)(DAT_022de12c + param_1 * 4);
              uVar2 = (ushort)((uVar9 & DAT_022de128) >> 1);
              if ((*(ushort *)(iVar11 + 0x24) & 0xc) == 4) {
                *puVar8 = uVar2 | 0xa000;
              }
              else if ((*(ushort *)(iVar11 + 0x24) & 0xfc) == 0x50) {
                *puVar8 = uVar2 | 0x9000;
              }
              else {
                *puVar8 = uVar2 | 0x8000;
              }
              func_0x037c904c(uVar3);
              return;
            }
            *(undefined2 *)(iVar11 + 0x18) = 2;
            FUN_022dded8(piVar13,iVar11);
            FUN_022d9bf0(iVar12);
          }
        }
        else {
          *(short *)(iVar7 + 0x4da) = *(short *)(iVar7 + 0x4da) + 1;
          *(undefined2 *)(iVar11 + 0x18) = 2;
          psVar10[2] = psVar10[2] + 1;
          (**(code **)(psVar10 + 8))(iVar12,0);
        }
      }
      func_0x037c904c(uVar3);
    }
    else {
      func_0x037c904c();
    }
  }
  return;
}

