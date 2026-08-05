// decomp: module=unk_autoload_0 addr=0x023274f8 name=FUN_023274f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e0 (Ghidra's cache says 0x1ce - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=85
// verify:  python tools/match.py --c <file> --func FUN_023274f8 --addr 0x023274f8 --size 0x1e0 --module unk_autoload_0 --version 2.0/sp1


void FUN_023274f8(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short local_2c [10];
  undefined2 local_18;
  
  iVar6 = DAT_023276cc;
  piVar3 = DAT_023276c8;
  iVar7 = 0;
  *DAT_023276c8 = 0;
  do {
    FUN_023292a8(iVar7);
    iVar1 = FUN_023292b8();
    if (iVar1 != 0) {
      FUN_02334628(iVar6 + *piVar3 * 0x94,iVar1,10);
      FUN_02334628(iVar6 + *piVar3 * 0x94 + 0x16,iVar1 + 0x14,0x1a);
      iVar4 = *piVar3;
      *(undefined2 *)(iVar6 + iVar4 * 0x94 + 0x4c) = *(undefined2 *)(iVar1 + 0x48);
      *piVar3 = iVar4 + 1;
    }
    iVar1 = DAT_023276cc;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  iVar6 = 0;
  iVar4 = *DAT_023276c8 * -0xe + 0xde;
  for (iVar7 = 0; iVar2 = DAT_023276cc, iVar7 < *DAT_023276c8; iVar7 = iVar7 + 1) {
    piVar3 = FUN_02321c68();
    iVar2 = FUN_0232dec8(piVar3,iVar1 + iVar7 * 0x94,1);
    iVar6 = iVar6 + iVar2 + 2;
  }
  if (iVar4 < iVar6) {
    local_18 = 0;
    iVar6 = FUN_02335e0c(0xde000);
    for (iVar7 = 0; iVar7 < *DAT_023276c8; iVar7 = iVar7 + 1) {
      iVar1 = iVar7 * 0x94;
      FUN_02334628(local_2c,DAT_023276cc + iVar1,10);
      while (local_2c[0] != 0) {
        piVar3 = FUN_02321c68();
        iVar4 = FUN_0232dec8(piVar3,local_2c,1);
        if (iVar4 < (iVar6 >> 0xc) + -0x10) break;
        iVar4 = FUN_023345fc(local_2c);
        local_2c[iVar4 + -1] = 0;
        iVar4 = FUN_023345fc(local_2c);
        if (iVar4 != 0) {
          iVar4 = FUN_023345fc(local_2c);
          local_2c[iVar4 + -1] = (short)DAT_023276d4;
        }
      }
      iVar4 = DAT_023276cc;
      if ((int)((uint)*(ushort *)(DAT_023276cc + iVar1 + 0x4c) * -0x80000000) < 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
      FUN_023216b4(DAT_023276cc + iVar1 + 0x50,DAT_023276d0,uVar5);
      FUN_023216e0(iVar4 + iVar1 + 0x50,local_2c);
      *(ushort *)(iVar4 + iVar1 + 0x66) = (*(ushort *)(iVar4 + iVar1 + 0x4c) >> 1) + 8;
      *(short *)(iVar4 + iVar1 + 0x90) = (short)(iVar7 * iVar6 + 0x800 >> 0xc);
    }
  }
  else {
    iVar4 = iVar4 - iVar6;
    for (iVar6 = 0; iVar6 < *DAT_023276c8; iVar6 = iVar6 + 1) {
      iVar7 = iVar6 * 0x94;
      if ((int)((uint)*(ushort *)(iVar2 + iVar7 + 0x4c) * -0x80000000) < 0) {
        uVar5 = 2;
      }
      else {
        uVar5 = 1;
      }
      FUN_023216b4(iVar2 + iVar7 + 0x50,DAT_023276d0,uVar5);
      FUN_023216e0(iVar2 + iVar7 + 0x50,iVar2 + iVar7);
      *(ushort *)(iVar2 + iVar7 + 0x66) = (*(ushort *)(iVar2 + iVar7 + 0x4c) >> 1) + 8;
      *(short *)(iVar2 + iVar7 + 0x90) = (short)iVar4;
      iVar4 = iVar4 + *(ushort *)(iVar2 + iVar7 + 0x5c) + 0x10;
    }
  }
  return;
}

