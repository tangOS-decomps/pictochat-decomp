// decomp: module=unk_autoload_0 addr=0x023211b4 name=FUN_023211b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x108 (Ghidra's cache says 0xf6 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=86
// verify:  python tools/match.py --c <file> --func FUN_023211b4 --addr 0x023211b4 --size 0x108 --module unk_autoload_0 --version 2.0/sp1


void FUN_023211b4(void)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  undefined2 *puVar8;
  short *psVar9;
  short local_18 [4];
  undefined1 auStack_10 [8];
  
  piVar4 = DAT_023212b4;
  psVar7 = local_18;
  psVar9 = local_18;
  uVar5 = (uint)DAT_023212b0 >> 0xc &
          ((uint)(*DAT_023212ac | *DAT_023212b0) ^ (uint)DAT_023212b0 >> 0xc);
  uVar3 = (ushort)uVar5 & ~(ushort)((uVar5 & 0x40) << 1) & ~(ushort)((int)(uVar5 & 0x20) >> 1);
  uVar2 = uVar3 ^ *(ushort *)((int)DAT_023212b4 + 6);
  *(ushort *)(DAT_023212b4 + 1) = uVar3 & uVar2;
  *(ushort *)(piVar4 + 2) = ~uVar3 & uVar2;
  *(ushort *)((int)piVar4 + 6) = uVar3;
  if ((*(ushort *)((int)piVar4 + 10) & *(ushort *)((int)piVar4 + 6)) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar4 + 1;
  }
  *piVar4 = iVar6;
  if (DAT_023212b4[9] != 0) {
    do {
      FUN_02338d6c();
      iVar6 = FUN_02338dcc(auStack_10);
    } while (iVar6 != 0);
    FUN_02338f74(local_18,auStack_10);
    piVar4 = DAT_023212b4;
    if (local_18[3] != 0) {
      iVar6 = 4;
      puVar8 = DAT_023212b8;
      do {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        *psVar7 = uVar1;
        psVar7 = psVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      local_18[2] = 0;
    }
    if (local_18[2] == (short)DAT_023212b4[4]) {
      if (local_18[2] == 0) {
        DAT_023212b4[7] = 0;
      }
      else {
        DAT_023212b4[7] = 2;
        piVar4[6] = piVar4[6] + 1;
      }
    }
    else {
      if (local_18[2] == 0) {
        iVar6 = 3;
      }
      else {
        iVar6 = 1;
      }
      DAT_023212b4[7] = iVar6;
      piVar4[6] = 0;
    }
    piVar4 = DAT_023212b4;
    if (local_18[2] != 0) {
      *(short *)(DAT_023212b4 + 5) = local_18[0];
      *(short *)((int)piVar4 + 0x16) = local_18[1];
    }
    puVar8 = DAT_023212b8;
    *(short *)(DAT_023212b4 + 8) = local_18[2];
    iVar6 = 4;
    do {
      uVar1 = *psVar9;
      psVar9 = psVar9 + 1;
      *puVar8 = uVar1;
      puVar8 = puVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return;
}

