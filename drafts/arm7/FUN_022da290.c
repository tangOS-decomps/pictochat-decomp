// decomp: module=arm7 addr=0x022da290 name=FUN_022da290
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1b8 (Ghidra's cache says 0x1b0 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=89
// verify:  python tools/match.py --c <file> --func FUN_022da290 --addr 0x022da290 --size 0x1b8 --module arm7 --version 2.0/sp1


void FUN_022da290(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 in_r3;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  
  piVar4 = DAT_022da440;
  uVar12 = 0;
  iVar9 = *DAT_022da440;
  uVar11 = 1;
  uVar1 = *(ushort *)(iVar9 + 0x52c);
  puVar3 = *(ushort **)(iVar9 + 0x31c);
  do {
    puVar10 = puVar3 + 0xe;
    if (*(ushort *)(iVar9 + 0x322) <= uVar11) {
      return;
    }
    if (*puVar10 == 0) {
LAB_022da41c:
      if (uVar1 <= uVar12) {
        return;
      }
    }
    else {
      uVar2 = puVar3[0x1a];
      uVar7 = (uint)uVar2;
      uVar5 = (uint)*puVar10;
      if (uVar7 != 0) {
        uVar5 = DAT_022da444;
      }
      if ((uVar7 == 0 || uVar7 == uVar5) || (puVar3[0x1a] = uVar2 - 1, puVar3[0x1a] != 0)) {
LAB_022da418:
        uVar12 = uVar12 + 1;
        goto LAB_022da41c;
      }
      if (*puVar10 < 0x20) {
LAB_022da404:
        *puVar10 = 0;
        *(short *)(iVar9 + 0x52c) = *(short *)(iVar9 + 0x52c) + -1;
        goto LAB_022da418;
      }
      uVar5 = FUN_022d9ffc(uVar11);
      FUN_022d9c60(uVar11 & 0xffff,0x20);
      FUN_022ded7c(uVar11);
      if (*(short *)(iVar9 + 0x350) != 1) {
        if (uVar11 == *(ushort *)(iVar9 + 0x3cc)) {
          puVar6 = (undefined2 *)FUN_022dfed8(puVar3 + 0x10,1,0);
          if (puVar6 != (undefined2 *)0x0) {
            *puVar6 = 1;
            FUN_022df098();
            uVar12 = uVar12 + 1;
            goto LAB_022da424;
          }
          func_0x037c62c0(0x20);
          FUN_022d8078();
          FUN_022dbc00(puVar3 + 0x10,1);
        }
        goto LAB_022da404;
      }
      if (uVar5 < 0x21) goto LAB_022da404;
      iVar8 = *piVar4;
      uVar5 = (uint)*(ushort *)(iVar8 + 0x534) | 1 << (uVar11 & 0xff);
      *(short *)(iVar8 + 0x534) = (short)uVar5;
      FUN_022d9d68(uVar11 & 0xffff,0,uVar5,iVar8 + 0x500,in_r3);
      iVar8 = *piVar4;
      *(ushort *)(iVar8 + 0x530) = *(ushort *)(iVar8 + 0x530) | (ushort)(1 << (uVar11 & 0xff));
      puVar6 = (undefined2 *)FUN_022dfed8(puVar3 + 0x10,1,0);
      if (puVar6 == (undefined2 *)0x0) {
        FUN_022dbc00(puVar3 + 0x10);
        goto LAB_022da404;
      }
      *puVar6 = 1;
      FUN_022df098();
      uVar12 = uVar12 + 1;
    }
LAB_022da424:
    uVar11 = uVar11 + 1;
    puVar3 = puVar10;
  } while( true );
}

