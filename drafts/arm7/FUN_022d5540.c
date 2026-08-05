// decomp: module=arm7 addr=0x022d5540 name=FUN_022d5540
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x330 (Ghidra's cache says 0x328 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=152
// verify:  python tools/match.py --c <file> --func FUN_022d5540 --addr 0x022d5540 --size 0x330 --module arm7 --version 2.0/sp1


undefined4 FUN_022d5540(int param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined2 uVar9;
  short sVar10;
  short sVar11;
  uint uVar12;
  ushort *puVar13;
  ushort *puVar14;
  short *psVar15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  uint local_58;
  undefined4 local_54;
  
  psVar15 = *(short **)(DAT_022d5868 + 0x550);
  local_54 = 0;
  if (*psVar15 == 9) {
    bVar18 = true;
  }
  else {
    if (*psVar15 != 10) {
      return 0;
    }
    bVar18 = false;
  }
  func_0x037ca044(psVar15 + 0x38e);
  if (*(int *)(psVar15 + 0x39a) == 0) {
    func_0x037ca0c8(psVar15 + 0x38e);
    local_54 = 0;
  }
  else {
    if (bVar18) {
      func_0x037cb520();
      uVar1 = psVar15[0xc1];
      func_0x037cb534();
    }
    else {
      uVar1 = 1;
    }
    iVar17 = 0;
    do {
      uVar6 = DAT_022d586c;
      uVar2 = psVar15[iVar17 * 2 + 0x37e];
      local_58 = DAT_022d586c;
      puVar13 = (ushort *)(psVar15 + iVar17 * 2 + 0x37e);
      uVar16 = DAT_022d586c;
      while (uVar7 = DAT_022d586c, uVar12 = (uint)uVar2, uVar12 != uVar6) {
        puVar14 = (ushort *)(psVar15 + uVar12 * 0x10 + 0x17c);
        if (param_1 == 0) {
          puVar14[4] = puVar14[4] | puVar14[5] & ~param_2;
          puVar14[3] = puVar14[3] & ~puVar14[4];
        }
        puVar14[3] = puVar14[3] & uVar1;
        puVar14[5] = 0;
        uVar5 = (ushort)uVar6;
        if (puVar14[3] == 0) {
LAB_022d5704:
          puVar8 = (undefined2 *)func_0x037d14bc();
          *puVar8 = 0x81;
          if (puVar14[3] == 0) {
            uVar9 = 0;
          }
          else {
            uVar9 = 0xf;
          }
          puVar8[1] = uVar9;
          puVar8[4] = 0x14;
          puVar8[5] = puVar14[1];
          puVar8[6] = puVar14[2];
          puVar8[7] = puVar14[3];
          puVar8[8] = puVar14[4];
          puVar8[0xc] = puVar14[7];
          *(undefined4 *)(puVar8 + 10) = *(undefined4 *)(puVar14 + 10);
          *(undefined4 *)(puVar8 + 0xe) = *(undefined4 *)(puVar14 + 0xc);
          *(undefined4 *)(puVar8 + 0x10) = *(undefined4 *)(puVar14 + 0xe);
          puVar8[0xd] = puVar14[8];
          sVar4 = psVar15[0x18];
          sVar10 = psVar15[0x19];
          sVar11 = sVar4;
          if (psVar15[0xc4] != 0) {
            sVar11 = sVar10;
          }
          puVar8[0x12] = sVar11;
          if (psVar15[0xc4] != 0) {
            sVar10 = sVar4;
          }
          puVar8[0x13] = sVar10;
          func_0x037d1464();
          if (*puVar14 == uVar6) {
            puVar13[1] = uVar5;
          }
          *puVar13 = *puVar14;
          *puVar14 = uVar5;
          if ((ushort)psVar15[0x37d] == uVar6) {
            psVar15[0x37c] = uVar2;
          }
          else {
            psVar15[(uint)(ushort)psVar15[0x37d] * 0x10 + 0x17c] = uVar2;
          }
          psVar15[0x37d] = uVar2;
          uVar12 = uVar16;
          uVar7 = local_58;
        }
        else {
          uVar3 = puVar14[1];
          bVar18 = (uVar3 & 8) == 0;
          if (bVar18) {
            uVar3 = puVar14[9];
          }
          if (bVar18 && uVar3 == 0) goto LAB_022d5704;
          local_54 = 1;
          if (puVar14[9] != 0) {
            puVar14[9] = puVar14[9] - 1;
          }
          if (*puVar14 == uVar6) {
            puVar13[1] = uVar5;
          }
          *puVar13 = *puVar14;
          *puVar14 = uVar5;
          uVar7 = uVar12;
          if (uVar16 != uVar6) {
            psVar15[uVar16 * 0x10 + 0x17c] = uVar2;
            uVar7 = local_58;
          }
        }
        local_58 = uVar7;
        uVar16 = uVar12;
        uVar2 = *puVar13;
      }
      if (uVar16 != DAT_022d586c) {
        psVar15[uVar16 * 0x10 + 0x17c] = psVar15[iVar17 * 2 + 0x386];
        if ((ushort)psVar15[iVar17 * 2 + 0x387] == uVar7) {
          psVar15[iVar17 * 2 + 0x387] = (short)uVar16;
        }
        psVar15[iVar17 * 2 + 0x386] = (short)local_58;
      }
      iVar17 = iVar17 + 1;
    } while (iVar17 < 4);
    psVar15[0x39a] = 0;
    psVar15[0x39b] = 0;
    func_0x037ca0c8(psVar15 + 0x38e);
  }
  return local_54;
}

